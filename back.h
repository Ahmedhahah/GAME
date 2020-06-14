#ifndef back_H_INCLUDED
#define back_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"
#include "entite.h"

typedef struct {
SDL_Surface *back ;
SDL_Surface *mask;
SDL_Rect back_pos;
SDL_Rect back_pos_relative;
SDL_Rect camera ; //t9os partie ml background w t7otha fl fenetre
}background ;

void initialiserr (background *b) ;
int scrol_right(background *b, SDL_Surface *screen, personnage *p, entite *e);
int scrol_left(background *b, SDL_Surface *screen, personnage *p, entite *e);
void affiche_back(background *b, SDL_Surface *screen);




#endif
