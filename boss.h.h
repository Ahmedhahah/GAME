typedef struct boss
{
	SDL_Rect boss_pos;
	SDL_Surface *image[15];
	SDL_Rect pouvoir_pos;
	SDL_Surface *image_pouvoir[15];
	int vie;
	int pouvoir;
};

void init_seconde_entite(med *m[],boss *b[],wiseman *w);
void afficher_seconde_entite(med m[],boss b[],wiseman w,map background);
int collision_2_entites(Will *hero,boss *b[]);
void deplacement_aleatoire(boss *b[]);
void animation_seconde_entite(Will *boss);