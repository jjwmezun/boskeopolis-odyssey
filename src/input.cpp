#include "input.hpp"

namespace Input
{
    static constexpr int NUMBER_OF_ACTIONS = ( int )( Input::Action::__NULL );

    static bool held_[ NUMBER_OF_ACTIONS ];
    static bool pressed_[ NUMBER_OF_ACTIONS ];
    static bool locks_[ NUMBER_OF_ACTIONS ];

    void init()
    {
        for ( int i = 0; i < NUMBER_OF_ACTIONS; ++i )
        {
            pressed_[ i ] = locks_[ i ] = false;
        }
    };

    void update()
    {
        for ( int i = 0; i < NUMBER_OF_ACTIONS; ++i )
        {
            pressed_[ i ] = false;
        }
    };

    void registerKeyPress( Action action )
    {
        const int i = ( int )( action );
        held_[ i ] = true;
        if ( !locks_[ i ] )
        {
            pressed_[ i ] = locks_[ i ] = true;
        }
    };

    void registerKeyRelease( Action action )
    {
        const int i = ( int )( action );
        pressed_[ i ] = locks_[ i ] = held_[ i ] = false;
    };

    bool pressedConfirm()
    {
        return pressed_[ ( int )( Input::Action::CONFIRM ) ];
    };

    bool heldUp()
    {
        return held_[ ( int )( Input::Action::UP ) ];
    };

    bool heldRight()
    {
        return held_[ ( int )( Input::Action::RIGHT ) ];
    };

    bool heldDown()
    {
        return held_[ ( int )( Input::Action::DOWN ) ];
    };

    bool heldLeft()
    {
        return held_[ ( int )( Input::Action::LEFT ) ];
    };
}