#include "engine.hpp"
#include <iostream>

Engine::Engine()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("kEngine",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1366, 768, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    running = true;
    cache = new Cache(renderer);
}

void Engine::run()
{
    SDL_Event event;

    load();

    while (running)
    {
        SDL_PollEvent(&event);
        switch (event.type)
        {
            case SDL_QUIT:
                running = false;
                break;
        }

        update();

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        draw();

        SDL_RenderPresent(renderer);
    }
}

Engine::~Engine()
{
    delete cache;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Engine::addSprite(Sprite *spr)
{
    scenegraph.push_back(spr);
}

void Engine::removeSprite(Sprite *spr)
{
    scenegraph.remove(spr);
}

void Engine::draw()
{
    for (const auto &spr : scenegraph)
        SDL_RenderCopy(renderer, spr->texture, NULL, spr->getBoundingBox().toSDL());
}
