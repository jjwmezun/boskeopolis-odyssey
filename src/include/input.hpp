#ifndef INPUT_H
#define INPUT_H

namespace Input
{
    enum class Action
    {
        CONFIRM,
        CANCEL,
        UP,
        RIGHT,
        DOWN,
        LEFT,
        __NULL
    };

    void init();
    void update();

    void registerKeyPress( Action action );
    void registerKeyRelease( Action action );

    bool pressedConfirm();
    bool heldUp();
    bool heldRight();
    bool heldDown();
    bool heldLeft();
}

#endif // INPUT_H