#include "header.h"
#include "menu.h"
#include "hero.h"
#include "enemy.h"
#include "aEnigmes.h"
#include "Enigme.h"
#include "Enigmess.h"
#include <SDL/SDL_rotozoom.h>
 
#define TEMPS       25

animated an;
int MenuP()
{

    int destination;
    TTF_Init();
    SDL_Surface *texte = NULL;
    SDL_Rect position;
    TTF_Font *police = NULL;
    SDL_Color couleur = {0, 0, 0};
    police = TTF_OpenFont("Ghost Writer - Demo.ttf", 30);
    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
    texte = TTF_RenderText_Blended(police, "Copyright 2020 - Imperium ", couleur);
    position.x = 1000;
    position.y = 550;

    Menu m0 = init_menu("menu/menu.png", 4);
    //initialisation des boutons
    m0.B[0] = init_button(340, 200, "menu/play.png", "menu/play_active.png");
    m0.B[1] = init_button(340, 290, "menu/options.png", "menu/options_active.png");
    m0.B[2] = init_button(590, 200, "menu/credits.png", "menu/credits_active.png");
    m0.B[3] = init_button(590, 290, "menu/quit.png", "menu/quit_active.png");
    //iniinitialisation du SDL

    int continu = 1;
    //Affiche le menu
    //Affiche les boutons initials du menu
    init_animation(&an);
    SDL_Event even;


    while(continu)
    {
        aff_menu(&m0);
        SDL_BlitSurface(texte, NULL, ecran, &position);
        aff_button(&m0);
        aff_animation(&an);
        //Gestion de l'input
        souris(even, &destination, &continu, &m0);
        SDL_Flip(ecran);
    }

     

    free_menu(&m0);
    TTF_CloseFont(police);
    TTF_Quit();
    SDL_FreeSurface(texte);
    SDL_Flip(ecran);
    if(destination == 3 || destination == 0)
        free_animation(&an);
    return destination;
}
int MenuOp()
{
    int destination;
    TTF_Init();
    SDL_Surface *texte = NULL;
    SDL_Rect position;
    TTF_Font *police = NULL;
    SDL_Color couleur = {0, 0, 0};
    police = TTF_OpenFont("Ghost Writer - Demo.ttf", 30);
    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
    texte = TTF_RenderText_Blended(police, "Copyright 2020 - Imperium ", couleur);
    position.x = 1000;
    position.y = 550;

    Menu m1 = init_menu("menu/menu.png", 2);

    //initialisation des boutons
    m1.B[0] = init_button(340, 200, "menu/sound.png", "menu/sound_active.png");
    m1.B[1] = init_button(590, 200, "menu/back.png", "menu/back_active.png");
    //iniinitialisation du SDL
    int continu = 1;
    //Affiche le menu
    //Affiche les boutons initials du menu
    SDL_Event even;
    while(continu)
    {
        aff_menu(&m1);
        SDL_BlitSurface(texte, NULL, ecran, &position);
        aff_button(&m1);
        aff_animation(&an);
        //Gestion de l'input
        souris_MenuOp(even, &destination, &continu, &m1);
        SDL_Flip(ecran);
    }
    free_menu(&m1);
    SDL_Flip(ecran);
    TTF_CloseFont(police);
    TTF_Quit();
    SDL_FreeSurface(texte);
    if(destination == 3 || destination == 0)
        free_animation(&an);
    return destination;
}
int Game(int *save)
{
    masque = NULL;
    Hero hero1;
    TTF_Init();
    masque = IMG_Load("mask.png");
    int activer_enigme = 0,i,testt = 0;
    Mix_FreeMusic(music);
enigme E;
    Enemies enemies;
    enemies.nombre = 3;
    enemies.enemy[0] = init_enemy(20,660,340);
    enemies.enemy[1] = init_enemy(20,1560,340);
    enemies.enemy[2] = init_enemy(20,2460,340);
    background = init_back("back.png");
    Map = init_map("minimap.png");
    herodot = init_dot("dot.png");
    intervalleH1 = 0, intervalleH2 = 0,intervalleE1 = 0, intervalleE2 = 0, decalage = 0,
      destination =  0, continuer = 1,position_absolue =100;
    init_hero(&hero1);
    
    SDL_Event event;
    SDL_EnableKeyRepeat(100, 100);
    LoadGame(&hero1,"save.txt",(*save));

    while (continuer)
    {
        aff_back(background);
        aff_map(Map);
        aff_dot(herodot); 
        aff_hero((&hero1));
        Deplacer_dot(&herodot,&hero1);
        getInput(event, &continuer, &background,&hero1,save);
        collision_ennemy(&enemies,&hero1);
        update_ennemy(&enemies,&hero1);
        Deplacer(&enemies);
        aff_enemies(&enemies);
                saveGame(hero1,"save.txt",*save);
        SDL_Flip(ecran);
      if((hero1.e.position.x >= 451 && hero1.e.position.x <= 532) && testt != 1 )
        {
            eenigme_ja();
            SDL_Flip(ecran);
            SDL_Delay(2000);

            testt = 1;

        }

        if(CollisionParfaite(hero1)!=0)
        {
            activer_enigme = 1;
            continuer = 0;
        }
    }

    if(activer_enigme)
      Enigme_finale();
 
       


    SDL_FreeSurface(background.imageDeFond);
    SDL_FreeSurface(Map.map);
    SDL_FreeSurface(herodot.fontdot);
    free_enemy(&enemies);
    free_hero(&hero1);
    SDL_FreeSurface(masque);
    TTF_Quit();
    SDL_FreeSurface(ecran);
    return destination;
}


int MenuMultiplayer()
{
    int destination;
    TTF_Init();
    SDL_Surface *texte = NULL;
    SDL_Rect position;
    TTF_Font *police = NULL;
    SDL_Color couleur = {0, 0, 0};
    police = TTF_OpenFont("Ghost Writer - Demo.ttf", 30);
    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
    texte = TTF_RenderText_Blended(police, "Copyright 2020 - Imperium ", couleur);
    position.x = 1000;
    position.y = 550;

    Menu m1 = init_menu("menu/newgameMenu/MENUBACKGROUND.jpg", 3);

    //initialisation des boutons
    m1.B[0] = init_button(340, 200, "menu/1player.png", "menu/1player_active.png");
    m1.B[1] = init_button(590, 200, "menu/2players.png", "menu/2players_active.png");
    m1.B[2] = init_button(420, 400, "menu/back.png", "menu/back_active.png");
    //iniinitialisation du SDL
    int continu = 1;
    //Affiche le menu
    //Affiche les boutons initials du menu
    SDL_Event even;
    while(continu)
    {
        aff_menu(&m1);
        SDL_BlitSurface(texte, NULL, ecran, &position);
        aff_button(&m1);
        
        //Gestion de l'input
        souris_MenuMultiplayer(even, &destination, &continu, &m1);
        SDL_Flip(ecran);
    }
    free_menu(&m1);
    SDL_Flip(ecran);
    TTF_CloseFont(police);
    TTF_Quit();
    SDL_FreeSurface(texte);
    
    return destination;
}

int MenuController()
{
    int destination;
    TTF_Init();
    SDL_Surface *texte = NULL;
    SDL_Rect position;
    TTF_Font *police = NULL;
    SDL_Color couleur = {0, 0, 0};
    police = TTF_OpenFont("Ghost Writer - Demo.ttf", 30);
    // Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) 
    texte = TTF_RenderText_Blended(police, "Copyright 2020 - Imperium ", couleur);
    position.x = 1000;
    position.y = 550;

    Menu m1 = init_menu("menu/controllerMenu/controllerBACKGROUND.jpg", 3);

    //initialisation des boutons
    m1.B[1] = init_button(740, 350, "menu/controllerMenu/controller.png", "menu/controllerMenu/controller_active.png");
    m1.B[0] = init_button(360, 350, "menu/controllerMenu/mousekeyboard.png", "menu/controllerMenu/mousekeyboard_active.png");
    m1.B[2] = init_button(20, 20, "menu/back.png", "menu/back_active.png");
    //iniinitialisation du SDL
    int continu = 1;
    //Affiche le menu
    //Affiche les boutons initials du menu
    SDL_Event even;
    while(continu)
    {
        aff_menu(&m1);
        SDL_BlitSurface(texte, NULL, ecran, &position);
        aff_button(&m1);
        
        //Gestion de l'input
        souris_MenuController(even, &destination, &continu, &m1);
        SDL_Flip(ecran);
    }
    free_menu(&m1);
    SDL_Flip(ecran);
    TTF_CloseFont(police);
    TTF_Quit();
    SDL_FreeSurface(texte);
    
    return destination;
}

int MenuLoad(int *save)
{
    int destination;
    TTF_Init();
    SDL_Surface *texte = NULL;
    SDL_Rect position;
    TTF_Font *police = NULL;
    SDL_Color couleur = {0, 0, 0};
    police = TTF_OpenFont("Ghost Writer - Demo.ttf", 30);
    // Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) 
    texte = TTF_RenderText_Blended(police, "Copyright 2020 - Imperium ", couleur);
    position.x = 1000;
    position.y = 550;

    Menu m1 = init_menu("menu/newgameMenu/MENUBACKGROUND.jpg", 3);

    //initialisation des boutons
    m1.B[0] = init_button(360, 270, "menu/newgameMenu/newgame.png", "menu/newgameMenu/newgame_active.png");
    m1.B[1] = init_button(740, 270, "menu/newgameMenu/continue.png", "menu/newgameMenu/continue_active.png");
    m1.B[2] = init_button(20, 20, "menu/back.png", "menu/back_active.png");

    
    //iniinitialisation du SDL
    int continu = 1;
    //Affiche le menu
    //Affiche les boutons initials du menu
    SDL_Event even;
    while(continu)
    {
        aff_menu(&m1);
        SDL_BlitSurface(texte, NULL, ecran, &position);
        aff_button(&m1);
        
        //Gestion de l'input
        souris_MenuLoad(even, &destination, &continu, &m1,save);
        SDL_Flip(ecran);
    }
    loading ();
    free_menu(&m1);
    SDL_Flip(ecran);
    TTF_CloseFont(police);
    TTF_Quit();
    SDL_FreeSurface(texte);
    ;
    return destination;
}



