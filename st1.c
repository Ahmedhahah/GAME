
#include "st1.h"


int stage1(SDL_Surface *screen)
{
        TTF_Init();
        background b;
        initialiserr(&b);

//chrono
//float temps_jeu=50,temps_rest;

//determiner fps
Uint32 t_dep,t_fin,dt=1;
int fps=30;

int a=1,a2=1; //enregistre le retour de la gestion vie et score

int accelere=0;

int touch_down=0;

        personnage p;
        entite e;
        initialiser_entite(&e);
        initialiser(&p,1);
        personnage p2;
      //  initialiser(&p2,2);
        //CREATION TEXTE

        TTF_Font *police = NULL;
        police = TTF_OpenFont("graphic/font.ttf", 40);
        SDL_Color couleur = {255, 255, 255}; //red green blue
        SDL_Surface *texte = NULL;
        texte = TTF_RenderText_Solid(police, "stage 1", couleur); //texte yetbadal solid //shaded texte mayetbadalech fon uni// blanded texte mayetbadalech fond image barcha couleurs

        //pos texte
        SDL_Rect texte_pos;
        texte_pos.x = 50;
        texte_pos.y = 30;

vie_perso val_vie;
init_vie(&val_vie,1);
//vie_perso val_vie2;
//init_vie(&val_vie2,2);
score_perso val_score;
init_score(&val_score,1);
//score_perso val_score2;
//init_score(&val_score2,2);



int xmouse,ymouse;
int mvt_perso_arriere=0,mvt_perso_avant=0;
int type_mvt=-1;//1-> droite | 2->gauche | 3->saut

        SDL_EnableKeyRepeat(200, 0);
        SDL_Event event;

        int done = 1;
        while (done)
        {
t_dep=SDL_GetTicks();

//update chrono
//temps_rest=temps_jeu-(float)SDL_GetTicks()/1000;
//printf("%0.2f\n", temps_rest);


update_point_collision(&p);
//update_point_collision(&p2);

p.stable=1;
p2.stable=1;

                if (SDL_PollEvent(&event)) // ki ninzel ala ay haja
                {
                        switch (event.type) //tal9a type el 7aja
                        {

                        case SDL_QUIT: //nenzel 3al (X) el 7amra
                                done = 0;
                                break;
/*
//souris
case SDL_MOUSEMOTION:
SDL_GetMouseState(&xmouse,&ymouse);
break;

case SDL_MOUSEBUTTONDOWN:
mvt_perso_avant=1;
mvt_perso_arriere=1;
break;
*/
                        //avec clavier
                        case SDL_KEYDOWN:                     // ay haja fil clav
                                switch (event.key.keysym.sym) // taref type l haja l nzalt alaha fil clav
                                {

                                case SDLK_ESCAPE: //echap
                                        done = 0;
                                        break;
                                case SDLK_RIGHT: //flech right
                                apply_acceleration(&p,dt);
                                if (scrol_right(&b, screen,&p,&e))
                                mvt_perso_droite(&p);
                                        break;

                                case SDLK_LEFT: //flech left
                                      apply_acceleration(&p,dt);
                                      if (scrol_left(&b, screen,&p,&e))
                                       mvt_perso_gauche(&p);
                                        break;
                                case SDLK_UP: //flech fou9
                                    jump_perso(&p);
                                        break;

                                        case SDLK_a: //acceleration
                                        p.acceleration++;
                                      break;

/*
                                        case SDLK_d: //flech right
                                        if (scrol_right(&b, screen,&p2))
                                      mvt_perso_droite(&p2,mvtx);
                                      break;

                                        case SDLK_q: //flech left
                                        if (scrol_left(&b, screen))
                                        mvt_perso_gauche(&p2,mvtx);
                                                break;
                                        case SDLK_z: //flech fou9
                                          jump_perso(&p2);
                                                break;
*/
                                }
                        } //fin switch
                } //fin if





/*
//mvt souris
if(mvt_perso_avant){//avancer
if(p.perso_pos.x+100<xmouse)     mvt_perso_droite_souris(&p,xmouse);
else  mvt_perso_avant=0;
  }

if(mvt_perso_arriere){  //reculer
if(p.perso_pos.x>xmouse)     mvt_perso_gauche_souris(&p,xmouse);
else  mvt_perso_arriere=0;
  }
*/

//collision parfaite avec background
update_perfect_collision(&p,&b);
//update_perfect_collision(&p2,&b);

//mise a jour entite
mise_a_jour_entite(&e,p.perso_pos.x);

//gestion vie et score apres collision avec entite
e.col=0;
if(detect_collision(&p, &e))         a=gestion_vie_score(&p,&e,&b);
/*
e.col=0;
if(detect_collision(&p2, &e))  a2=gestion_vie_score(&p2,&e,&b);
*/

//animation stable perso
if (p.stable==1)   {
anim_stable(&p);
p.mvtx=3;
}
//if (p2.stable==1)    anim_stable(&p2);


affiche_back(&b, screen);

if(a)     afficher_entite(&e,screen);

afficher_vie_score(&p,screen,&val_score,&val_vie,1);
//afficher_vie_score(&p2,screen,&val_score2,&val_vie2,2);

afficher_perso(&p, screen);
//afficher_perso(&p2, screen);

SDL_BlitSurface(texte, NULL, screen, &texte_pos);
SDL_Flip(screen);

printf("%d\t%f\n",p.acceleration,p.mvtx );

if (gameover(&p))  done=0;
//if (gameover(&p2))   done=0;

//determiner fps
t_fin=SDL_GetTicks();
dt=t_fin-t_dep;
if (1000/fps>dt) SDL_Delay (1000/fps-dt);

        } //fin while

        SDL_FreeSurface(b.back);
        SDL_FreeSurface(p.perso);
        SDL_FreeSurface(texte);
        TTF_CloseFont(police);
        TTF_Quit();

} //fin fct
