#ifndef DEF_VILLE
#define DEF_VILLE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define pi 3.14159265358979323846

typedef struct Ville Ville;
struct Ville
{
	char Nom[100];
	int Hbts;
	float C1;
	float C2;
	int indice;

};

void Afficher_Ville(Ville v,FILE* f); /* Prend une ville en paramètre et affiche ses différentes caractéristiques */

float conversion_coordonnee (char *c); /* convertit une coordonnée de type caractère 00.00000A en une coordonnée de type float */

float distance(Ville v1,Ville v2); /* calcule la distance entre 2 villes */

float deg2rad(float deg);  /* convertit des degré en radian */

float rad2deg(float rad); /* convertit des radian en degré */


#endif

