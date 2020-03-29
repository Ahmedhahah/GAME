#include "score.h"



void initTTF()
{TTF_Init();
 if(TTF_Init()==-1) 
             {fprintf(stderr ,"Can not to open Font : %s\n", TTF_GetError());
		exit(EXIT_FAILURE) ;}
}


void closeScore(TTF_Font *font ,SDL_Surface *points)
{
TTF_CloseFont(font) ;
TTF_Quit();
SDL_FreeSurface(points);
}





void initialisationScore(int x , TTF_Font *font ,SDL_Surface *points ,SDL_Rect pospoints){
 
 
 pospoints.x=0;
 pospoints.y=40;

font = TTF_OpenFont("Space.ttf", 56);
 SDL_Color color;
        color.r = 0 ;
        color.g = 0 ;
        color.b = 0 ;
char score[100]=" ";

 sprintf (score,"%.2d:score",x) ;

points=TTF_RenderText_Solid(font ,score, color);
}




void showScore(SDL_Surface *screen,SDL_Surface *points ,SDL_Rect pospoints )
{
       
SDL_BlitSurface(points,NULL,screen,&pospoints);

SDL_Flip(screen);
}




void initialisationVie(int y , TTF_Font *police ,SDL_Surface *point ,SDL_Rect posit)
{
 

 posit.x=0;
 posit.y=40;
police = TTF_OpenFont("Poopy.ttf" , 56);
 SDL_Color collor;
        collor.r = 255 ;
        collor.g = 0 ;
        collor.b = 255 ;
char nombrevie[100]=" ";

 sprintf (nombrevie,"%.2d: vie",y) ;

point=TTF_RenderText_Solid(police ,nombrevie, collor);




}






void closeScoreVie(TTF_Font *police ,SDL_Surface *point){

SDL_FreeSurface(point);
TTF_CloseFont(police) ;

}


void showScoreVie(SDL_Surface *screen,SDL_Surface *point ,SDL_Rect posit ) 
{
SDL_BlitSurface(point,NULL,screen,&posit);

SDL_Flip(screen);}






