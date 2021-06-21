#include <cstdio>
#include "game_state_machine.hpp"
#include "overworld_state.hpp"
#include "input.hpp"
#include "title_state.hpp"

void OverworldState::init()
{

};

void OverworldState::update()
{
    printf( "We’re in the o’erworld.\n" );
    if ( Input::pressedConfirm() )
    {
        GameStateMachine::changeState( new TitleState() );
    }
};