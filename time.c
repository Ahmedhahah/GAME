#include "time.h"




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
