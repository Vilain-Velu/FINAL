#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/graphe.h"

#define max 300.00


/*****************************************************
Fonction : prend un noeud* en paramètre et affiche le graphe
Retour : Pas de retour
*****************************************************/
void Afficher_Graphe(Noeud* N, int Nbnoeuds){
char nom[100] ="Graphe.txt";
   FILE* f = fopen(nom,"w+");
 Noeud *NoeudCourant;
    NoeudCourant =N;
	int i;

	if ( NoeudCourant ==NULL) {
      fputs("Graphe null",f);
	}

	for (i = 0; i < Nbnoeuds; i++){
		fputs("----------------------------\n",f);
		Afficher_Noeud (NoeudCourant,f);
fputs("Les voisins sont  :\n",f);
     
		Afficher_voisins(NoeudCourant->Voisins_Ville,f);
		NoeudCourant  =NoeudCourant->Ville_Suivante;

		fputs("\n",f);
	}
fclose(f);
printf("\n\nLe fichier %s a été généré \n",nom);

}


/*****************************************************
Fonction : prend un noeud* en paramètre et affiche les villes, sans leurs voisins
Retour : pas de retour
*****************************************************/
void Afficher_Graphe_sans_voisin (Noeud* N,int Nbnoeuds){

char nom[100]="Graphe sans voisin.txt";
FILE* f = fopen(nom,"w+");


    Noeud *NoeudCourant;
    NoeudCourant =N;
	int i;

	if ( NoeudCourant ==NULL) {
fputs("Graphe null",f);
     
	}

	for (i = 0; i < Nbnoeuds; i++){
fputs("----------------------------\n",f);
		Afficher_Noeud (NoeudCourant,f);
		NoeudCourant  =NoeudCourant->Ville_Suivante;
fputs("\n",f);
		
	}
fclose(f);
printf("\n\nLe fichier %s a été généré \n",nom);}



/*****************************************************
Fonction : Prend un Noeud* en paramètre et génère la liste des voisins de chaque ville
Retour : pas de retour
*****************************************************/

void generer_graphe(Noeud* N){
    Noeud* Noeud_courant=NULL;
    Noeud* tmp=NULL;
    Liste_Ville* Voisins=NULL;Noeud_courant=N;
    Noeud_courant->Voisins_Ville=Voisins;
float dist=0;

    printf(" * La distance max entre ville voisine vaut :%f km * \n\n",max);

    while(!Est_Vide_noeud(Noeud_courant)){
        tmp=N;

        while(!Est_Vide_noeud(tmp)){
	dist=distance(Noeud_courant->v,tmp->v);
            if(dist<=max){
		                Noeud_courant->Voisins_Ville=Ajouter_debut_voisins(Noeud_courant->Voisins_Ville,tmp->v,dist);
            }
        tmp=tmp->Ville_Suivante;
        }
    Noeud_courant=Noeud_courant->Ville_Suivante;
    }
}


/*****************************************************
Fonction : calcule le Plus Court Chemin entre deux villes
Retour :
*****************************************************/
int PCC (Noeud* N, int Nb, char v1[100], char v2[100],int ant[Nb][2],float poids[Nb][3]){

    int i=0;
    float j=0;
    int indicev2 = indice(N,v2);
    int indicev1 = indice(N,v1);
    Noeud* No ;
    No=N;
    int indicecourant=indicev1;
    int indvoisin;
    Liste_Ville* voisinscourant;

    for (i=0;i<Nb;i++){
        poids[i][0]= j;
        poids[i][1]=9999;
        poids[i][2]= 1; /*variable qui sert à déterminer si on est passé par le noeud*/
        j++;
	}

    poids[indicev1][1]=0;  /* la distance de la ville de départ à elle même = 0 */
    					   /*initialisation des tableaux des antecedents*/
    for (i=0;i<Nb;i++){
	ant[i][0]= i;
	ant[i][1]=-1;}

        while (indicecourant != indicev2) {
            poids[indicecourant][2]= 0;
            voisinscourant = fils(N,indicecourant);

            while(voisinscourant !=NULL) {
                indvoisin =voisinscourant->v.indice;
                if (poids[indvoisin][2] !=0 &&((poids[indicecourant][1]+voisinscourant->dist) < poids[indvoisin][1] || poids[indvoisin][1] == 99999 )) {
                poids[indvoisin][1] =  (poids[indicecourant][1]+voisinscourant->dist);
                ant[indvoisin][1]=indicecourant;
                }

                voisinscourant=voisinscourant->Ville_Suivant;
            }
            indicecourant=indice_poids_plus_faible_np(Nb,poids);
        }
    return 0;
}


/*****************************************************
Fonction : renvoie l'indice correspondant au nom de la ville donné en paramètre
Retour :
*****************************************************/
int indice(Noeud* N, char c[100]){
    int ind=0;
    char* ville;
    int trouve = 0;
    int i,j;

    while (!Est_Vide_noeud(N) && trouve != 1){
        ville=N->v.Nom;
        i=strlen(ville)-1;
        j=0;

        while(j<i && ville[j+1]==c[j]){
            j++;
        }

        if (j==i){
            trouve=1;
        }else{
			trouve=0;
        }
		N = Suivant_noeud(N);
		ind++;
	}

	if (trouve == 1){
		return (ind-1);
    }else{
		return 0;
	}
}


/*****************************************************
Fonction : renvoie le nom de la ville correspondant à l'indice donné en paramètre
Retour :
*****************************************************/
char* nom(Noeud* N, int id){
    int i;

    for(i=1;i<=id;i++){
        N=N->Ville_Suivante;
    }
    return N->v.Nom;
}


/*****************************************************
Fonction : renvoie l'indice de la ville voisine
Retour :
*****************************************************/
int indicevoisin(Noeud* N, char c[100]){
    int i=1;

    while(strcmp(N->v.Nom, c) != 0){
        i++;
        N=N->Ville_Suivante;
    }
    return (i-1);
}


/*****************************************************
Fonction :
Retour :
*****************************************************/
int indice_poids_plus_faible_np(int Nb,float poids[Nb][3]){
    float  poidscourant ;
    int indice;
    int i;
    poidscourant  = 9999;
    indice =-1;

    for(i=0; i<Nb; i++) {
        if(poids[i][2]!= 0  && poids[i][1]< poidscourant ) {  poidscourant  = poids[i][1]; indice = i;}
    }
    return indice;
}


/*****************************************************
Fonction : renvoie la coordonnée 1 de la ville d'indice i
Retour :
*****************************************************/
float c1_indice(int i, Noeud* N){
    int j;
    Noeud* tmp;
    tmp=N;

    for(j=0;j<i;j++){
        tmp=tmp->Ville_Suivante;
    }
    return tmp->v.C1;
}


/*****************************************************
Fonction : renvoie la coordonnée 2 de la ville d'indice i
Retour :
*****************************************************/
float c2_indice(int i, Noeud* N){
    int j;
    Noeud* tmp;
    tmp=N;

    for(j=0;j<i;j++){
        tmp=tmp->Ville_Suivante;
    }
    return tmp->v.C2;
}


/*****************************************************
Fonction : renvoie un tableau contenant les villes nécessaires c'est à dire les villes dans lesquelles le petit avion doit absolument s'arrêter pour faire le plein de kérosène
Retour :
*****************************************************/
void Villesnecessaire (Noeud* N,int Nb ,int ant[Nb][2],int VD, int VA,int tab[1000]){
    int i =0;
    int indice;
    float compteur =0.0;
    indice = VA;
    int derniereville =VA;
    i++;
    indice=ant[indice][1];
    compteur=distance2(N,VA,indice);

    while(indice !=VD){
        if (compteur<=max){
            if ((compteur+distance2(N,indice, ant[indice][1]))<=max){
                compteur =compteur+distance2(N,indice, ant[indice][1]);
                indice=ant[indice][1];
            }else{
                tab[derniereville]=indice;
                derniereville=indice;      /*indice=ant[indice][1];*/
                compteur=0;
            }
        }
    }

    if(indice ==VD){
        tab[derniereville]=indice;
    }
}

