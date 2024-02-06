#include "engine/engine.hpp"

class Test : public Engine
{
private:
    Sprite *spr;

protected: 
    void load()
    {
        spr = new Sprite();
        spr->position = Vector2 { 100, 100 };
        spr->size = Vector2 { 200, 200 };
        spr->texture = cache->getTexture("test.png");
        addSprite(spr);
    }

    void update()
    {
        spr->position.x += 0.01f;
    }
};

int main()
{
    Engine *engine = new Test();
    engine->run();
    delete engine;

    return 0;
}