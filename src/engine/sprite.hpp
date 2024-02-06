#pragma once

#include <SDL2/SDL.h>
#include "maths.hpp"

struct Sprite
{
    Vector2 position;
    Vector2 size;
    SDL_Texture *texture = NULL;

    Rectangle getBoundingBox()
    {
        Rectangle rect { position.x, position.y, size.x, size.y };
        return rect;
    }
};
