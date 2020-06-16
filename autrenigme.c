#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "autrenigme.h"


int autre_enigme(SDL_Surface *screen)
{

    int hb = 100, //3olw boutton
        lb = 300, //3orth boutton
        bs = 30;  // espace bin les bouttons
    int f = 0;

    Mix_Chunk *music1;
    Mix_AllocateChannels(1);

    music1 = Mix_LoadWAV("graphic/ClicDeSouris.wav");

    int tmp = 0, m = 0;

    //creation background
    SDL_Surface *background = NULL;
    background = IMG_Load("graphic/background1.jpg");
    // detreminerr pos de back
    SDL_Rect background_pos;
    background_pos.x = 0;
    background_pos.y = 0;

    //creation bouton reponse1
    SDL_Surface *reponse1[3];
    reponse1[0] = IMG_Load("graphic/reponse1.0.png");
    reponse1[1] = IMG_Load("graphic/reponse1.1.png");
    reponse1[2] = IMG_Load("graphic/reponse1.2.png");
    int ng = 0;
    //pos buton reponse1
    SDL_Rect reponse1_pos;
    reponse1_pos.x = 100;
    reponse1_pos.y = 50;

    //creation bouton reponse2
    SDL_Surface *reponse2[3];
    reponse2[0] = IMG_Load("graphic/reponse2.0.png");
    reponse2[1] = IMG_Load("graphic/reponse2.1.png");
    reponse2[2] = IMG_Load("graphic/reponse2.2.png");
    int cr = 0;
    //pos buton reponse2
    SDL_Rect reponse2_pos;
    reponse2_pos.x = 100;
    reponse2_pos.y = reponse1_pos.y + hb + bs;

    //creation bouton reponse3
    SDL_Surface *reponse3[3];
    reponse3[0] = IMG_Load("graphic/reponse3.0.png");
    reponse3[1] = IMG_Load("graphic/reponse3.1.png");
    reponse3[2] = IMG_Load("graphic/reponse3.2.png");
    int op = 0;
    //pos buton reponse3
    SDL_Rect reponse3_pos;
    reponse3_pos.x = 100;
    reponse3_pos.y = reponse2_pos.y + hb + bs;

    // detreminerr pos de bravo
	SDL_Surface *img = NULL;
    SDL_Rect bravo_pos;

    int t1 = 0, t2 = 0, r = 0;
    //SDL_Surface *img = NULL;

    int t = 0;
    SDL_Event event;
    int done = 1;
    while (done)
    {

        //afficher back

        t = 0;
        if (SDL_PollEvent(&event)) // ki ninzel ala ay haja
        {
            switch (event.type) //tal9a type el 7aja
            {
            ////////////////////////////////////////////////////////////////////////////////////////////////////////
            ////////////////////////////////////////////////////////////////////////////////////////////////////////
            case SDL_QUIT: //nenzel 3al (X) el 7amra
                done = 0;
                break;
            ////////////////////////////////////////////////////////////////////////////////////////////////////////
            ////////////////////////////////////////////////////////////////////////////////////////////////////////
            //avec clavier
            case SDL_KEYDOWN:                 // ay haja fil clav
                switch (event.key.keysym.sym) // taref type l haja l nzalt alaha fil clav
                {
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                case SDLK_q: //q
                    done = 0;
                    break;
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                case SDLK_UP: //flech fou9ani
                    if (ng == 0 && cr == 0 && op == 0)
                    {
                        ng = 1;
                    }
                    else if (ng == 1 && t == 0)
                    {

                        ng = 0;
                        cr = 0;
                        op = 0;
                        t = 1;
                    }
                    else if (cr == 1 && t == 0)
                    {
                        ng = 1;
                        cr = 0;
                        op = 0;

                        t = 1;
                    }
                    else if (op == 1 && t == 0)
                    {
                        ng = 0;
                        cr = 1;
                        op = 0;

                        t = 1;
                    }

                    break;
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                case SDLK_DOWN: //flech loutani
                    if (ng == 0 && cr == 0 && op == 0)
                    {
                        ng = 1;
                    }
                    else if (ng == 1 && t == 0)
                    {

                        ng = 0;
                        cr = 1;
                        op = 0;
                        t = 1;
                    }
                    else if (cr == 1 && t == 0)
                    {
                        ng = 0;
                        cr = 0;
                        op = 1;

                        t = 1;
                    }
                    else if (op == 1 && t == 0)
                    {
                        ng = 1;
                        cr = 0;
                        op = 0;

                        t = 1;
                    }

                    break;
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                case SDLK_RETURN: //entree
                    if (ng == 1)
                    {
//bravo_pos.x =200;
  //                  bravo_pos.y = 200;
img = IMG_Load("bravo.jpg");////
                        SDL_BlitSurface(reponse1[2], NULL, screen, &reponse1_pos);
                        
                        p->score=p->score+100;
    //                SDL_BlitSurface(img, NULL, screen, &bravo_pos);
			SDL_Flip(screen);

                        return 1;
                    }
                    else if (cr == 1)
                    {
//bravo_pos.x =200;
  //                  bravo_pos.y = 200;
img = IMG_Load("faux.jpg");///
p->score=p->score-100;
                        SDL_BlitSurface(reponse2[2], NULL, screen, &reponse2_pos);
                        
                        
                        
                        
    //                SDL_BlitSurface(img, NULL, screen, &bravo_pos);
			SDL_Flip(screen);


                        return 3;
                    }
                    else if (op == 1)
                    {
//bravo_pos.x =200;
  //                  bravo_pos.y = 200;
img = IMG_Load("faux.jpg");///
                        SDL_BlitSurface(reponse3[2], NULL, screen, &reponse3_pos);
                        
                        p->score=p->score-100;
                        
    //                SDL_BlitSurface(img, NULL, screen, &bravo_pos);
			SDL_Flip(screen);

                        return 2;

		    
                    }
			bravo_pos.x =200;
                    bravo_pos.y = 200;
                    SDL_BlitSurface(img, NULL, screen, &bravo_pos);

                    break;
                }
                break;
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                ////////////////////////////////////////////////////////////////////////////////////////////////////////

            //avec souris
            case SDL_MOUSEMOTION:

                ng = 0;
                cr = 0;
                op = 0;
                if (event.motion.x > reponse1_pos.x && event.motion.y > reponse1_pos.y && event.motion.x < reponse1_pos.x + lb && event.motion.y < reponse1_pos.y + hb)
                {
                    ng = 1;
                }
                else if (event.motion.x > reponse2_pos.x && event.motion.y > reponse2_pos.y && event.motion.x < reponse2_pos.x + lb && event.motion.y < reponse2_pos.y + hb)
                {
                    cr = 1;
                }
                else if (event.motion.x > reponse3_pos.x && event.motion.y > reponse3_pos.y && event.motion.x < reponse3_pos.x + lb && event.motion.y < reponse3_pos.y + hb)
                {
                    op = 1;
                }

                break;

           /* case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (ng == 1)
                    {
                        printf("heyyyy");
                        ng = 2;
                        Mix_PlayChannel(1, music1, 0);
                        SDL_Delay(500);

                        //img = IMG_Load("bravo.jpg");
                    }
                    else if (cr == 1)
                    {
                        cr = 2;
                        Mix_PlayChannel(1, music1, 0);
                        SDL_Delay(500);

                        //img = IMG_Load("faux.jpg");
                    }
                    else if (op == 1)
                    {
                        op = 2;
                        Mix_PlayChannel(1, music1, 0);
                        SDL_Delay(500);

                        //img = IMG_Load("faux.jpg");
                    }
                    //bravo_pos.x =200;
                    //bravo_pos.y = 200;
                    //SDL_BlitSurface(img, NULL, screen, &bravo_pos);

                    
                }
                break;*/

            } //fin switch event
        }     //fin pollevent
	//SDL_BlitSurface(img, NULL, screen, &bravo_pos);
        SDL_BlitSurface(background, NULL, screen, &background_pos);

        SDL_BlitSurface(reponse1[ng], NULL, screen, &reponse1_pos);

        SDL_BlitSurface(reponse2[cr], NULL, screen, &reponse2_pos);

        SDL_BlitSurface(reponse3[op], NULL, screen, &reponse3_pos);
//SDL_BlitSurface(img, NULL, screen, &bravo_pos);
        SDL_Flip(screen);
    } //fin while

    //Mix_FreeChunk(music1);
    SDL_FreeSurface(background);
	SDL_FreeSurface(img);
    SDL_FreeSurface(reponse1[2]);
    SDL_FreeSurface(reponse2[2]);
    SDL_FreeSurface(reponse3[2]);
    SDL_FreeSurface(reponse1[0]);
    SDL_FreeSurface(reponse1[1]);
    SDL_FreeSurface(reponse3[0]);
    SDL_FreeSurface(reponse3[1]);
    SDL_FreeSurface(reponse2[0]);
    SDL_FreeSurface(reponse3[1]);
}

void main()
{
    SDL_Surface *screen = NULL;
    screen = SDL_SetVideoMode(852, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    autre_enigme(screen);
}
