#ifndef TITLE_STATE_H
#define TITLE_STATE_H

#include "game_state.hpp"

class TitleState : public GameState
{
    public:
        void init() override;
        void update() override;
};

#endif // TITLE_STATE_H