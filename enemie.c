#include "enemie.h"
#include <time.h>
#include <stdlib.h>






void depaleatoire(med *enem ,SDL_Surface *screen)
{


int nbr ; 
srand(time(NULL)); 
nbr=(rand() % 4) ;
int move=1 ;
if(move==1){
switch (nbr){
case 0 :
     {
       if(enem->positionenemi.x!=0 ) {
      enem->positionenemi.x -= 50;}
       break ;}
case 1 :
     {
if(enem->positionenemi.x!=550) {
      enem->positionenemi.x += 50;}
       break ;}
case 2 :
     { 
   
if(enem->positionenemi.y!=0) {
      enem->positionenemi.y -= 50;}
      break ;}
case 3 :
     { 
  
if(enem->positionenemi.y!=300) {
      enem->positionenemi.y += 50;}
      break ;}
}
}
}

		




