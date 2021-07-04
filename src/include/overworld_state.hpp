#ifndef OVERWORLD_STATE_H
#define OVERWORLD_STATE_H

#include "game_state.hpp"
#include "sprite.hpp"

class OverworldState : public GameState
{
    public:
        void init() override;
        void update() override;

    private:
        Sprite hero;
};

#endif // OVERWORLD_STATE_H