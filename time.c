#include "time.h"

/**
* @file time.c
*/
#include "time.h"

/**
* @brief To initialize the time_perso t .
* @param t the time_perso
* @param x the number of player
* @return Nothing
*/
void init_time(time_perso* t, int x){
    t->police_time=TTF_OpenFont("graphic/font.ttf",24);

    t->texte_time=NULL;
    if (x==1){
        t->pos_texte_time.x=900;
        t->pos_texte_time.y=10;
      }

if (x==2){
    t->pos_texte_time.x=900;
    t->pos_texte_time.y=50;
  }
}
/**
* @brief To show the time .
* @param p the person
* @param scren the screen
* @param t the time 
* @param x the number of player
* @return Nothing
*/

void afficher_time(personnage* p,SDL_Surface* screen,time_perso* t, int x)
{SDL_Color couleur_time={143,89,34};
char char_time[50];
sprintf(char_time,"temps %d: ",x);
char perso_time[50];
  sprintf(perso_time,"%03d",p->tempsActuel/1000);
strcat(char_time,perso_time);
t->texte_time=TTF_RenderText_Solid(t->police_time,char_time,couleur_time);
  SDL_BlitSurface(t->texte_time,NULL,screen,&t->pos_texte_time);
}

/**
* @brief To check if time is over or not  .
* @param tempsActuel the actual time
* @param tempsPrecedent the previous time 
* @return int
*/

int checktime(int tempsActuel , int tempsPrecedent)
{if(tempsActuel-tempsPrecedent >=300000) //5 min
{

return 1 ;
}
}
 
/**
* @brief To save the lost time when for example game is over because SDL_GetTicks() keep going .
* @param t the time to save
* @return Nothing
*/
void save_time(int t)
{
    FILE *fichier = NULL;
    fichier = fopen("pauseTime.txt", "w");
    fprintf(fichier, "%d", t);
    fclose(fichier);
}


/**
* @brief To get the saved time from file .
* @param nothing
* @return int
*/
int get_time()
{
    int time;
    FILE *fichier = NULL;
    fichier = fopen("pauseTime.txt", "r");
    while (!feof(fichier))
        fscanf(fichier, "%d", &time);
    fclose(fichier);
    return time;
}
