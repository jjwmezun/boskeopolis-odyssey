#include "graphics.hpp"
#include "unit.hpp"

namespace GFX
{
    Graphics createFullRect( Color color )
    {
        Graphics g;
        g.type = GFXType::RECT;
        g.data.rect =
        {
            { 0.0f, 0.0f, ( float )( Unit::WINDOW_WIDTH_PIXELS ), ( float )( Unit::WINDOW_HEIGHT_PIXELS ) },
            color
        };
        return g;
    };

    Graphics createSprite
    (
        int texture_id,
        Rect position
    )
    {
        Graphics g;
        g.type = GFXType::SPRITE;
        g.data.sprite.texture_id = texture_id;
        g.data.sprite.src.w = g.data.sprite.dest.w = position.w;
        g.data.sprite.src.h = g.data.sprite.dest.h = position.h;
        g.data.sprite.src.x = 0.0f;
        g.data.sprite.src.y = 0.0f;
        g.data.sprite.dest.x = position.x;
        g.data.sprite.dest.y = position.y;
        return g;
    };
}