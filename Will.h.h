typedef struct Will
{
	SDL_Rect will_pos;
	int vie;
	int score;
	int pouvoir;
	SDL_Surface *image[15];
	SDL_Rect image_pos;
	SDL_Surface *image_pouvoir[15];
	SDL_Rect pouvoir_pos;
	SDL_Surface *direction_droite[15];
	SDL_Rect direction_droite;
	SDL_Surface *direction_gauche[15];
	SDL_Rect direction_gauche;
};



void init_personnage(Will *hero);
void gestion_vie_et_score(Will *p,boss *b[]);
void deplacer_personnage(Will *hero);
void afficher_personnage(Will hero ,boss *b[], med *m[],int stage,map background,wiseman w);
int collision_2_entites(Will *hero,boss *b[]);
int collision_entre_personnage_et_background(Will *hero, int stage,map background);
void animation_personage(Will *hero);
void deplacement_souris(Will *hero);
void animation_seconde_entite(Will *hero);
void scrolling(Will hero ,map background);