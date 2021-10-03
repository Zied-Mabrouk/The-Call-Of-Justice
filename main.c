#include "header.h"

int main(int argc, char *argv[])
{
    
    init_SDL();
    int continuer=1,choix=1, save;

    while(continuer)
    {
        switch(choix)
        {
            case 0:
            continuer=0;
            break;
            case 1:
            choix = MenuP();
            break;
            case 2:
            choix = MenuOp();
            break;
            case 3:
            choix = Game(&save);
            break;
            case 4:
            choix= MenuMultiplayer();
            break;
            case 5:
            choix = MenuController();
            break;
            case 6:
            choix = MenuLoad(&save);
            break;
        }
    }
    SDL_Quit();
    return EXIT_SUCCESS;
}