#include "hero.h"
#include "header.h"
#include "entity.h"

//Fonction qui initialise l'héro 
void init_hero(Hero *hero)
{
    hero->e = init_entity(100, Hero_Default_Y);
    hero->e.sprite[0] = IMG_Load("mvtt/r1.png");
    hero->e.sprite[1] = IMG_Load("mvtt/r2.png");
    hero->e.sprite[2] = IMG_Load("mvtt/r3.png");
    hero->e.sprite[3] = IMG_Load("mvtt/r4.png");
    hero->e.sprite[4] = IMG_Load("mvtt/flip.png");
    hero->e.sprite[5] = IMG_Load("mvtt/l1.png");
    hero->e.sprite[6] = IMG_Load("mvtt/l2.png");
    hero->e.sprite[7] = IMG_Load("mvtt/l3.png");
    hero->e.sprite[8] = IMG_Load("mvtt/l4.png");
    hero->e.sprite[9] = IMG_Load("mvtt/hidden.png");
    hero->frame = 0;
    hero->direction = 'r';
    hero->mouvement.right = 0;
    hero->mouvement.left = 0;
    hero->mouvement.up = 0;
    hero->air = 0;
    hero->sol = 0;
    hero->mouse_clicked = 0;
    hero->vitesse = 20;
}

//Fonction qui affiche l'héro 
void aff_hero(Hero *hero)
{
    SDL_BlitSurface(hero->e.sprite[hero->frame], NULL, ecran, &hero->e.position);
}

void free_hero(Hero *hero)
{
    int i;
    for(i = 0; i < 10; i++)
    {
        SDL_FreeSurface(hero->e.sprite[i]);
    }
}
/**
* @brief initialisation de point représentant le hero sur la minimap.
* @param reddot  .
* @return dot.
*/

dot init_dot(char reddot[])
{

    dot herodot;
    herodot.fontdot = IMG_Load(reddot);
    herodot.positiondot.x = 5;
    herodot.positiondot.y = 30;
    
    return herodot;
}
/**
* @brief affichage de point représentant le hero sur la minimap.
* @param herodot  .
* @return Rien.
*/
void aff_dot(dot herodot)
{
 SDL_BlitSurface(herodot.fontdot , NULL, ecran, &herodot.positiondot);
}


