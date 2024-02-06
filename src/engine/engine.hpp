#pragma once

#include <list>
#include "SDL2/SDL.h"
#include "sprite.hpp"
#include "cache.hpp"

class Engine
{
public:
    Engine();
    ~Engine();
    void run();

    void addSprite(Sprite *spr);
    void removeSprite(Sprite *spr);

protected:
    Cache *cache;
    virtual void load() {};
    virtual void update(){};

private:
    bool running;
    std::list<Sprite*> scenegraph;

    SDL_Renderer *renderer;
    SDL_Window *window;

    void draw();
};