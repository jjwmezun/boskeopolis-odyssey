#include "game_state.hpp"
#include "game_state_machine.hpp"
#include <memory>
#include "title_state.hpp"
#include <vector>

namespace GameStateMachine
{
    static std::vector<std::unique_ptr<GameState>> states_;
    static std::vector<std::unique_ptr<GameState>> push_states_;
    static GameState * change_state_ = nullptr;
    static int pop_states_ = 0;

    void init()
    {
        states_.emplace_back( new TitleState() );
        states_.back()->init();
    };

    void update()
    {
        for ( auto & state : states_ )
        {
            state->update();
        }

        if ( change_state_ != nullptr )
        {
            for ( auto & state : states_ )
            {
                state->close();
            }
            states_.clear();
            states_.emplace_back( change_state_ );
            states_.back()->init();
            change_state_ = nullptr;
        }
    };

    void changeState( GameState * state )
    {
        change_state_ = state;
    };
}