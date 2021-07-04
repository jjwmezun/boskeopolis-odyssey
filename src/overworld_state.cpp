#include <cstdio>
#include "game_state_machine.hpp"
#include "graphics.hpp"
#include "overworld_state.hpp"
#include "input.hpp"
#include "layer.hpp"
#include "render.hpp"
#include "title_state.hpp"

void OverworldState::init()
{
    Render::addGraphics( GFX::createFullRect({ 255.0f, 255.0f, 255.0f, 255.0f }), Layer::BG_1 );
    hero = createHeroSprite();
};

void OverworldState::update()
{
    updateSprite( hero );
    if ( Input::pressedConfirm() )
    {
        GameStateMachine::changeState( new TitleState() );
    }
};