/**
* @file sauvegarder.c
*/
#include "sauvegarde.h"



/**
* @brief To save player settings .
* @param p the player
* @param f the file to save on
* @return Nothing
*/


void save_joueur(personnage *p,char*f)
{ int i;
    FILE *fichier =NULL;
    fichier=fopen(f,"w");
    if(fichier !=NULL)
    {
        
fprintf(fichier ,"%d %d %d %hd %hd \n", p->vie , p->score, p->tempsActuel, p->perso_pos.x, p->perso_pos.y );
 
 
    }
    else
    {
        printf("erreur");
    }
    fclose(fichier);


}

/**
* @brief To get the player settings from file f .
* @param p the player
* @param f the file
* @return Nothing
*/

void  continue_joueur(personnage *p,char*f)
{ FILE *fich=NULL;
    fich=fopen(f,"r");
     
    char ligne[100] ;
    while( fgets(ligne, sizeof(ligne), fich) != NULL )
    {
       
 sscanf(ligne ,"%d %d %d %hd %hd ", &p->vie , &p->score, &p->tempsActuel, &p->perso_pos.x, &p->perso_pos.y);
   
        
    }
    
    
  
    fclose(fich);
       
    }

/**
* @brief To save enemy settings .
* @param e the enemy
* @param f the file to save on
* @return Nothing
*/

void save_entite(entite *e,char*f )
{ int i;
    FILE *fichier =NULL;
    fichier=fopen(f,"w");
    if(fichier !=NULL)
    {
        
fprintf(fichier ,"%hd %hd \n",e->entite_pos.x, e->entite_pos.y );
 
 
    }
    else
    {
        printf("erreur");
    }
    fclose(fichier);


}
/**
* @brief To get the enemy settings from file f .
* @param e the enemy
* @param f the file
* @return Nothing
*/
void  continue_entite(entite *e,char*f)
{ FILE *fich=NULL;
    fich=fopen(f,"r");
     
    char ligne[100] ;
    while( fgets(ligne, sizeof(ligne), fich) != NULL )
    {
       
 sscanf(ligne ," %hd %hd ", &e->entite_pos.x, &e->entite_pos.y);
   
        
    }
    
    
  
    fclose(fich);
       
    }










