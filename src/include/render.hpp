#ifndef RENDER_H
#define RENDER_H

#include "graphics.hpp"
#include "layer.hpp"

namespace Render
{
    bool init( const char * title, int width, int height );
    void close();
    void update();
    int addGraphics( Graphics gfx, Layer layer );
    Graphics & getGraphics( int id );
    int getTextureId( const char * local );
}

#endif // RENDER_H