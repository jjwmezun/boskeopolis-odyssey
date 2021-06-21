#include <cstdio>
#include <cstdlib>
#include "engine.hpp"
#include "game_state_machine.hpp"
#include "input.hpp"
#include "render.hpp"

static constexpr int DT = 17;

static bool running = true;
static int ticks = 0;
static int accumulator = 0;

int main( int argc, char * * argv )
{
    if ( !Engine::init() || !Render::init( "Boskeopolis Odyssey" ) )
    {
        printf( "¡Error! Failed to initialize game!\n" );
        return -1;
    }

    Input::init();
    GameStateMachine::init();

    ticks = Engine::getTicks();
    while ( running )
    {
        running = Engine::handleEvents();
        int new_time = Engine::getTicks();
        int frame_time = new_time - ticks;
        ticks = new_time;
        accumulator += frame_time;
        while ( accumulator >= DT )
        {
            GameStateMachine::update();
            Input::update();
            accumulator -= DT;
        }

        Render::update();
    }

    Render::close();
    Engine::close();
    return 0;
}