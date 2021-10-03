#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>



typedef struct
{
	SDL_Rect positionFond;
	SDL_Surface *background;
}backgroundd;

typedef struct 
{
	SDL_Rect cords,cordsText;
	SDL_Surface *imageTick,*textObj;
	int clicked;
	char name[10];
	
}objet;

typedef struct 
{
	SDL_Surface *background, *win, *lose;
	SDL_Rect positionFond,positionTrials;
	objet obj[10];
	int n,trials,objLeft,wrong;
	Mix_Chunk *backgroundMus,*rightEffect,*wrongEffect,*stampEffect,*houseAlarm;
	
}enigme;

SDL_Surface *ecran;
void initSDL();
backgroundd init(char name[]);
void afficher(backgroundd *b);
enigme initialiserEnigme(char bg[],char win[],char lose[]);
void afficherEnigme(enigme *E);
void enigmeInput(enigme *E,int *continu);
int EndingCheck(enigme *E);
int ending(enigme *E,int end);
void animationEnigme(enigme *E,int end,int old);
int jEnigme();

#endif
