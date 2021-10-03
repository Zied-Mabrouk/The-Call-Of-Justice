/**
@file Enigme.h
@brief code de l'enigme nbr 3
@date 05/06/2020
@author Jasser 

*/
#ifndef ENIGME_H_INCLUDED
#define  ENIGME_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include <SDL/SDL_mixer.h>

typedef struct objett
{
	SDL_Rect cords,cordsTex,cordsTick,cordsgreen,cordspic;
	SDL_Surface *imageTick,*textObj,*photo;
	char name[10];
	int clicked;
	
}objett;
typedef struct photoo
{
    SDL_Surface *pic;
    SDL_Rect cordspic;
    
}photoo;

typedef struct eenigmes
{
    SDL_Surface *background;
    SDL_Rect positionTrials,positionFond;
    objett obj[10];
    photoo ph[6];
    int n,trials,objLeft,right;
    Mix_Chunk *backgroundMus,*rightEffect,*wrongEffect,*stampEffect,*houseAlarm;

}eenigmes;

typedef struct pic
{
    SDL_Surface *images;
    SDL_Rect pos;
    
}pic;


 
 SDL_Surface *ecran;
 SDL_Event event;
Mix_Music *music;


void initSDL();
eenigmes initialiserEnigmee(char bg[]);
void afficherEnigmee(eenigmes *E);
void enigmeInputt(eenigmes *E,int *continu);
void checkk(eenigmes *E,int i);
int EndingCheckk(eenigmes *E);
void aff_PIC(eenigmes *E);

pic init_photoo(char images[]); 
void aff_photoo(pic p,int x,int y);
void sounn(eenigmes *E);
void eenigme_ja();
#endif
