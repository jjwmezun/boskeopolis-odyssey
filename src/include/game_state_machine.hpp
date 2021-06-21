#ifndef GAME_STATE_MACHINE_H
#define GAME_STATE_MACHINE_H

class GameState;

namespace GameStateMachine
{
    void init();
    void update();
    void changeState( GameState * state );
}

#endif // GAME_STATE_MACHINE_H