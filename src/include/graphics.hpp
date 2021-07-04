#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "color.hpp"
#include "rect.hpp"

enum class GFXType
{
    __NULL,
    RECT,
    SPRITE
};

struct RectGraphics
{
    Rect rect;
    Color color;
};

struct SpriteGraphics
{
    int texture_id;
    Rect src;
    Rect dest;
};

struct Graphics
{
    GFXType type;
    union
    {
        RectGraphics rect;
        SpriteGraphics sprite;
    } data;
};

namespace GFX
{
    Graphics createFullRect( Color color );
    Graphics createSprite
    (
        int texture_id,
        Rect position
    );
}

#endif // GRAPHICS_H