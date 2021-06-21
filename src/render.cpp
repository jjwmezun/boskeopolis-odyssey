#include "render.hpp"
#include <SDL2/SDL.h>

namespace Render
{
    static SDL_Window * window_;
    static SDL_Renderer * renderer_;

    bool init( const char * title )
    {
        // Try to create window & abort if it fails.
        if ( ( window_ = SDL_CreateWindow( title, 0, 0, 1600, 900, SDL_WINDOW_OPENGL ) ) == nullptr )
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
        SDL_DestroyRenderer( renderer_ );
        SDL_DestroyWindow( window_ );
    }

    void update()
    {
        SDL_SetRenderDrawColor( renderer_, 0, 0, 0, 255 );
        SDL_RenderClear( renderer_ );
        SDL_RenderPresent( renderer_ );
    };
}