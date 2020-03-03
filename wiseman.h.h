typedef struct wiseman //Enigme
{
	SDL_Rect wiseman_pos;
	SDL_Surface *image[15];
        
};



void init_enigme(enigme *e[]);
int temps_jeu_et_enigmes();
void resolution_enigme(enigme *e[]);
void enigme_aleatoire(enigme *e[]);
void reponse_enigme(enigme *e[]);