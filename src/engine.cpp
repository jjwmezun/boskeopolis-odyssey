#include <cstdio>
#include "engine.hpp"
#include "input.hpp"
#include <SDL2/SDL.h>
#include <unordered_map>

namespace Engine
{
    static std::unordered_map<SDL_Keycode, Input::Action> actions_ =
    {
        { SDLK_z, Input::Action::CONFIRM },
        { SDLK_x, Input::Action::CANCEL },
        { SDLK_UP, Input::Action::UP },
        { SDLK_RIGHT, Input::Action::RIGHT },
        { SDLK_DOWN, Input::Action::DOWN },
        { SDLK_LEFT, Input::Action::LEFT }
    };

    bool init()
    {
        if ( SDL_Init( SDL_INIT_VIDEO ) != 0 )
        {
            SDL_Log( "Unable to initialize SDL: %s", SDL_GetError() );
            return false;
        }
        return true;
    };

    void close()
    {
        SDL_Quit();
    }

    int getTicks()
    {
        return SDL_GetTicks();
    };

    bool handleEvents()
    {
        SDL_Event event;
        if ( SDL_PollEvent( &event ) )
        {
            switch ( event.type )
            {
                case ( SDL_QUIT ):
                {
                    return false;
                }
                break;
                case ( SDL_KEYDOWN ):
                {
                    const auto & seek = actions_.find( event.key.keysym.sym );
                    if ( seek != actions_.end() )
                    {
                        Input::registerKeyPress( seek->second );
                    }
                }
                break;
                case ( SDL_KEYUP ):
                    const auto & seek = actions_.find( event.key.keysym.sym );
                    if ( seek != actions_.end() )
                    {
                        Input::registerKeyRelease( seek->second );
                    }
                break;
            }
        }
        return true;
    };
};