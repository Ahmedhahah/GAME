typedef struct enigme
{
	int time;
	SDL_Rect question_pos;
	SDL_Surface *question[15];
	SDL_Rect choix1_pos;
	SDL_Surface *choix1[15];
	SDL_Rect choix2_pos;
	SDL_Surface *choix2[15];
	SDL_Rect choix3_pos;
	SDL_Surface *choix3[15];
        SDl_Rect   Pos_reponse; 
        SDL_Surface *reponse[3] ;
    

      
};
void init_enigme(enigme *e[]);
void afficher_enigme(enigme *e[] ,int stage,map background,wiseman w);
int temps_jeu_et_enigmes();
void resolution_enigme(enigme *e[]);
void enigme_aleatoire(enigme *e[]);
void reponse_enigme(enigme *e[]);

