
/**
* @file time.h
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 01, 2015
*
* structure perso
*
*/
#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "perso.h"

/**
* @struct time_perso
* @brief struct for time
*/
typedef struct
{
  
  TTF_Font* police_time;
  SDL_Surface *texte_time;  /*!< Surface. */
  SDL_Rect pos_texte_time; /*!< Rectangle*/

} time_perso;

void init_time(time_perso* t,int x);

void afficher_time(personnage *p, SDL_Surface *screen, time_perso *t, int x);

void save_time(int t) ;

int get_time() ;

int checktime(int tempsActuel , int tempsPrecedent);



#endif
