#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../headers/ville.h"
#include "../headers/noeud.h"
#include "../headers/Liste_ville.h"
#include "../headers/graphe.h"
#include "../headers/menu.h"

int Nbnoeuds=1;

int main (int argc, char *argv[])
{
	FILE * f = NULL;

	int i;
	Ville v;
	/*Graphe* G=NULL;*/
	Noeud* N=NULL;
	N = (Noeud*)malloc(sizeof(Noeud));
	int taille=200;
	char* in=NULL;
	in = (char*)malloc(sizeof(char)*taille);
	char C1[100];
	char C2[100];
	Ville tmp;
	int Nbville;

	printf("\n**Bonjour, veuillez entrer tout d'abord le nombre de villes de votre fichier**\n\n");
	scanf("%d",&Nbville);
	printf("\n");



	
	/* Construction du graphe */
	N = (Noeud*)malloc(sizeof(Noeud) * Nbville);

	
  f = fopen(argv[1], "r+");
  if (f != NULL)
  {

    /* Lecture des villes */
    for (i = 0; i < Nbville; i++)
{
			/* Lecture de Nom, Nbhabitants, coord 1 et coord 2 */
			fscanf (f, "%[^,], %d, %[^,], %s,\n", v.Nom, &v.Hbts, C1, C2);

			v.C1=conversion_coordonnee(C1);
	
			v.C2=conversion_coordonnee(C2);		

  if(i==0){
	N->v=v;}
else{
			Ajouter_Fin(N,v); 
			Nbnoeuds++;
			
	}


}

/*probleme de Abbeville*/
tmp=N->v;
N=N->Ville_Suivante;
Ajouter_Fin(N,tmp);





   fclose(f);




menu(N,Nbnoeuds);



}else{
      perror(argv[1]);

}

	return 0;
}
