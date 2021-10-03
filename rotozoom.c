/**
@file rotozoom.c
@brief code de rotozoom
@date 12/06/2020
@author Rihem

*/


#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_rotozoom.h>
 
#define TEMPS       25
#include "header.h"

 /**
@brief rotation et zoom
@param rien
@return variable de type entier 
*/
int loading()
{
    SDL_Surface *fond=NULL ,*image = NULL, *rotation = NULL;
    SDL_Rect rect,pos;
    SDL_Event event;
    double angle = 0;
    double zoom = 1.0;
    int sens =1 ;



    pos.x=0;
    pos.y=0;


 
    int continuer = 1;
    int tempsPrecedent = 0, tempsActuel = 0;
 

 
    image = IMG_Load("diamond.png");
    fond = IMG_Load ("bg.jpg");


 
    while(continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }
 
        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent > TEMPS)
        {
            angle += 2; 
            
            

            tempsPrecedent = tempsActuel;
        }
        else
        {
            SDL_Delay(TEMPS - (tempsActuel - tempsPrecedent));
        }

       


         if (tempsActuel>13000)
            continuer=0;
 
         SDL_BlitSurface(fond,NULL,ecran,&pos);
        rotation = rotozoomSurface(image, angle, zoom, 0); 


        rect.x =  640 - rotation->w / 2;
        rect.y =  287 - rotation->h / 2;


    
 
        SDL_BlitSurface(rotation ,NULL, ecran, &rect); 
       
        SDL_FreeSurface(rotation); 
    
 
        
        if(zoom >= 2){sens = 0;}
        else if(zoom <= 0.5){sens = 1;}
 
        if(sens == 0){zoom -= 0.02;}
        else{zoom += 0.02;}


        SDL_Flip(ecran);
    }
 
    SDL_FreeSurface(ecran);
    SDL_FreeSurface(image);
   
 
    return EXIT_SUCCESS;
}
