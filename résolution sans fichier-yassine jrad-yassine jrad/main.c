#include<SDL/SDL.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_image.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/**
* @file main.c
* @brief Resolution enigme sans fichier
* @author Yassine Jrad
* @version 1.0
* @date June ,12 2020
*
* resolution de l'énigme si sans fichier exemple d'une suite arithmétique
*
*/
int main(int argc, char const *argv[])
{
	int done = 1;
	char num[50];
	int i=0;
	int j=0;
	char result[4]={'1','7','0'};
	SDL_Rect position_msg,question_propose,choice;
	SDL_Surface *screen ,*msg,*msg1,*imageDeback,*rfaux ,*rvrai;
	TTF_Font *font = NULL;
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();	
	screen = SDL_SetVideoMode(1000,648,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_Event event;
	font = TTF_OpenFont("font.ttf",50);
	SDL_Color color = {0,0,0};
	choice.x=80;
	choice.y=550;

	while(done) {
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT)
			{
				done = 0;
			}
			if(event.type == SDL_KEYDOWN) 
			{
				if(event.key.keysym.sym == SDLK_ESCAPE)
				{
					done = 0;
				}
			}
			if(event.key.keysym.sym == SDLK_0)
			{
				num[i]='0';
				i++;
				j=0;
			}
			if(event.key.keysym.sym == SDLK_1)
			{
				num[i]='1';
				i++;
				j=0;
			}
			if(event.key.keysym.sym == SDLK_2)
			{
				num[i]='2';
				i++;
				j=0;
			}
			if(event.key.keysym.sym == SDLK_3)
			{
				num[i]='3';
				i++;
				j=0;
			}
			if(event.key.keysym.sym == SDLK_4)
			{
				num[i]='4';
				i++;
				j=0;
			}
			if(event.key.keysym.sym == SDLK_5)
			{
				num[i]='5';
				i++;
				j=0;
			}
			if(event.key.keysym.sym == SDLK_6)
			{
				num[i]='6';
				i++;
				j=0;
			}
			if(event.key.keysym.sym == SDLK_7)
			{
				num[i]='7';
				i++;
				j=0;
			}
			if(event.key.keysym.sym == SDLK_8)
			{
				num[i]='8';
				i++;
				j=0;
			}
			if(event.key.keysym.sym == SDLK_9)
			{
				num[i]='9';
				i++;
				j=0;
			}
			if(event.key.keysym.sym == SDLK_CLEAR)
			{
				if(j==0)
				{
					num[i]=' ';
					j++;	
				}
				else
				{
					num[i]=' ';
					i--;
				}
			}
			if(event.key.keysym.sym == SDLK_RETURN)
			{
				if (strcmp (num,result)==0)
				{
					rvrai = IMG_Load("rvrai.png");	
					SDL_BlitSurface(rvrai,NULL,screen,NULL);
					SDL_Flip(screen);
				}
				else
				{
					rfaux = IMG_Load("rfaux.png");	
					SDL_BlitSurface(rfaux,NULL,screen,NULL);
					SDL_Flip(screen);
				}
			}
		}
		imageDeback = IMG_Load("back.jpg");
		SDL_BlitSurface(imageDeback, NULL, screen, NULL);
		SDL_Flip(screen);
		question_propose.x = 180;
		question_propose.y = 180;
		msg = TTF_RenderText_Solid(font, 'x=50*3+20' , color);
		SDL_BlitSurface(msg,NULL,screen,&question_propose);
		msg1 = TTF_RenderText_Solid(font, num , color);
		SDL_BlitSurface(msg1,NULL,screen,&choice);
		SDL_Flip(screen);
		SDL_Delay(16);
	}
	SDL_FreeSurface(screen);
	SDL_FreeSurface(msg);
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();
	return 0;
}
