#include "render.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <unordered_map>
#include <vector>

namespace Render
{
    static SDL_Window * window_;
    static SDL_Renderer * renderer_;
    static std::vector<Graphics> gfx_;
    static std::vector<SDL_Texture *> textures_;
    static std::unordered_map<const char *, int> texture_map_;

    bool init( const char * title, int width, int height )
    {
        // Try to create window & abort if it fails.
        if ( ( window_ = SDL_CreateWindow( title, 0, 0, width, height, SDL_WINDOW_OPENGL ) ) == nullptr )
        {
            SDL_Log( "Could not create window: %s\n", SDL_GetError() );
            return false;
        }

        // Try to create renderer & abort if it fails.
        if ( ( renderer_ = SDL_CreateRenderer( window_, -1, SDL_RENDERER_ACCELERATED ) ) == nullptr )
        {
            SDL_Log( "Could not create renderer: %s\n", SDL_GetError() );
            return false;
        }

        return true;
    }

    void close()
    {
        for ( auto texture : textures_ )
        {
            SDL_DestroyTexture( texture );
        }
        SDL_DestroyRenderer( renderer_ );
        SDL_DestroyWindow( window_ );
    }

    void update()
    {
        SDL_SetRenderDrawColor( renderer_, 0, 0, 0, 255 );
        SDL_RenderClear( renderer_ );
        for ( Graphics & gfx : gfx_ )
        {
            switch ( gfx.type )
            {
                case ( GFXType::RECT ):
                {
                    SDL_Rect r = { ( int )( gfx.data.rect.rect.x ), ( int )( gfx.data.rect.rect.y ), ( int )( gfx.data.rect.rect.w ), ( int )( gfx.data.rect.rect.h ) };
                    SDL_SetRenderDrawColor
                    (
                        renderer_,
                        ( Uint8 )( gfx.data.rect.color.r ), ( Uint8 )( gfx.data.rect.color.g ), ( Uint8 )( gfx.data.rect.color.b ), ( Uint8 )( gfx.data.rect.color.a )
                    );
                    SDL_RenderFillRect( renderer_, &r );
                }
                break;

                case ( GFXType::SPRITE ):
                {
                    SDL_Rect src =
                    {
                        ( int )( gfx.data.sprite.src.x ),
                        ( int )( gfx.data.sprite.src.y ),
                        ( int )( gfx.data.sprite.src.w ),
                        ( int )( gfx.data.sprite.src.h )
                    };
                    SDL_Rect dest =
                    {
                        ( int )( gfx.data.sprite.dest.x ),
                        ( int )( gfx.data.sprite.dest.y ),
                        ( int )( gfx.data.sprite.dest.w ),
                        ( int )( gfx.data.sprite.dest.h )
                    };
                    SDL_RenderCopy( renderer_, textures_[ gfx.data.sprite.texture_id ], &src, &dest );
                }
                break;
            }
        }
        SDL_RenderPresent( renderer_ );
    };

    int addGraphics( Graphics gfx, Layer layer )
    {
        gfx_.push_back( gfx );
        return gfx_.size() - 1;
    };

    Graphics & getGraphics( int id )
    {
        return gfx_[ id ];
    };

    int getTextureId( const char * local )
    {
        auto seek = texture_map_.find( local );
        if ( seek != texture_map_.end() )
        {
            return seek->second;
        }
        else
        {
            std::string full = "assets/img/" + std::string( local );
            SDL_RWops * rwop = SDL_RWFromFile( full.c_str(), "rb" );
            if ( rwop == nullptr )
            {
                printf( "Failed to read file %s\n", full.c_str() );
                SDL_Log( "SDL_RWFromFile failed: %s", SDL_GetError() );
            }
            SDL_Surface * surface = IMG_LoadPNG_RW( rwop );
            SDL_RWclose( rwop );
            if ( surface == nullptr )
            {
                printf( "Failed to make surface for %s\n", full.c_str() );
                SDL_Log( "SDL_Surface failed: %s", SDL_GetError() );
            }
            SDL_Texture * texture = SDL_CreateTextureFromSurface( renderer_, surface );
            if ( texture == nullptr )
            {
                SDL_Log( "SDL_CreateTextureFromSurface failed: %s", SDL_GetError() );
            }
            SDL_FreeSurface( surface );
            textures_.push_back( texture );
            const int texture_id = textures_.size() - 1;
            texture_map_.insert( std::pair<const char *, int> ( local, texture_id ) );
            return texture_id;
        }
    };
}