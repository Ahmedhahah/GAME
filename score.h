#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initTTF() ;
void initialisationScore(int x , TTF_Font *font ,SDL_Surface *points ,SDL_Rect pospoints);

void closeScore(TTF_Font *font ,SDL_Surface *points);


void showScore(SDL_Surface *screen,SDL_Surface *points ,SDL_Rect pospoints ) ;



void initialisationVie(int y , TTF_Font *police ,SDL_Surface *point ,SDL_Rect posit);

void closeScoreVie(TTF_Font *police ,SDL_Surface *point);


void showScoreVie(SDL_Surface *screen,SDL_Surface *point ,SDL_Rect posit ) ;




#endif
