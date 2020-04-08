#ifndef ENEMIE_H_INCLUDED
#define ENEMIE_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct enemi
{       SDL_Surface *enemy;
	
        SDL_Rect positionenemi;
        int score  ;
} med ;


void depaleatoire(med *enem,SDL_Surface *screen);

#endif
