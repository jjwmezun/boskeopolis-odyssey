#ifndef OVERWORLD_STATE_H
#define OVERWORLD_STATE_H

#include "game_state.hpp"

class OverworldState : public GameState
{
    public:
        void init() override;
        void update() override;
};

#endif // OVERWORLD_STATE_H