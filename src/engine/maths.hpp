#pragma once

struct Vector2
{
    float x;
    float y;
};

struct Rectangle
{
    float x;
    float y;
    float w;
    float h;

    SDL_Rect *toSDL()
    {
        SDL_Rect *rect = new SDL_Rect;
        rect->x = x; rect->y = y; rect->w = w; rect->h = h;
        return rect;
    }
};