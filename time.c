#include "time.h"






int timeAct(int tempsActuel) 
{tempsActuel = SDL_GetTicks();}




int checktime(int tempsActuel , int tempsPrecedent)
{if(tempsActuel-tempsPrecedent >180000)
{

printf("Time is up  \n") ;
return 1 ;
}
}
 // fel main int tempsPrecedent = 0, tempsActuel = 0 ; 9bal el while 
 // fi awel el while tempsActuel =timeAct(tempsActuel);
// fi e5er el while int t= checktime( tempsActuel,tempsPrecedent );if(t==1){done=0 ;}






void pause()
{
int pause = 1;
   SDL_Event event;

    while(pause)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
            pause = 0;
            break;

            case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                case SDLK_p:
                pause = 0;
                break;

            }
            break;

     
        }
    }


}
