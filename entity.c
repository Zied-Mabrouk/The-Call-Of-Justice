#include "entity.h"
#include "hero.h"
entity init_entity(int x, int y)
{
    entity e;
    e.position.x = x;
    e.position.y = y;
    return e;
}

