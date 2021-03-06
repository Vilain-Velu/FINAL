#ifndef DEF_LISTE_VILLE
#define DEF_LISTE_VILLE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ville.h"
#include "noeud.h"

typedef struct Liste_Ville Liste_Ville;

struct Liste_Ville
{
	Ville v;
	Liste_Ville* Ville_Suivant;
	float dist;
};

Liste_Ville* Suivant(Liste_Ville *L);  /* Prend en paramètre un pointeur sur Liste_Ville et renvoie la ville qui suit Liste_Ville */

int Est_Vide(Liste_Ville *L);  /* Prend en paramètre un pointeur sur Liste_Ville et regarde si celui-ci est vide */

int Nb_Ville(Liste_Ville *L); /* Prend en paramètre un pointeur sur Liste_Ville et renvoie le nombre de ses voisins */

void Afficher_voisins(Liste_Ville* L,FILE* f);  /* Prend en paramètre un pointeur sur Liste_Ville et renvoie la liste de ses voisins */

Liste_Ville* Ajouter_Fin_voisins(Liste_Ville *L, Ville V, float dist);

Liste_Ville* Ajouter_debut_voisins(Liste_Ville* L, Ville V,float dist);





#endif
