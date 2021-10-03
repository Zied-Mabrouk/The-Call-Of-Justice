#include "Enigmes.h"

#include "aEnigmes.h"


photo init_photo(char images[])
{

    photo ph;

    ph.images = IMG_Load(images);

    return ph;
}

void aff_photo(photo ph, SDL_Surface *ecran, int x, int y)
{
    ph.position.x = x;
    ph.position.y = y;
    SDL_BlitSurface(ph.images, NULL, ecran, &ph.position);
}

enigmes init_enigmes(char reponse, char image[])
{
    enigmes e;
    e.image = IMG_Load(image);
    e.positionE.x = 0;
    e.positionE.y = 0;
    e.corr = reponse;

    return e;
}


int Aleatoire()
{
    int num;
    srand(time(0));
    num = (rand() % 3);  //(upper - lower + 1)) + lower
    return num;
}

void aff_enigmes(enigmes e[], int num, SDL_Surface *ecran)
{

    SDL_BlitSurface(e[num].image, NULL, ecran, &e[num].positionE);
}

int get_Input(SDL_Event event, int *continuer, enigmes e, int num)
{
    int resolution = 0;
    char rep;
    do
    {
        SDL_WaitEvent(&event);
    }
    while(!(event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && (event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_b || event.key.keysym.sym == SDLK_c))));
    switch(event.type)
    {

    case SDL_QUIT:
        (*continuer) = 0;
        break;

    case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {

        case SDLK_a :

            rep = 'a';

            break;


        case SDLK_b:

            rep = 'b';

            break;


        case SDLK_c:


            rep = 'c';

            break;
        }
        if (e.corr == rep)
            resolution = 1;

        else
            resolution = 0;
    }

    return resolution;
}
void Enigme_finale()
{
    int final=0,test,exit,old,end,continu = 1;
    enigme E;
    E = initialiserEnigme("Enigmes/wEnigme/background.png", "Enigmes/wEnigme/win.png", "Enigmes/wEnigme/lose.png");
        afficherEnigme(&E);
        while(continu)
        {
            old = EndingCheck(&E);
            enigmeInput(&E, &continu);
            animationEnigme(&E, EndingCheck(&E), old);
            SDL_Flip(ecran);
            if (EndingCheck(&E) == 0)
            {
                exit = 0;
                continu = 0;
            }
            if(EndingCheck(&E) == -1)
            {
                exit = -1;
                continu = 0;
            }
        }
        if (exit == 0)
        {
            test = jEnigme();
            final = ending(&E, test);
        }
        if (exit == -1)
            final = ending(&E, exit);
        Mix_FreeChunk(E.backgroundMus);
        Mix_FreeChunk(E.rightEffect);
        Mix_FreeChunk(E.wrongEffect);
        Mix_FreeChunk(E.stampEffect);
        Mix_FreeChunk(E.houseAlarm);
        SDL_FreeSurface(E.background);
        SDL_FreeSurface(E.win);
        SDL_FreeSurface(E.lose);

        Mix_CloseAudio();
}

