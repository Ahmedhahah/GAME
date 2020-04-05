#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//1s=1000 
//30 min =1800000

int tempsPrecedent = 0, tempsActuel = 0 ; // hedhi te7at fi awel el main

tempsActuel = SDL_GetTicks(); // tet7at ba3d el while 
 if(tempsActuel-tempsPrecedent >1800000) // tet7at fi e5er el while
{done=0;

printf("Time is up  \n") ;
}

void pause();

#endif
