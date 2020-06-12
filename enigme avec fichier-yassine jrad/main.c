#include<SDL/SDL.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_image.h>
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include"enigme.h"

/**
* @file main.c
* @brief main program
* @author Yassine Jrad
* @version 2.0
* @date June ,12 2020
*
* Afichage et résolution énigme avec fichier 
*
*/

/**
* @brief genere les reponse
* @param t structure de type Question
* @param q numero de la reponse
* @return la reponse selon son numero
*/
const char* getQuestion(Question *t,int q){
	if(q==0)
		return t->reponse1;
	if(q==1)
		return t->reponse2;
	if (q==2)
		return t->reponse3;
}	

int main() {

	int done = 1;
	int currentChoice = 0;
	srand(time(NULL));
	int qid = (rand() % (9));
	printf("%d \n",qid );
	int choices[3] = {0,1,2};
	Enigme q;
	enigme_Init(&q,"./questions.txt");
    SDL_Rect choice1,choice2,choice3 ,question_propose, positionback,choice;
	SDL_Surface *screen ,*msg,*imageDeback, *square,*rfaux ,*rvrai;
	TTF_Font *font = NULL;
	TTF_Font *font1 = NULL;

	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	
	screen = SDL_SetVideoMode(1000,648,32,SDL_HWSURFACE | SDL_DOUBLEBUF);

	SDL_Event event;

	font = TTF_OpenFont("font.ttf",30);
	SDL_Color color = {0,0,0};
	
	


	choice.x = 80;
	choice.y = 532.8;
	positionback.x=positionback.y=0;

	square = SDL_CreateRGBSurface(0,10,10,28,0,0,0,0);
	SDL_FillRect(square,NULL,SDL_MapRGB(square->format,0,255,0));

	SDL_EnableKeyRepeat(0,0);
	
	while(done) {
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
					done = 0;
			}
			if(event.type == SDL_KEYDOWN) 
			{
				if(event.key.keysym.sym == SDLK_ESCAPE){
					done = 0;
				}
				if(event.key.keysym.sym == SDLK_RIGHT){
					if(currentChoice != 2)
						currentChoice++;
					else 
						currentChoice = 0;	
				}
				if(event.key.keysym.sym == SDLK_LEFT){
					if(currentChoice != 0)
						currentChoice--;
					else 
						currentChoice = 2;	
				}
				if(event.key.keysym.sym == SDLK_RETURN){
					if(choices[currentChoice] == 0 && (qid<=0 && qid<3)){
						done = 0;
                        rvrai=IMG_Load("rvrai.png");
						SDL_BlitSurface(rvrai,NULL,screen,NULL);
						SDL_Flip(screen);
						SDL_Delay(1000);
					}
					else if(choices[currentChoice] == 1 && (qid<=3 && qid<6)){
						done = 0;
                        rvrai=IMG_Load("rvrai.png");
						SDL_BlitSurface(rvrai,NULL,screen,NULL);
						SDL_Flip(screen);
						SDL_Delay(1000);
					}
					else if(choices[currentChoice] == 2 && (qid<=6 && qid<9)){
						done = 0;
                        rvrai=IMG_Load("rvrai.png");
						SDL_BlitSurface(rvrai,NULL,screen,NULL);
						SDL_Flip(screen);
						SDL_Delay(1000);
					}
					else {
						done = 0;
                        rfaux=IMG_Load("rfaux.png");
						SDL_BlitSurface(rfaux,NULL,screen,NULL);
						SDL_Flip(screen);
						SDL_Delay(1000);
					}
				}
			}
		}
	imageDeback = IMG_Load("back.jpg");
	SDL_BlitSurface(imageDeback, NULL, screen, &positionback);
	SDL_Flip(screen);
			
	question_propose.x = 30;
	question_propose.y = 180;

	msg = TTF_RenderText_Solid(font, q.questions[qid].question , color);
	SDL_BlitSurface(msg,NULL,screen,&question_propose);
	choice1.x=93.6;
	choice1.y = 532.8;
	msg = TTF_RenderText_Solid(font, getQuestion(&q.questions[qid],choices[0]) , color);
	SDL_BlitSurface(msg,NULL,screen,&choice1);
	choice2.x=453.6;
	choice2.y = 532.8;
	msg = TTF_RenderText_Solid(font, getQuestion(&q.questions[qid],choices[1]) , color);
	SDL_BlitSurface(msg,NULL,screen,&choice2);
    choice3.x=770.4;
	choice3.y = 532.8;
	msg = TTF_RenderText_Solid(font, getQuestion(&q.questions[qid],choices[2]), color);
	SDL_BlitSurface(msg,NULL,screen,&choice3);
	choice.x = 80+currentChoice*338.5;
	SDL_BlitSurface(square,NULL,screen,&choice);


	SDL_Flip(screen);
		SDL_Delay(16);
	}


	SDL_FreeSurface(screen);
	SDL_FreeSurface(msg);
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();

}
