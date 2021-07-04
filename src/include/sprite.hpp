#ifndef SPRITE_H
#define SPRITE_H

#include "rect.hpp"
#include <unordered_map>
#include <variant>

enum class SpriteType
{
    __NULL,
    HERO
};

struct Sprite
{
    SpriteType type;
    Rect position;
    std::unordered_map<const char *, std::variant<int, float>> data;
};

Sprite createHeroSprite();
void updateSprite( Sprite & sprite );

#endif // SPRITE_H