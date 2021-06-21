#include "input.hpp"

namespace Input
{
    static constexpr int NUMBER_OF_ACTIONS = ( int )( Input::Action::__NULL );

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
        if ( !locks_[ i ] )
        {
            pressed_[ i ] = locks_[ i ] = true;
        }
    };

    void registerKeyRelease( Action action )
    {
        const int i = ( int )( action );
        pressed_[ i ] = locks_[ i ] = false;
    };

    bool pressedConfirm()
    {
        return pressed_[ ( int )( Input::Action::CONFIRM ) ];
    };
}