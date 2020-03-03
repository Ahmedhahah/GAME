#ifndef FONCTIONS_H_
#define FONCTIONS_H_
typedef struct map
{
	SDL_Rect map_pos;
	SDL_Surface *image[15];
};
void afficher_seconde_entite(med m[],boss b[],wiseman w,map background);
void afficher_enigme(enigme *e[] ,int stage,map background,wiseman w);
void afficher_personnage(Will hero ,boss *b[], med *m[],int stage,map background,wiseman w);
int collision_entre_personnage_et_background(Will *hero, int stage,map background);
void scrolling(Will hero ,map background);
#endif
