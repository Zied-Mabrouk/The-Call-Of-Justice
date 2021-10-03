/**

@file jEnigme.c
@brief code de l'enigme nbr 2
@date 05/06/2020
@author Jasser 

*/
#include "Enigmess.h"

/**
@brief la fonction main de 2éme enigme
@param rien
@return retourner un entier
*/

int jEnigme()
{


    int continuer = 1;
    int resolu, num = 2, i, j;
    
    Mix_Chunk *son;
    Mix_Chunk *son2;
    Mix_Chunk *son3;
    Mix_Chunk *son4;

    son = Mix_LoadWAV("Enigmes/jEnigme/numb.wav");
    son2 = Mix_LoadWAV("Enigmes/jEnigme/open.wav");
    son3 = Mix_LoadWAV("Enigmes/jEnigme/close.wav");
    son4 = Mix_LoadWAV("Enigmes/jEnigme/paper.wav");

    ////////////////////////////////////////
    
    enigmes p[3];
    photo vrai, faux;

    p[0] = init_enigmes('a', "Enigmes/jEnigme/loula.png");
    p[1] = init_enigmes('b', "Enigmes/jEnigme/thenya.png");
    p[2] = init_enigmes('b', "Enigmes/jEnigme/theltha.png");

    vrai = init_photo("Enigmes/jEnigme/vrai.png");
    faux = init_photo("Enigmes/jEnigme/faux.png");
    

    num = Aleatoire();
    aff_enigmes(p, num, ecran);

    SDL_Flip(ecran);

    resolu = get_Input(event, &continuer, p[num], num);

    for(j = 0; j < 4; j++)
    {
        Mix_PlayChannel(1, son, 0);

        SDL_Delay(300);
    }


    if(resolu == 1)
    {
        

        aff_photo(vrai, ecran, 220, 110);


        Mix_PlayChannel(2, son2, 0);

    }
    else
    {
        

        aff_photo(faux, ecran, 200, 80);

        Mix_PlayChannel(3, son3, 0);

    }

    SDL_Flip(ecran);
    SDL_Delay(1000);

    for (i = 0; i < 3; i++)
    {
        SDL_FreeSurface(p[i].image);
    }

    Mix_FreeChunk(son);
    Mix_FreeChunk(son2);
    Mix_FreeChunk(son3);
    Mix_FreeChunk(son4);
    

    SDL_FreeSurface(vrai.images);
    SDL_FreeSurface(faux.images);
    

    if(resolu == 1)
    {

        return 0;

    }
    else
    {


        return -1;
    }

    

    
    



    return EXIT_SUCCESS;
}




