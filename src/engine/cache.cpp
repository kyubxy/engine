#include "cache.hpp"
#include <iostream>

Cache::Cache(SDL_Renderer *r)
{
    this->r = r;
}

Cache::~Cache()
{
    // clear cache
    for(const auto &[key, tex] : cache)
    {
        SDL_DestroyTexture(tex);
        cache[key] = NULL;
    }
}

SDL_Texture *Cache::getTexture(string path)
{
    // check cache first
    if (cache.find(path) != cache.end())
        return cache[path]; // cache hit

    // cache miss, load from disk and cache before returning
    auto *tex = loadTexture(path);
    cache[path] = tex;
    return tex;
}

SDL_Texture *Cache::loadTexture(string path)
{
    SDL_Texture *tex = NULL;
    SDL_Surface *surf = IMG_Load(path.c_str());

    if (surf == NULL)
    {
        cout << IMG_GetError() << endl;
        return NULL;
    }

    tex = SDL_CreateTextureFromSurface(r, surf);

    if (tex == NULL)
    {
        cout << SDL_GetError() << endl;
        return NULL;
    }

    SDL_FreeSurface(surf);
    return tex;
}

