#include "menu.h"

int in = 0, position;

Button init_button(int x, int y, char name1[], char name2[])
{
    Button bu;
    bu.positionButton.x = x;
    bu.positionButton.y = y;
    bu.image1 = IMG_Load(name1);
    bu.image2 = IMG_Load(name2);
    bu.state = 1;
    return bu;
}

void aff_button(Menu *m)
{
    int i;
    for(i = 0; i < m->nbre; i++)
    {
        if (m->B[i].state == 1)
            SDL_BlitSurface(m->B[i].image1, NULL, ecran, &m->B[i].positionButton);
        if (m->B[i].state == 2)
            SDL_BlitSurface(m->B[i].image2, NULL, ecran, &m->B[i].positionButton);
    }
}

//Fonction qui renvoie le numero du bouton sur lequel se trouve la souriss
int mouse_input(SDL_Event event, Menu *m)
{
    int position = 0, i;

    for(i = 0; i < m->nbre; i++)
    {
        if(event.button.x >= m->B[i].positionButton.x && event.button.x <= m->B[i].positionButton.x + m->B[i].positionButton.w
                && event.button.y >= m->B[i].positionButton.y && event.button.y <= m->B[i].positionButton.y + m->B[i].positionButton.h)
            position = i +1;
    }

    return position;
}
//Fonction qui affiche les boutons selon la position de la souris
void hover_button(Menu *m, int pos)
{
    int i;
    for(i = 0; i < m->nbre; i++)
    {
        m->B[i].state = 1;
    }
    if(pos != 0)
        m->B[pos - 1].state = 2;
}

//Fonction de gestion de la souris
void souris(SDL_Event event, int *destination, int *continu, Menu *m)
{
    Mix_Chunk *sound_but;
    sound_but = Mix_LoadWAV("menu/s.wav");
    SDL_PollEvent(&event);
    switch(event.type)
    {
    case SDL_QUIT:
        (*destination) = 0;
        (*continu) = 0;
        Mix_FreeChunk(sound_but);
        break;
    case SDL_MOUSEMOTION:
        position = mouse_input(event, m);
        hover_button(m, position);
        if(position > 0 && position <= m->nbre)
        {
            if(in != 1)
                Mix_PlayChannel(1, sound_but, 0);
            in = 1;
        }
        else
        {
            in = 0;
        }
        break;
    case SDL_MOUSEBUTTONUP:
        position = mouse_input(event, m);
        if(position == 1)
        {
            (*destination) = 4;
            (*continu) = 0;
        }
        if(position == 2)
        {
            (*destination) = 2;
            (*continu) = 0;
        }
        if(position == 4)
        {
            (*continu) = 0;
            (*destination) = 0;
        }
        break;
    case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
        case SDLK_j:
            (*destination) = 3;
            (*continu) = 0;
            break;
        case SDLK_m:
            if (m->muted == 0)
            {
                Mix_VolumeMusic(0);
                m->muted = 1;
            }
            else
            {
                Mix_VolumeMusic(128);
                m->muted = 0;
            }
            break;
        case SDLK_ESCAPE :
            (*continu) = 0;
            (*destination) = 0;
            break;
        case SDLK_UP: // Flèche haut

            switch(m->selected_button)
            {
            case 0:
                hover_button(m, 2);
                m->selected_button = 2 ;
                break;
            case 1:
                hover_button(m, 2);
                m->selected_button=2;
                break;
            case 2:
                hover_button(m, 1);
                m->selected_button=1;
                break;
            case 3:
                hover_button(m, 4);
                m->selected_button=4;
                break;
            case 4:
                hover_button(m, 3);
                m->selected_button=3;
                break;
            case 5:
                hover_button(m, 1);
                m->selected_button = 1;
                break;
            }
            break;
        case SDLK_DOWN: // Flèche bas
           switch(m->selected_button)
            {
            case 0:
                hover_button(m, 1);
                m->selected_button = 1 ;
                break;
            case 1:
                hover_button(m, 2);
                m->selected_button=2;
                break;
            case 2:
                hover_button(m, 1);
                m->selected_button=1;
                break;
            case 3:
                hover_button(m, 4);
                m->selected_button=4;
                break;
            case 4:
                hover_button(m, 3);
                m->selected_button=3;
                break;
            }
            break;
        case SDLK_LEFT: // Flèche gauche
           switch(m->selected_button)
            {
            case 0:
                hover_button(m, 1);
                m->selected_button = 1 ;
                break;
            case 1:
                hover_button(m, 3);
                m->selected_button=3;
                break;
            case 2:
                hover_button(m, 4);
                m->selected_button=4;
                break;
            case 3:
                hover_button(m, 1);
                m->selected_button=1;
                break;
            case 4:
                hover_button(m, 2);
                m->selected_button=2;
                break;
            }
            break;
        case SDLK_RIGHT: // Flèche droite
           switch(m->selected_button)
            {
            case 0:
                hover_button(m, 3);
                m->selected_button = 3 ;
                break;
            case 1:
                hover_button(m, 3);
                m->selected_button=3;
                break;
            case 2:
                hover_button(m, 4);
                m->selected_button=4;
                break;
            case 3:
                hover_button(m, 1);
                m->selected_button=1;
                break;
            case 4:
                hover_button(m, 2);
                m->selected_button=2;
                break;
            }
            break;
        case SDLK_RETURN:
            switch(m->selected_button)
            {
            case 1:
                (*destination) = 4;
                (*continu) = 0;
                break;
            case 2:
                (*destination) = 2;
                (*continu) = 0;
                break;
            case 4:
                (*continu) = 0;
                (*destination) = 0;
                break;
            }
            break;
        }
        break;

    }
}
void souris_MenuOp(SDL_Event event, int *destination, int *continu, Menu *m)
{
    Mix_Chunk *sound_but;
    sound_but = Mix_LoadWAV("menu/s.wav");
    SDL_PollEvent(&event);
    switch(event.type)
    {
    case SDL_QUIT:
        (*destination) = 0;
        (*continu) = 0;
        Mix_FreeChunk(sound_but);
        break;
    case SDL_MOUSEMOTION:
        position = mouse_input(event, m);
        hover_button(m, position);
        if(position > 0 && position <= m->nbre)
        {
            if(in != 1)
                Mix_PlayChannel(1, sound_but, 0);
            in = 1;
        }
        else
        {
            in = 0;
        }
        break;
    case SDL_MOUSEBUTTONUP:
        position = mouse_input(event, m);

        if(position == 2)
        {
            (*continu) = 0;
            (*destination) = 1;
        }
        if(position == 1)
        {
            if (m->muted == 0)
            {
                Mix_VolumeMusic(0);
                m->muted = 1;
            }
            else
            {
                Mix_VolumeMusic(128);
                m->muted = 0;
            }
        }
        break;
    case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
        case SDLK_m:
            if (m->muted == 0)
            {
                Mix_VolumeMusic(0);
                m->muted = 1;
            }
            else
            {
                Mix_VolumeMusic(128);
                m->muted = 0;
            }
            break;
        case SDLK_ESCAPE :
            (*continu) = 0;
            (*destination) = 1;
            break;
        case SDLK_LEFT: // Flèche gauche
           switch(m->selected_button)
            {
            case 0:
                hover_button(m, 1);
                m->selected_button = 1 ;
                break;
            case 1:
                hover_button(m, 2);
                m->selected_button=2;
                break;
            case 2:
                hover_button(m, 1);
                m->selected_button=1;
                break;
            }
            break;
        case SDLK_RIGHT: // Flèche droite
           switch(m->selected_button)
            {
            case 0:
                hover_button(m, 2);
                m->selected_button = 2 ;
                break;
            case 1:
                hover_button(m, 2);
                m->selected_button=2;
                break;
            case 2:
                hover_button(m, 1);
                m->selected_button=1;
                break;
            }
            break;
        case SDLK_RETURN:
            switch(m->selected_button)
            {
            case 1:
                if (m->muted == 0)
                {
                    Mix_VolumeMusic(0);
                    m->muted = 1;
                }
                else
                {
                    Mix_VolumeMusic(128);
                    m->muted = 0;
                }
                break;
            case 2:
                (*destination) = 1;
                (*continu) = 0;
                break;
            }
            break;
        }
        break;

    }
}

void souris_MenuMultiplayer(SDL_Event event, int *destination, int *continu, Menu *m)
{
    Mix_Chunk *sound_but;
    sound_but = Mix_LoadWAV("menu/s.wav");
    SDL_PollEvent(&event);
    (*continu) = 1;
    switch(event.type)
    {
    case SDL_QUIT:
        (*destination) = 0;
        (*continu) = 0;
        Mix_FreeChunk(sound_but);
        break;
    case SDL_MOUSEMOTION:
        position = mouse_input(event, m);
        hover_button(m, position);
        if(position > 0 && position <= m->nbre)
        {
            if(in != 1)
                Mix_PlayChannel(1, sound_but, 0);
            in = 1;
        }
        else
        {
            in = 0;
        }
        break;
    case SDL_MOUSEBUTTONUP:
        position = mouse_input(event, m);

        if(position == 2)
        {
            (*continu) = 0;
            (*destination) = 1;
        }
        if(position == 1)
        {
            (*continu) = 0;
            (*destination) = 5;
        }
        if(position == 3)
            {
            (*continu) = 0;
            (*destination) = 1;
            }
        break;
    case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
        
        case SDLK_ESCAPE :
            (*continu) = 0;
            (*destination) = 1;
            break;
        case SDLK_LEFT: // Flèche gauche
           switch(m->selected_button)
            {
            case 0:
                hover_button(m, 1);
                m->selected_button = 1 ;
                break;
            case 1:
                hover_button(m, 2);
                m->selected_button=2;
                break;
            case 2:
                hover_button(m, 1);
                m->selected_button=1;
                break;
            }
            break;
        case SDLK_RIGHT: // Flèche droite
           switch(m->selected_button)
            {
            case 0:
                hover_button(m, 2);
                m->selected_button = 2 ;
                break;
            case 1:
                hover_button(m, 2);
                m->selected_button=2;
                break;
            case 2:
                hover_button(m, 1);
                m->selected_button=1;
                break;
            }
            break;
        case SDLK_RETURN:
            switch(m->selected_button)
            {
            case 1:
                (*destination) = 3;
                (*continu) = 0;
                break;
            case 2:
                (*destination) = 1;
                (*continu) = 0;
                break;
            }
            break;
        }
        break;

    }
}


void souris_MenuController(SDL_Event event, int *destination, int *continu, Menu *m)
{
    Mix_Chunk *sound_but;
    sound_but = Mix_LoadWAV("menu/s.wav");
    SDL_PollEvent(&event);
    (*continu) = 1;
    switch(event.type)
    {
    case SDL_QUIT:
        (*destination) = 0;
        (*continu) = 0;
        Mix_FreeChunk(sound_but);
        break;
    case SDL_MOUSEMOTION:
        position = mouse_input(event, m);
        hover_button(m, position);
        if(position > 0 && position <= m->nbre)
        {
            if(in != 1)
                Mix_PlayChannel(1, sound_but, 0);
            in = 1;
        }
        else
        {
            in = 0;
        }
        break;
    case SDL_MOUSEBUTTONUP:
        position = mouse_input(event, m);

        if(position == 2)
        {
            (*continu) = 0;
            (*destination) = 4;
        }
        if(position == 1)
        {
            (*continu) = 0;
            (*destination) = 6;
        }
        if(position == 3)
            {
            (*continu) = 0;
            (*destination) = 4;
            }
        break;
    case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
        
        case SDLK_ESCAPE :
            (*continu) = 0;
            (*destination) = 1;
            break;
        case SDLK_LEFT: // Flèche gauche
           switch(m->selected_button)
            {
            case 0:
                hover_button(m, 1);
                m->selected_button = 1 ;
                break;
            case 1:
                hover_button(m, 2);
                m->selected_button=2;
                break;
            case 2:
                hover_button(m, 1);
                m->selected_button=1;
                break;
            }
            break;
        case SDLK_RIGHT: // Flèche droite
           switch(m->selected_button)
            {
            case 0:
                hover_button(m, 2);
                m->selected_button = 2 ;
                break;
            case 1:
                hover_button(m, 2);
                m->selected_button=2;
                break;
            case 2:
                hover_button(m, 1);
                m->selected_button=1;
                break;
            }
            break;
        case SDLK_RETURN:
            switch(m->selected_button)
            {
            case 1:
                (*destination) = 3;
                (*continu) = 0;
                break;
            case 2:
                (*destination) = 1;
                (*continu) = 0;
                break;
            }
            break;
        }
        break;

    }
}


void souris_MenuLoad(SDL_Event event, int *destination, int *continu, Menu *m,int * save)
{
    Mix_Chunk *sound_but;
    sound_but = Mix_LoadWAV("menu/s.wav");
    SDL_PollEvent(&event);
    (*continu) = 1;
    switch(event.type)
    {
    case SDL_QUIT:
        (*destination) = 0;
        (*continu) = 0;
        Mix_FreeChunk(sound_but);
        break;
    case SDL_MOUSEMOTION:
        position = mouse_input(event, m);
        hover_button(m, position);
        if(position > 0 && position <= m->nbre)
        {
            if(in != 1)
                Mix_PlayChannel(1, sound_but, 0);
            in = 1;
        }
        else
        {
            in = 0;
        }
        break;
    case SDL_MOUSEBUTTONUP:
        position = mouse_input(event, m);

        if(position == 2)
        {
            (*continu) = 0;
            (*save)=2;
            (*destination) = 3;
        }
        if(position == 1)
        {
            (*continu) = 0;
            (*destination) = 3;
        }
        if(position == 3)
            {
            (*continu) = 0;
            (*destination) = 5;
            }
        break;
    case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
        
        case SDLK_ESCAPE :
            (*continu) = 0;
            (*destination) = 1;
            break;
        case SDLK_LEFT: // Flèche gauche
           switch(m->selected_button)
            {
            case 0:
                hover_button(m, 1);
                m->selected_button = 1 ;
                break;
            case 1:
                hover_button(m, 2);
                m->selected_button=2;
                break;
            case 2:
                hover_button(m, 1);
                m->selected_button=1;
                break;
            }
            break;
        case SDLK_RIGHT: // Flèche droite
           switch(m->selected_button)
            {
            case 0:
                hover_button(m, 2);
                m->selected_button = 2 ;
                break;
            case 1:
                hover_button(m, 2);
                m->selected_button=2;
                break;
            case 2:
                hover_button(m, 1);
                m->selected_button=1;
                break;
            }
            break;
        case SDLK_RETURN:
            switch(m->selected_button)
            {
            case 1:
                (*destination) = 3;
                (*continu) = 0;
                break;
            case 2:
                (*destination) = 1;
                (*continu) = 0;
                break;
            }
            break;
        }
        break;

    }
}


int souris_MenuSave(Menu *m,SDL_Event event)
{
    
    int position=0;
    SDL_WaitEvent(&event);
    switch(event.type)
    {
    
    case SDL_MOUSEMOTION:
        position = mouse_input(event, m);
        hover_button(m, position);
        
        break;
    case SDL_MOUSEBUTTONUP:
        position = mouse_input(event, m);

        if(position == 2)
        {
            return 0;

        }
        if(position == 1)
        {
            return 1;
        }
    
        
        break;
    case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
        
        
        case SDLK_RIGHT: // Flèche droite
           switch(m->selected_button)
            {
            case 0:
                hover_button(m, 2);
                m->selected_button = 2 ;
                break;
            case 1:
                hover_button(m, 2);
                m->selected_button=2;
                break;
            case 2:
                hover_button(m, 1);
                m->selected_button=1;
                break;
            }
            break;
        
        }
        break;
        

    }
    return 6;
}