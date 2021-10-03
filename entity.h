#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED
#include "sdl.h"


typedef struct
{
    SDL_Surface *sprite[10] ;
    SDL_Rect position;
} entity;
entity init_entity(int x,int y);

#endif