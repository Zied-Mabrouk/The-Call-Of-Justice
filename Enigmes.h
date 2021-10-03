#ifndef ENIGMES_H_INCLUDED
#define  ENIGMES_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include <SDL/SDL_mixer.h>

typedef struct enigmes
{
    SDL_Surface *image;
    SDL_Rect positionE;
    char corr;

}enigmes;

typedef struct photo
{
    SDL_Surface *images;
    SDL_Rect position;
    
}photo;
 
 SDL_Surface *ecran;
 SDL_Event event;
Mix_Music *music;

photo init_photo(char images[]); 

void aff_photo(photo ph,SDL_Surface *ecran,int x,int y);

enigmes init_enigmes(char reponse,char image[]);

int Aleatoire();

void aff_enigmes(enigmes e[],int num,SDL_Surface *ecran);

int get_Input(SDL_Event event, int *continuer,enigmes e,int num);

void Enigme_finale();

#endif 