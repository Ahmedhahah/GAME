#include"wiseman.h"
#include"enigme.h"
void init_enigme(enigme *e[])
{
			e->question[0]=IMG_Load("graphic/q0.png");
			e->choix1[0]=IMG_Load("graphic/c01.png");
			e->choix2[0]=IMG_Load("graphic/c02.png");
			e->choix3[0]=IMG_Load("graphic/c03.png");
			e->reponse[0]=IMG_Load("graphic/rfaux.png");//response faux
			e->reponse[1]=IMG_Load("graphic/rvrai.png");//response vrai
			e->question[1]=IMG_Load("graphic/q1.png");
			e->choix1[1]=IMG_Load("graphic/c11.png");
			e->choix2[1]=IMG_Load("graphic/c12.png");
			e->choix3[1]=IMG_Load("graphic/c13.png");
			e->question[2]=IMG_Load("graphic/q2.png");
			e->choix1[2]=IMG_Load("graphic/c21.png");
			e->choix2[2]=IMG_Load("graphic/c22.png");
			e->choix3[2]=IMG_Load("graphic/c23.png");
			e->question_pos.x=100;
			e->question_pos.y=200;
			e->choix1_pos.x=100;
			e->choix1_pos.y=450;
			e->choix2_pos.x=350;
			e->choix2_pos.y=450;
			e->choix3_pos.x=600;
			e->choix3_pos.y=450;
			e->Pos_reponse.x=400;
			e->Pos_reponse.y=300;
}
void afficher_enigme(enigme *e[] ,int stage,map background,wiseman w)
{
	map->background[10]=IMG_Load("graphic/benigme.g");
	w->image[10]=IMG_Load("graphic/wiseman.png");
	w->wiseman_pos.x=450;
	w->wiseman_pos.y=100;
	SDL_BlitSurface(map->background[10],NULL,screen,NULL);
	SDL_BlitSurface(e->question[stage],NULL,screen,&question_pos);
	SDL_BlitSurface(e->choix1[stage],NULL,screen,&choix2_pos);
	SDL_BlitSurface(e->choix2[stage],NULL,screen,&choix3_pos);
	SDL_BlitSurface(e->choix3[stage],NULL,screen,&choix3_pos);
	SDL_BlitSurface(w->wiseman[10],NULL,screen,&wiseman_pos);
	SDl_flip(screen);
}
void resolution_enigme(enigme *e[],int stage)
{
	SDL_Event event;
	switch(event.type)
	{
	case SDL_MOUSEBUTTONUP:
	if ((100<=event.button.x && event.button.x<=300)&&(450<=event.button.y && event.button.y<=500)&& stage==0)
	{
		SDL_BlitSurface(e->question[stage],NULL,screen,&question_pos);
		SDL_BlitSurface(w->wiseman[10],NULL,screen,&wiseman_pos);
      	SDL_BlitSurface(e->reponse[0],NULL,screen,&Pos_reponse);
      	SDL_Flip(screen);
	}
	else if ((350<=event.button.x && event.button.x<=450)&&(450<=event.button.y && event.button.y<=500)&& stage==0)
	{
		SDL_BlitSurface(e->question[stage],NULL,screen,&question_pos);
		SDL_BlitSurface(w->wiseman[10],NULL,screen,&wiseman_pos);
      	SDL_BlitSurface(e->reponse[0],NULL,screen,&Pos_reponse);
      	SDL_Flip(screen);
	}
	else if ((600<=event.button.x && event.button.x<=800)&&(450<=event.button.y && event.button.y<=500)&& stage==0)
	{
		SDL_BlitSurface(e->question[stage],NULL,screen,&question_pos);
		SDL_BlitSurface(w->wiseman[10],NULL,screen,&wiseman_pos);
      	SDL_BlitSurface(e->reponse[1],NULL,screen,&Pos_reponse);
      	SDL_Flip(screen);
	}
	else if ((100<=event.button.x && event.button.x<=300)&&(450<=event.button.y && event.button.y<=500)&& stage==1)
	{
		SDL_BlitSurface(e->question[stage],NULL,screen,&question_pos);
		SDL_BlitSurface(w->wiseman[10],NULL,screen,&wiseman_pos);
      	SDL_BlitSurface(e->reponse[0],NULL,screen,&Pos_reponse);
      	SDL_Flip(screen);
	}
	else if ((350<=event.button.x && event.button.x<=450)&&(450<=event.button.y && event.button.y<=500)&& stage==1)
	{
		SDL_BlitSurface(e->question[stage],NULL,screen,&question_pos);
		SDL_BlitSurface(w->wiseman[10],NULL,screen,&wiseman_pos);
      	SDL_BlitSurface(e->reponse[1],NULL,screen,&Pos_reponse);
      	SDL_Flip(screen);
	}
	else if ((600<=event.button.x && event.button.x<=800)&&(450<=event.button.y && event.button.y<=500)&& stage==1)
	{
		SDL_BlitSurface(e->question[stage],NULL,screen,&question_pos);
		SDL_BlitSurface(w->wiseman[10],NULL,screen,&wiseman_pos);
      	SDL_BlitSurface(e->reponse[0],NULL,screen,&Pos_reponse);
      	SDL_Flip(screen);
	}
	else if ((100<=event.button.x && event.button.x<=300)&&(450<=event.button.y && event.button.y<=500)&& stage==2)
	{
		SDL_BlitSurface(e->question[stage],NULL,screen,&question_pos);
		SDL_BlitSurface(w->wiseman[10],NULL,screen,&wiseman_pos);
      	SDL_BlitSurface(e->reponse[0],NULL,screen,&Pos_reponse);
      	SDL_Flip(screen);
	}
	else if ((350<=event.button.x && event.button.x<=450)&&(450<=event.button.y && event.button.y<=500)&& stage==2)
	{
		SDL_BlitSurface(e->question[stage],NULL,screen,&question_pos);
		SDL_BlitSurface(w->wiseman[10],NULL,screen,&wiseman_pos);
      	SDL_BlitSurface(e->reponse[0],NULL,screen,&Pos_reponse);
      	SDL_Flip(screen);
	}
	else if ((600<=event.button.x && event.button.x<=800)&&(450<=event.button.y && event.button.y<=500)&& stage==3)
	{
		SDL_BlitSurface(e->question[stage],NULL,screen,&question_pos);
		SDL_BlitSurface(w->wiseman[10],NULL,screen,&wiseman_pos);
      	SDL_BlitSurface(e->reponse[1],NULL,screen,&Pos_reponse);
      	SDL_Flip(screen);
	}
	}
}
