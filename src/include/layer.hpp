#ifndef LAYER_H
#define LAYER_H

#include <algorithm>

enum class Layer
{
    BEFORE_BG_1 = 0,
    BG_1,
    BEFORE_BG_2,
    BG_2,
    BEFORE_BLOCKS_1,
    BLOCKS_1,
    BEFORE_SPRITES_1,
    SPRITES_1,
    BEFORE_BLOCKS_2,
    BLOCKS_2,
    BEFORE_SPRITES_2,
    SPRITES_2,
    BEFORE_FG_1,
    FG_1,
    BEFORE_FG_2,
    FG_2,
    AFTER_FG_2,
    SUPER
};

static constexpr int NUMBER_OF_LAYERS = ( int )( Layer::SUPER ) + 1;

inline constexpr Layer IntToLayer( int value )
{
    return ( Layer )( std::max( 0, std::min( NUMBER_OF_LAYERS, value ) ) );
};

#endif // LAYER_H