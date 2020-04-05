#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* fel main zid int score=0  ; a chaque fois tsir collision score+= 1  ; w zid int sante=100  ;
et int vie =3  ; while(tsir 3arka avec l enemie){ sante-=5 ;
if(sante==0){vie-=1; sante=100;}} */
void initTTF() ;
void initialisationScore(int x , TTF_Font *font ,SDL_Surface *points ,SDL_Rect pospoints);

void closeScore(TTF_Font *font ,SDL_Surface *points);


void showScore(SDL_Surface *screen,SDL_Surface *points ,SDL_Rect pospoints ) ;



void initialisationVie(int y , TTF_Font *police ,SDL_Surface *point ,SDL_Rect posit);

void closeScoreVie(TTF_Font *police ,SDL_Surface *point);


void showScoreVie(SDL_Surface *screen,SDL_Surface *point ,SDL_Rect posit ) ;




#endif
