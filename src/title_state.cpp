#include <cstdio>
#include "game_state_machine.hpp"
#include "input.hpp"
#include "overworld_state.hpp"
#include "title_state.hpp"

void TitleState::init()
{

};

void TitleState::update()
{
    if ( Input::pressedConfirm() )
    {
        GameStateMachine::changeState( new OverworldState() );
    }
};