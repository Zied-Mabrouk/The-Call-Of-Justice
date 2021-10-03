#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include "sdl.h"

typedef struct
{
    SDL_Surface *imageDeFond ;
    SDL_Rect positionFond;

} Background;

Background background;

typedef struct 
{
	SDL_Surface *map;
	SDL_Rect positionMap;
}minimap;

minimap Map;
int loading();
int MenuController();
int MenuLoad(int *save);
int MenuMultiplayer();
int Game(int *save);
int MenuOp();
int MenuP();
Background init_back(char background_name[]);
void init_SDL();
void aff_back(Background background);
int level1();
int level2();
void aff_map(minimap Map);
minimap init_map (char map_name[]);
#endif // HEADER_H_INCLUDED
