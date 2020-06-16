/**
* @file sauvegarde.h
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 01, 2015
*
* structure perso
*
*/
#ifndef SAUVEGARDE_H_INCLUDED
#define SAUVEGARDE_H_INCLUDED


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



void save_joueur(personnage *p,char*f ); 

void  continue_joueur(personnage *p,char*f);

void save_entite(entite *e,char*f );

void  continue_entite(entite *e,char*f);




  #endif //
