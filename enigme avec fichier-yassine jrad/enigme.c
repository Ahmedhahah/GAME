#include"enigme.h"

/**
* @file enigme.c
* @brief initialisation de l'énigme
* @author Yassine Jrad
* @version 2.0
* @date June ,12 2020
*
* initialisation de l'énigme avec fichier 
*
*/
/**
* @brief lire la question et les reponses a partir du fichier dédié
* @param t structure de type Enigme
* @param filename c'est le nom du fichier
* @return rien
*/
void enigme_Init(Enigme *q, char* filename) {
	q->f = fopen(filename,"r");
	for(int i = 0; i<10; i++){
		char a[255];
		fgets(a, sizeof(a),q->f);
		strcpy(q->questions[i].question,a);
		fgets(a, sizeof(a),q->f);
		strcpy(q->questions[i].reponse1,a);
		fgets(a, sizeof(a),q->f);
		strcpy(q->questions[i].reponse2,a);
		fgets(a, sizeof(a),q->f);
		strcpy(q->questions[i].reponse3,a);
	}

	fclose(q->f);
}
