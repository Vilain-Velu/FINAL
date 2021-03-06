#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "noeud.h"
#include "graphe.h"
#include "kruskal.h"


void menu(Noeud* N,int Nb);  /* gère le menu du programme */

void Generateur_HTML (char * html, Noeud* No, int N);  /* remplit un fichier HTML avec les N plus grandes villes */

void Generateur_HTML2 (char * html,Noeud*N, int Nb, int ant[Nb][2],int indicev1, int indicev2); /* remplit un fichier HTML en indiquant le plus court chemin 																									   entre deux villes */
void Generateur_HTML3 (char * html,Noeud* N, int Nb, Arbre* A);
