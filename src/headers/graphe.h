#ifndef DEF_GRAPHE
#define DEF_GRAPHE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "noeud.h"
#include <math.h>


void Afficher_Graphe(Noeud* N, int Nbnoeuds);  /* prend un noeud* en paramètre et affiche le graphe */

void Afficher_Graphe_sans_voisin (Noeud* N,int Nbnoeuds);  /* prend un noeud* en paramètre et affiche les villes, sans leurs voisins */

void generer_graphe(Noeud* N);   /* Prend un Noeud* en paramètre et génère la liste des voisins de chaque ville  */

int PCC (Noeud* N, int Nb, char v1[100], char v2[100],int ant[Nb][2],float poids[Nb][3]); /* calcule le Plus Court Chemin entre deux villes */

int indice(Noeud* N, char c[100]);  /* renvoie l'indice correspondant au nom de la ville donné en paramètre */

char* nom(Noeud* N, int id); /* renvoie le nom de la ville correspondant à l'indice donné en paramètre */

int indicevoisin(Noeud* N, char c[100]);  /* renvoie l'indice de la ville voisine */

int indice_poids_plus_faible_np(int Nb, float poids[Nb][3]);  /*utilisée dans la fonction PCC, np = Non parcouru  */

int indice_poids_plus_faible(int Nb, float poids[Nb][3]);  /* utilisée dans la fonction PCC  */

float c1_indice(int i, Noeud* N); /* renvoie la coordonnée 1 de la ville d'indice i  */

float c2_indice(int i, Noeud* N);  /* renvoie la coordonnée 2 de la ville d'indice i  */

void Villesnecessaire (Noeud* N, int Nb ,int ant[Nb][2],int VD, int VA,int tab[1000]); /* renvoie un tableau contenant les villes nécessaires c'est à dire les villes dans lesquelles le petit avion doit absolument s'arrêter pour faire le plein de kérosène */  /* utilisée dans générer HTML2 */



#endif
