#ifndef INPUT_H
#define INPUT_H

namespace Input
{
    enum class Action
    {
        CONFIRM,
        __NULL
    };

    void init();
    void update();

    void registerKeyPress( Action action );
    void registerKeyRelease( Action action );

    bool pressedConfirm();
}

#endif // INPUT_H