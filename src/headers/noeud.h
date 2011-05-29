#ifndef DEF_NOEUD
#define DEF_NOEUD

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ville.h"
#include "Liste_ville.h"

typedef struct Noeud Noeud;

struct Noeud
{
	Ville v;
	struct Liste_Ville* Voisins_Ville;
	Noeud* Ville_Suivante;

};

int Est_Vide_noeud(Noeud *N) ;  /* Prend un Noeud* en paramètre et regarde si il est vide */

Noeud* Suivant_noeud(Noeud *N);  /* Prend un Noeud* en paramètre et renvoie le Noeud suivant */

void Ajouter_Fin(Noeud* N, Ville V);

void completion(char c[100], Noeud* N); /* Affiche les noms des villes commençant par les caractères donnés en paramètre */

int Rechercher_Noeud(Noeud* N, char id[100]);

void Remplirindice(Noeud* N);/* Ajoute des indices dans le graphe, correspondant à la position des noeuds */

float distance2(Noeud *N,int v1, int v2); /* calcule la distance entre la ville d'indice v1 et celle d'indice v2 */

struct Liste_Ville* fils(Noeud *N, int indice); /* renvoie la liste des fils du noeud N */

void Afficher_Noeud(Noeud* N,FILE* f);  /* Affiche le noeud */





#endif
