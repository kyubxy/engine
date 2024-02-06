#pragma once

#include <map>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

class Cache
{
public:
    Cache(SDL_Renderer *r);
    ~Cache();
    SDL_Texture *getTexture(string path);

private:
    map<string, SDL_Texture *> cache;
    SDL_Renderer *r;

    SDL_Texture *loadTexture(string path);
};
