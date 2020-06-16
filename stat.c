/**
* @file stat.c
*/
#include "stat.h"

/**
* @brief To initialize the vie_perso v .
* @param v the vie_perso
* @param x the number of player
* @return Nothing
*/
void init_vie(vie_perso* v, int x){
    v->police_vie=TTF_OpenFont("graphic/font.ttf",32);

    v->texte_vie=NULL;
    if (x==1){
        v->pos_texte_vie.x=350;
        v->pos_texte_vie.y=10;
      }

if (x==2){
    v->pos_texte_vie.x=350;
    v->pos_texte_vie.y=50;
  }
}

/**
* @brief To initialize the score_perso s .
* @param s score_perso
* @param x the number of player
* @return Nothing
*/
void init_score(score_perso* s, int x){
    s->police_score=TTF_OpenFont("graphic/font.ttf",32);

    s->texte_score=NULL;
    if (x==1){
    s->pos_texte_score.x=550;
    s->pos_texte_score.y=10;
  }

    if (x==2){
    s->pos_texte_score.x=550;
    s->pos_texte_score.y=50;
  }
}

/**
* @brief To show the score .
* @param p the personnage
* @param screen 
* @param s the score_perso
* @param x the number of player
* @return Nothing
*/
void afficher_score(personnage* p,SDL_Surface* screen,score_perso* s, int x)
{SDL_Color couleur_score={143,89,34};
char char_score[50];
sprintf(char_score,"score %d : ",x);
  char perso_score[50];
  sprintf(perso_score,"%06d",p->score);
strcat(char_score,perso_score);
  s->texte_score=TTF_RenderText_Solid(s->police_score,char_score,couleur_score);
  SDL_BlitSurface(s->texte_score,NULL,screen,&s->pos_texte_score);
}

/**
* @brief To show vie .
* @param p the personnage
* @param screen 
* @param v the vie_perso
* @param x the number of player
* @return Nothing
*/
void afficher_vie(personnage* p,SDL_Surface* screen,vie_perso* v, int x)
{SDL_Color couleur_vie={143,89,34};
  char char_vie[50];
  sprintf(char_vie,"vie %d : ",x);
  char perso_vie[50];
  sprintf(perso_vie,"%02d",p->vie);
  strcat(char_vie,perso_vie);
  v->texte_vie=TTF_RenderText_Solid(v->police_vie,char_vie,couleur_vie);
  SDL_BlitSurface(v->texte_vie,NULL,screen,&v->pos_texte_vie);
}

/**
* @brief To show vie and score .
* @param p the personnage
* @param screen
* @param s score_perso
* @param v the vie_perso
* @param x the number of player
* @return Nothing
*/
void afficher_vie_score(personnage *p, SDL_Surface *screen, score_perso *s, vie_perso *v, int x)
{
afficher_vie(p,screen,v,x);
afficher_score(p,screen,s,x);
}

/**
* @brief To manage the number of vie and score .
* @param p the personnage
* @param e the entite
* @param b the background
* @return int
*/
int gestion_vie_score(personnage *p, entite *e,background *b)
{

//disappear after collision
  if (e->type==0){
    p->vie++;
    e->entite_pos.y=100;
    e->maxdown=150;
    return 0;//ne pas afficher entite
  }

  if (e->type==2){
    p->score+=200;

  e->entite_pos.y=100;
  e->maxdown=150;
  return 0;//ne pas afficher entite
}
  //stay after collision
  if (e->type==1){
    p->vie--;
    p->perso_pos.x=30;
    p->perso_pos.y=460;
    p->perso_pos_relative.x=30;
    p->perso_pos_relative.y=460;
    b->camera.x=0;
    b->camera.y=0;
    b->back_pos_relative.y-=0;
    b->back_pos_relative.x-=0;
      return 1;//afficher entite
  }



  if (e->type==3){
  p->score-=100;

  if(p->perso_pos.x<= e->entite_pos.x) p->perso_pos.x-=150;
  if(p->perso_pos.x>= e->entite_pos.x) p->perso_pos.x+=150;
    return 1;//afficher entite
}

}






