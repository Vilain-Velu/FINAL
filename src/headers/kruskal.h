#ifndef DEF_ARBRE
#define DEF_ARBRE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphe.h"

typedef struct Arbre Arbre;

struct Arbre
	{
	Ville V1;
	Ville V2;
	float dist;
	Arbre* Suivant;
	};

typedef struct Liste Liste;

struct Liste
	{
	int val;
	Liste* Suivant;
	};



void Inserer_trier(Arbre* A, Ville V1, Ville V2, float dist);

Arbre* RemplirArbre(Arbre* A,Noeud* N, int M); 

Arbre* Ajouter_debut(Arbre* A, Ville V1,Ville V2,float dist);

void initialisation_Mat(int Nb, float Mat[Nb][Nb]);

Liste* Inserer(Liste* Li, int j);

Liste* Voisin(int N, float Mat[N][N], int i);

int SS_circuit_prof(int N, float Mat[N][N], int i, int etat[N]);

void initialiser_etat(int Nb, int etat[Nb]);

int sans_circuit2(int N, float Mat[N][N],int i, int etat[N]);

int Est_sans_circuit2(int N, float Mat[N][N]);

Arbre* Ligne(Arbre* A,int N);

Liste* Ajouter_fin(Liste *L, int i);

Arbre* quick_sort (Arbre* list);

Arbre* _quick_sort (Arbre* L1, Arbre* end);

#endif
