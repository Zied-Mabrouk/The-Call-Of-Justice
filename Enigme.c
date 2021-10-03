/**
@file Enigme.c
@brief code de l'enigme nbr 3
@date 05/06/2020
@author Jasser 

*/
#include "Enigme.h"
#include "hero.h"
/*void initSDL()
{
	ecran = SDL_SetVideoMode(1280,590,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Init(SDL_INIT_AUDIO);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	Mix_AllocateChannels(32);
}*/

/**
@brief afficher la photo
@param variable de type eenigmes
@return rien
*/
void aff_PIC(eenigmes *E)
{

	if (E->trials==5)
		SDL_BlitSurface(E->ph[0].pic,NULL,ecran,&E->ph[0].cordspic);
	if (E->trials==4)
        SDL_BlitSurface(E->ph[1].pic,NULL,ecran,&E->ph[0].cordspic);
	if (E->trials==3)
		SDL_BlitSurface(E->ph[2].pic,NULL,ecran,&E->ph[0].cordspic);
	if (E->trials==2)
		SDL_BlitSurface(E->ph[3].pic,NULL,ecran,&E->ph[0].cordspic);
	if (E->trials==1)
		SDL_BlitSurface(E->ph[4].pic,NULL,ecran,&E->ph[0].cordspic);
	if (E->trials==0)
		SDL_BlitSurface(E->ph[5].pic,NULL,ecran,&E->ph[0].cordspic);

}


/**
@brief afficher la photo
@param initialiser l'enigmes (position, les effets sonores , les files qu'ils faut les couper et files qu'ils ne faut pas les couper ) 
@return variable de type eenigmes
*/
eenigmes initialiserEnigmee(char bg[])
{
	eenigmes E;
	E.background = IMG_Load(bg);

	E.positionFond.x =0;
	E.positionFond.y =0;
	E.n=8;
	E.trials=5;
	E.objLeft=3;
	E.positionTrials.x=1210;
	E.positionTrials.y=74;

	//Music
 
    E.backgroundMus = Mix_LoadWAV("backgroundMus.wav");
    E.rightEffect = Mix_LoadWAV("rightEffect.wav");
	E.wrongEffect = Mix_LoadWAV("wrongEffect.wav");
	E.stampEffect = Mix_LoadWAV("stampEffect.wav");
	E.houseAlarm = Mix_LoadWAV("houseAlarm.wav");

	//initialiser les positions des objets
	 

	//correct zone

	strcpy(E.obj[0].name,"yellow");                       
	E.obj[0].cords.x=330;
	E.obj[0].cords.w=105;
	E.obj[0].cords.y=97;
	E.obj[0].cords.h=32;
	E.obj[0].clicked=0;
	E.obj[0].imageTick = IMG_Load("1.png");
	E.obj[0].cordsTick.x=276;
	E.obj[0].cordsTick.y=74;
	E.obj[0].photo = IMG_Load("green.png");
	E.obj[0].cordsgreen.x=431;
	E.obj[0].cordsgreen.y=79;

	
	strcpy(E.obj[1].name,"blue");   
	E.obj[1].cords.x=533;
	E.obj[1].cords.w=114;
	E.obj[1].cords.y=171;
	E.obj[1].cords.h=21;
	E.obj[1].clicked=0;
    E.obj[1].imageTick = IMG_Load("2.png");
	E.obj[1].cordsTick.x=488;
	E.obj[1].cordsTick.y=74;
    E.obj[1].photo = IMG_Load("green.png");
	E.obj[1].cordsgreen.x=622;
	E.obj[1].cordsgreen.y=78;

	
	strcpy(E.obj[2].name,"white");   
	E.obj[2].cords.x=522;
	E.obj[2].cords.w=126;
	E.obj[2].cords.y=396;
	E.obj[2].cords.h=20;
	E.obj[2].clicked=0;
	E.obj[2].imageTick = IMG_Load("3.png");
	E.obj[2].cordsTick.x=494;
	E.obj[2].cordsTick.y=289;
    E.obj[2].photo = IMG_Load("green.png");
	E.obj[2].cordsgreen.x=631;
	E.obj[2].cordsgreen.y=292;



	// wrong zone

	strcpy(E.obj[3].name,"not yellow");   
	E.obj[3].cords.x=326;
	E.obj[3].cords.w=118;
	E.obj[3].cords.y=133;
	E.obj[3].cords.h=118;
	E.obj[3].clicked=0;
	
	strcpy(E.obj[4].name,"not blue 1");   
	E.obj[4].cords.x=533;
	E.obj[4].cords.w=114;
	E.obj[4].cords.y=93;
	E.obj[4].cords.h=77;
	E.obj[4].clicked=0;

    strcpy(E.obj[5].name,"not blue 2");   
	E.obj[5].cords.x=533;
	E.obj[5].cords.w=114;
	E.obj[5].cords.y=194;
	E.obj[5].cords.h=53;
	E.obj[5].clicked=0;

    strcpy(E.obj[6].name,"not white 1");   
	E.obj[6].cords.x=523;
	E.obj[6].cords.w=113;
	E.obj[6].cords.y=310;
	E.obj[6].cords.h=65;
	E.obj[6].clicked=0;
	
	strcpy(E.obj[7].name,"not white 2");   
	E.obj[7].cords.x=525;
	E.obj[7].cords.w=111;
	E.obj[7].cords.y=435;
	E.obj[7].cords.h=40;
	E.obj[7].clicked=0;


	E.ph[0].pic=IMG_Load("111.png");
	E.ph[1].pic=IMG_Load("222.png"); 
	E.ph[2].pic=IMG_Load("333.png"); 
	E.ph[3].pic=IMG_Load("444.png"); 
    E.ph[4].pic=IMG_Load("555.png");  
	E.ph[5].pic=IMG_Load("666.png"); 
	E.ph[0].cordspic.x=181;
	E.ph[0].cordspic.y=4;

	return E;
}

/**
@brief afficher l'enigmes
@param variable de type eenigmes
@return rien
*/
void afficherEnigmee(eenigmes *E)
{
	SDL_BlitSurface(E->background,NULL,ecran,&E->positionFond);
	//SDL_BlitSurface(E->back,NULL,ecran,&E->pos);
	Mix_PlayChannel(1, E->backgroundMus, -1);
}

/**
@brief tester click de sourie
@param variable de type eenigmes et un entier
@return rien
*/

void enigmeInputt(eenigmes *E,int *continu)
{
	int i,j;
	E->right=0;
	SDL_Event e;
	SDL_WaitEvent(&e);
	switch(e.type)
    {
    case SDL_QUIT:
        (*continu) = 0;
    break; 
    case SDL_MOUSEBUTTONUP:
    	for(i=0;i<(E->n);i++)
    	{ 
	    	if((e.button.x >= E->obj[i].cords.x && e.button.x <= (E->obj[i].cords.x + E->obj[i].cords.w) && e.button.y >= E->obj[i].cords.y && e.button.y <= (E->obj[i].cords.y + E->obj[i].cords.h)) && (i<3 ) )
	    	{
	    		E->obj[i].clicked=1;
      E->objLeft--;
      E->trials--;
      E->right=i;
      
             }
if(e.button.x >= E->obj[i].cords.x && e.button.x <= (E->obj[i].cords.x + E->obj[i].cords.w) && e.button.y >= E->obj[i].cords.y && e.button.y <= (E->obj[i].cords.y + E->obj[i].cords.h) && ( i>=3) )
   {
   	  E->obj[i].clicked=2;
      E->trials--;
   }
	    }
    break;
	}
}
/**
@brief teste si on a atteint la fin de l'enigmes
@param variable de type eenigmes
@return un entier entre -1 et 0 
*/
int EndingCheckk(eenigmes *E)
{
	char compteur[2];

		if (E->objLeft==0)
			return 0;
		if ((E->trials==0) && ((E->objLeft)>0))
			return -1;
		return E->trials;

}
/**
@brief teste si on a atteint la fin de l'enigmes
@param variable de type eenigmes
@return un entier entre -1 et 0 
*/
void checkk(eenigmes *E,int i)
{

 
SDL_BlitSurface(E->obj[i].imageTick,NULL,ecran,&E->obj[i].cordsTick);
SDL_BlitSurface(E->obj[i].photo,NULL,ecran,&E->obj[i].cordsgreen);

}
/**
@brief initialiser photo
@param nom de l'image
@return retourner varialbe de type pic 
*/
pic init_photoo(char images[])
{

    pic p;

    p.images = IMG_Load(images);

    return p;
}
/**
@brief teste si on a atteint la fin de l'enigmes
@param variable de type pic et la position de pic
@return rien 
*/
void aff_photoo(pic p, int x, int y)
{
    p.pos.x = x;
    p.pos.y = y;
    SDL_BlitSurface(p.images, NULL, ecran, &p.pos);
}
/**
@brief la fonction main de 3éme enigme
@param rien
@return rien
*/
void eenigme_ja()
{
eenigmes En;


    photoo ph[5];
    pic p, m, w;
    int   exitt, ii, continuu = 1, testt = 0;
    En = initialiserEnigmee("11.png");
    p = init_photoo("attempts.png");
    m = init_photoo("lose.png");
    w = init_photoo("win.png");

        afficherEnigmee(&En);
        aff_photoo(p, 0, 0);
        SDL_Flip(ecran);
        while(continuu)

        {
            enigmeInputt(&En, &continuu);
            for(ii = 0; ii < En.n; ii++)
            {
                if(En.obj[ii].clicked == 1)
                {
                    checkk(&En, ii);
                    //    Mix_PlayChannel(2, E.rightEffect, 0);
                }
                aff_PIC(&En);

                /* if(E.obj[i].clicked == 2)
                 {
                   Mix_PlayChannel(2, E.wrongEffect, 0);
                 }*/

            }
            SDL_Flip(ecran);
            if (EndingCheckk(&En) == 0)

            {
                exitt = 0;
                continuu = 0;
                SDL_Delay(1000);
                Mix_PlayChannel(2, En.stampEffect, 0);
                SDL_Delay(400);
                aff_photoo(w, 0, 0);



            }
            if(EndingCheckk(&En) == -1)
            {
                exitt = -1;
                continuu = 0;

                SDL_Delay(1000);
                Mix_PlayChannel(2, En.stampEffect, 0);
                SDL_Delay(400);
                aff_photoo(m, 0, 0);
                Mix_PlayChannel(1, En.houseAlarm, 0);

            }
                   }
       
    
}
