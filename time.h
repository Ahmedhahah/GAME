#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// pour la gestion de temps en main ; on va utiliser SDL_WM_SetCaption("Gestion du temps en SDL", NULL); int tempsPrecedent = 0, tempsActuel = 0 ;tempsActuel = SDL_GetTicks()  ; if(tempsActuel-tempsPrecedent >10){}

void pause();

#endif
