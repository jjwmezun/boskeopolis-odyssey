#ifndef GAME_STATE_H
#define GAME_STATE_H

class GameState
{
    public:
        virtual void init() = 0;
        virtual void update() = 0;
        virtual void close();
};

#endif // GAME_STATE_H