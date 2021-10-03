#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED
#include "entity.h"
#include "header.h"

#define JumpLimit 180
#define Hero_Default_Y 340
#define Gravity -5

typedef struct 
{
	int  up,left, right;
}Mouvement;
typedef struct
{
    entity e;
    Mouvement mouvement;
    int frame, air, sol;
    char direction;
    int mouse_clicked, target, vitesse;
} Hero;

typedef struct
{
  
	SDL_Surface *fontdot;
	SDL_Rect positiondot; 
}dot;
dot herodot;

SDL_Surface *masque;
int intervalleH1,intervalleH2,intervalleE1,intervalleE2,destination,continuer,position_absolue;

dot init_dot(char reddot[]);
void aff_dot(dot herodot);
void Deplacer_dot(dot *herodot,Hero *hero);
void init_hero(Hero *hero);
void aff_hero(Hero *hero);
void getInput(SDL_Event event, int *continuer,Background *background,Hero *hero,int *save);
void free_hero(Hero *hero);
void doKeyUp(SDL_Event event,Hero *hero,int *save);
void doKeyDown(SDL_Event event,Hero *hero);
void mouvement_mouse(Hero *hero);
void mouvement(SDL_Event event,Background *background,Hero *hero);
SDL_Color GetPixel(int X, int Y);
int CollisionParfaite (Hero hero);
void saveGame(Hero player, char filename[50],int save);
void LoadGame(Hero *player, char filename[50],int save);
#endif
