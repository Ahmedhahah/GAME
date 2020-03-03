typedef struct med
{
	SDL_Rect med_pos;
	SDL_Surface *image[15];
        int score = 10 ;
};
void afficher_personnage(Will hero ,boss *b[], med *m[],int stage,map background,wiseman w);
void init_seconde_entite(med *m[],boss *b[],wiseman *w);
void afficher_seconde_entite(med m[],boss b[],wiseman w,map background);