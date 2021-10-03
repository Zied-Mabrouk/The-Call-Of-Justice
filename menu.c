#include "menu.h"


Menu init_menu(char name[], int n)
{
    Menu m;
    m.positionMenu.x = 0;
    m.positionMenu.y = 0;
    m.image_menu = IMG_Load(name);
    m.nbre = n;
    m.selected_button = 0;
    m.muted = 0;
    return m;
}

void aff_menu(Menu *m)
{
    SDL_BlitSurface(m->image_menu, NULL, ecran, &m->positionMenu);
}

void free_menu(Menu *m)
{
    int i;
    SDL_FreeSurface(m->image_menu);
    for(i = 0; i < m->nbre; i++)
    {
        SDL_FreeSurface(m->B[i].image1);
        SDL_FreeSurface(m->B[i].image2);
    }
}
void init_animation(animated *a)
{
    a->position.x = 0;
    a->position.y = 300;
    a->frame = 0;
    a->animation[0] = IMG_Load("animation/0.png");
    a->animation[1] = IMG_Load("animation/0.png");
    a->animation[2] = IMG_Load("animation/1.png");
    a->animation[3] = IMG_Load("animation/1.png");
    a->animation[4] = IMG_Load("animation/2.png");
    a->animation[5] = IMG_Load("animation/2.png");
    a->animation[6] = IMG_Load("animation/3.png");
    a->animation[7] = IMG_Load("animation/3.png");
    a->animation[8] = IMG_Load("animation/4.png");
    a->animation[9] = IMG_Load("animation/4.png");
    a->animation[10] = IMG_Load("animation/5.png");
    a->animation[11] = IMG_Load("animation/5.png");
    a->animation[12] = IMG_Load("animation/6.png");
    a->animation[13] = IMG_Load("animation/6.png");
    a->animation[14] = IMG_Load("animation/7.png");
    a->animation[15] = IMG_Load("animation/7.png");

    a->animation[16] = IMG_Load("animation/8.png");
    a->animation[17] = IMG_Load("animation/8.png");
    a->animation[18] = IMG_Load("animation/9.png");
    a->animation[19] = IMG_Load("animation/9.png");
    a->animation[20] = IMG_Load("animation/10.png");
    a->animation[21] = IMG_Load("animation/10.png");
    a->animation[22] = IMG_Load("animation/11.png");
    a->animation[23] = IMG_Load("animation/11.png");
    a->animation[24] = IMG_Load("animation/12.png");
    a->animation[25] = IMG_Load("animation/12.png");
    a->animation[26] = IMG_Load("animation/13.png");
    a->animation[27] = IMG_Load("animation/13.png");
    a->animation[28] = IMG_Load("animation/14.png");
    a->animation[29] = IMG_Load("animation/14.png");
    a->animation[30] = IMG_Load("animation/15.png");
    a->animation[31] = IMG_Load("animation/15.png");
}
void aff_animation(animated *a)
{   
	SDL_BlitSurface(a->animation[a->frame], NULL, ecran, &a->position);
	 a->frame++;
    if(a->frame == 32)
        a->frame = 0;
    
}
void free_animation(animated *a)
{
    int i;
    for(i = 0; i < 23; i++)
    {
        SDL_FreeSurface(a->animation[i]);
    }
}
