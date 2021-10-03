#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "aEnigmes.h"


void initSDL()
{
	ecran = SDL_SetVideoMode(1280,590,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	SDL_Init(SDL_INIT_AUDIO);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	Mix_AllocateChannels(32);
}

backgroundd init(char name[])
{
	backgroundd b;
	b.background = SDL_LoadBMP(name);
	b.positionFond.x=0;
	b.positionFond.y=0;
	return b;
}


void afficher(backgroundd *b)
{
	SDL_BlitSurface(b->background,NULL,ecran,&b->positionFond);
	
}

enigme initialiserEnigme(char bg[],char win[],char lose[])
{
	enigme E;
	E.background = IMG_Load(bg);
	E.win = IMG_Load(win);
	E.lose = IMG_Load(lose);
	E.positionFond.x =0;
	E.positionFond.y =0;
	E.n=5;
	E.trials=8;
	E.objLeft=E.n;
	E.positionTrials.x=1210;
	E.positionTrials.y=74;

	//Music
	E.backgroundMus = Mix_LoadWAV("Enigmes/wEnigme/backgroundMus.wav");
	E.rightEffect = Mix_LoadWAV("Enigmes/wEnigme/rightEffect.wav");
	E.wrongEffect = Mix_LoadWAV("Enigmes/wEnigme/wrongEffect.wav");
	E.stampEffect = Mix_LoadWAV("Enigmes/wEnigme/stampEffect.wav");
	E.houseAlarm = Mix_LoadWAV("Enigmes/wEnigme/houseAlarm.wav");


	//initialiser les positions des objets
	
	//MUG
	strcpy(E.obj[0].name,"MUG");                       
	E.obj[0].cords.x=647;
	E.obj[0].cords.w=26;
	E.obj[0].cords.y=324;
	E.obj[0].cords.h=26;
	E.obj[0].clicked=0;
	E.obj[0].imageTick = IMG_Load("Enigmes/wEnigme/mugTick.png");
	E.obj[0].cordsText.x=1057;
	E.obj[0].cordsText.y=185;

	//LAMP
	strcpy(E.obj[1].name,"LAMP");   
	E.obj[1].cords.x=599;
	E.obj[1].cords.w=16;
	E.obj[1].cords.y=56;
	E.obj[1].cords.h=40;
	E.obj[1].clicked=0;
	E.obj[1].imageTick = IMG_Load("Enigmes/wEnigme/lampTick.png");
	E.obj[1].cordsText.x=1057;
	E.obj[1].cordsText.y=225;

	//RADIO
	strcpy(E.obj[2].name,"RADIO");   
	E.obj[2].cords.x=135;
	E.obj[2].cords.w=61;
	E.obj[2].cords.y=140;
	E.obj[2].cords.h=38;
	E.obj[2].clicked=0;
	E.obj[2].imageTick = IMG_Load("Enigmes/wEnigme/radioTick.png");
	E.obj[2].cordsText.x=1057;
	E.obj[2].cordsText.y=265;

	//PHONE
	strcpy(E.obj[3].name,"PHONE");   
	E.obj[3].cords.x=429;
	E.obj[3].cords.w=58;
	E.obj[3].cords.y=300;
	E.obj[3].cords.h=19;
	E.obj[3].clicked=0;
	E.obj[3].imageTick = IMG_Load("Enigmes/wEnigme/phoneTick.png");
	E.obj[3].cordsText.x=1057;
	E.obj[3].cordsText.y=305;

	//SAFE
	strcpy(E.obj[4].name,"SAFE");   
	E.obj[4].cords.x=908;
	E.obj[4].cords.w=100;
	E.obj[4].cords.y=378;
	E.obj[4].cords.h=115;
	E.obj[4].clicked=0;
	E.obj[4].imageTick = IMG_Load("Enigmes/wEnigme/safeTick.png");
	E.obj[4].cordsText.x=1057;
	E.obj[4].cordsText.y=345;


	return E;

}

void afficherEnigme(enigme *E)
{
	SDL_BlitSurface(E->background,NULL,ecran,&E->positionFond);
	Mix_PlayChannel(1, E->backgroundMus, -1);

	
}

void enigmeInput(enigme *E,int *continu)
{
	int i;
	E->wrong=0;
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
	    	if(e.button.x >= E->obj[i].cords.x && e.button.x <= (E->obj[i].cords.x + E->obj[i].cords.w) && e.button.y >= E->obj[i].cords.y && e.button.y <= (E->obj[i].cords.y + E->obj[i].cords.h))
	    	{

	    		E->obj[i].clicked=1;
	    		E->objLeft--;
	    		E->wrong=1;

	    	}
    	}
    	E->trials--;
    break;
	}
	
}

int EndingCheck(enigme *E)
{

	char compteur[2];


		if (E->objLeft==0)
			return 0;

		if ((E->trials==0) && ((E->objLeft)>0))
			return -1;

		

		return E->trials;


}

int ending(enigme *E,int end)
{
	if (end==0)
	{
		Mix_PlayChannel(2, E->stampEffect, 0);
		SDL_Delay(500);
		SDL_BlitSurface(E->win,NULL,ecran,&E->positionFond);
		SDL_Flip(ecran);
		SDL_Delay(2000);
		return 1;
		

	}
	if (end==-1)
	{
		Mix_PlayChannel(2, E->stampEffect, 0);
		Mix_PlayChannel(1, E->houseAlarm, 0);
		SDL_Delay(500);
		SDL_BlitSurface(E->lose,NULL,ecran,&E->positionFond);
		SDL_Flip(ecran);
		SDL_Delay(2000);
		return -1;
		
	}
}

void animationEnigme(enigme *E,int end,int old)
{
	SDL_Rect positionBoard;
	char var[10];
	int i;
	SDL_Surface *textTrials,*board;
	SDL_Color colorBlack = {0, 0, 0}, colorGrey = {121, 121, 121}, colorGreen = {1, 121, 1}, colorRed = {219,8,8};
	TTF_Font *police = TTF_OpenFont("Enigmes/wEnigme/Assyrian.ttf", 24);
	
	//BOARD
	positionBoard.x=1008;
	positionBoard.y=0;
	board = IMG_Load("Enigmes/wEnigme/Board.png");

	//TRIALS
	sprintf(var, "%d", E->trials);
	textTrials = TTF_RenderText_Solid (police,var,colorGrey);


	if (E->trials==8)
	{
		SDL_BlitSurface(textTrials, NULL, ecran, &E->positionTrials);

		for (i=0;i<(E->n);i++)
		{
			E->obj[i].textObj = TTF_RenderText_Solid (police,E->obj[i].name,colorBlack);
			SDL_BlitSurface(E->obj[i].textObj, NULL, ecran, &E->obj[i].cordsText);
		}	
	}
 	

 	if(end!=old)
 	{
	SDL_BlitSurface(board, NULL, ecran, &positionBoard);
	if (E->wrong==0)
	{
		textTrials = TTF_RenderText_Solid (police,var,colorRed);
		
		Mix_PlayChannel(2, E->wrongEffect, 0);
	}
	else
	{
		textTrials = TTF_RenderText_Solid (police,var,colorGrey);
		Mix_PlayChannel(2, E->rightEffect, 0);
	}
	SDL_BlitSurface(textTrials, NULL, ecran, &E->positionTrials);
		for (i=0;i<(E->n);i++)
		{
			if (E->obj[i].clicked==0)
			{
				E->obj[i].textObj = TTF_RenderText_Solid (police,E->obj[i].name,colorBlack);
				
			}
			if (E->obj[i].clicked==1)
			{
				E->obj[i].textObj = TTF_RenderText_Solid (police,E->obj[i].name,colorGreen);
				
				SDL_BlitSurface(E->obj[i].imageTick,NULL,ecran,&E->obj[i].cords);
				E->obj[i].clicked=2;
			}
			SDL_BlitSurface(E->obj[i].textObj, NULL, ecran, &E->obj[i].cordsText);
		}
	}

}


void score (enigme *E)
{
	int i,tot=0;
	SDL_Rect pos;
	pos.x =1140 ;
	pos.y=520;
	SDL_Color colorBlack = {0, 0, 0}, colorGrey = {121, 121, 121}, colorGreen = {1, 121, 1}, colorRed = {219,8,8};
	TTF_Font *police = TTF_OpenFont("Enigmes/wEnigme/Assyrian.ttf", 24);
	SDL_Surface *textScore;
	char scor[10];
	int score=0;
   E->objLeft = 10;





    for (i=0;i<(E->n);i++)
             {
             	if (E->obj[i].clicked==0)
             	tot++;
              }

    score = 50-(tot*10);
   
   sprintf(scor, "%d", score);
	textScore = TTF_RenderText_Solid (police,scor,colorGrey);

	SDL_BlitSurface(textScore, NULL, ecran, &pos);

}
	
		  
		



