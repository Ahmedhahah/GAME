
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

/**
* @struct Question
* @brief struct for question
*/
typedef struct Question {
	char question[255];/*!< question*/
	char reponse1[255];/*!< response1*/
	char reponse2[255];/*!< response2*/
	char reponse3[255];/*!< response3*/
} Question;

/**
* @struct Enigme
* @brief tableau de questions
*/
typedef struct Enigme {
	FILE *f;/*!< fichier*/
	Question questions[50];/*!< question*/
} Enigme;

void enigme_Init(Enigme *q,char* filename);

