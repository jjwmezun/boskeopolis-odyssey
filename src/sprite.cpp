#include "input.hpp"
#include "render.hpp"
#include "sprite.hpp"

Sprite createHeroSprite()
{
    Sprite hero;
    hero.type = SpriteType::HERO;
    hero.position = { 64.0f, 48.0f, 128.0f, 235.0f };
    hero.data.insert
    (
        std::pair<const char *, std::variant<int, float>>
        (
            "gfx",
            Render::addGraphics
            (
                GFX::createSprite
                (
                    Render::getTextureId( "sprites/map-autumn.png" ),
                    hero.position
                ),
                Layer::BG_1
            )
        )
    );
    hero.data[ "accx" ] = 0.0f;
    hero.data[ "accy" ] = 0.0f;
    hero.data[ "vx" ] = 0.0f;
    hero.data[ "vy" ] = 0.0f;
    hero.data[ "max_speed" ] = 4.0f;
    hero.data[ "start_speed" ] = 0.5f;
    hero.data[ "walk_animation_timer" ] = 0;
    hero.data[ "walk_animation_frame" ] = 0;
    return hero;
};

void updateSprite( Sprite & sprite )
{
    switch ( sprite.type )
    {
        case ( SpriteType::HERO ):
        {
            float accy;
            float accx;
            float vy = std::get<float>( sprite.data[ "vy" ] );
            float vx = std::get<float>( sprite.data[ "vx" ] );
            float max_speed = std::get<float> ( sprite.data[ "max_speed" ] );
            float start_speed = std::get<float> ( sprite.data[ "max_speed" ] );

            if ( Input::heldDown() )
            {
                accy = start_speed;
            }
            else if ( Input::heldUp() )
            {
                accy = -start_speed;
            }
            else
            {
                accy = 0.0f;
                vy /= 1.15f;
            }

            vy += accy;

            if ( vy > max_speed )
            {
                vy = max_speed;
            }
            else if ( vy < -max_speed )
            {
                vy = -max_speed;
            }

            if ( Input::heldRight() )
            {
                accx = start_speed;
            }
            else if ( Input::heldLeft() )
            {
                accx = -start_speed;
            }
            else
            {
                accx = 0.0f;
                vx /= 1.15f;
            }

            vx += accx;

            if ( vx > max_speed )
            {
                vx = max_speed;
            }
            else if ( vx < -max_speed )
            {
                vx = -max_speed;
            }

            sprite.position.y += vy;
            sprite.position.x += vx;

            SpriteGraphics & gfx = Render::getGraphics( std::get<int>( sprite.data[ "gfx" ] ) ).data.sprite;
            gfx.dest = sprite.position;

            sprite.data[ "accy" ] = accy;
            sprite.data[ "vy" ] = vy;
            sprite.data[ "accx" ] = accx;
            sprite.data[ "vx" ] = vx;


            if ( accy != 0.0f || accx != 0.0f )
            {
                int walk_animation_timer = std::get<int>( sprite.data[ "walk_animation_timer" ] );
                if ( walk_animation_timer == 7 )
                {
                    walk_animation_timer = 0;
                    int walk_animation_frame = std::get<int>( sprite.data[ "walk_animation_frame" ] );
                    if ( walk_animation_frame == 4 )
                    {
                        walk_animation_frame = 0;
                    }
                    else
                    {
                        ++walk_animation_frame;
                    }
                    gfx.src.x = ( walk_animation_frame == 1 ) ? 128.0f : ( ( walk_animation_frame == 3 ) ? 256.0f : 0.0f );
                    sprite.data[ "walk_animation_frame" ] = walk_animation_frame;
                }
                else
                {
                    ++walk_animation_timer;
                }
                sprite.data[ "walk_animation_timer" ] = walk_animation_timer;
            }
            else
            {
                gfx.src.x = 0.0f;
            }
        }
        break;
    }
};