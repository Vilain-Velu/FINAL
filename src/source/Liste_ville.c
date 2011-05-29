#include "../headers/Liste_ville.h"

/*****************************************************
Fonction : prend en param�tre un pointeur sur Liste_Ville
Retour : renvoie la ville qui suit Liste_Ville
*****************************************************/
Liste_Ville* Suivant(Liste_Ville *L){
	return L->Ville_Suivant;
}


/*****************************************************
Fonction : prend en param�tre un pointeur sur Liste_Ville et regarde si celui-ci est vide
Retour : renvoie ?
*****************************************************/
int Est_Vide(Liste_Ville *L){
    return (L == NULL);
}


/*****************************************************
Fonction : prend en param�tre un pointeur sur Liste_Ville
Retour : renvoie le nombre de ses voisins
*****************************************************/
int Nb_Ville(Liste_Ville *L){
	Liste_Ville* tmp = L;
    int nb = 0;

    while(tmp != NULL){
        nb++;
        tmp = tmp->Ville_Suivant;
    }
    return nb;
}


/*****************************************************
Fonction : prend en param�tre un pointeur sur Liste_Ville
Retour : renvoie la liste de ses voisins
*****************************************************/
void Afficher_voisins(Liste_Ville* L,FILE* f){
    Liste_Ville* Nouvelle;
    Nouvelle=L;

    while(!Est_Vide(Nouvelle)){
        fprintf(f,"%s\n",Nouvelle->v.Nom);
        Nouvelle=Nouvelle->Ville_Suivant;
    }
}


/*****************************************************
Fonction :
Retour :
*****************************************************/
Liste_Ville* Ajouter_Fin_voisins(Liste_Ville *L, Ville V, float dist){
   	Liste_Ville* Nouvelle_Ville;
    Nouvelle_Ville = (Liste_Ville*)malloc(sizeof(Liste_Ville));
   	Nouvelle_Ville->v = V;
   	Nouvelle_Ville->Ville_Suivant = NULL;
	Nouvelle_Ville->dist=dist;

   	 if(L ==NULL){
   	    L=Nouvelle_Ville;
   	    return L;
  	 }else{
        Liste_Ville* Tmp = L;

        while(!Est_Vide(Suivant(Tmp))){
     	       Tmp = Suivant(Tmp);
        }
        Tmp->Ville_Suivant = Nouvelle_Ville;
        return L;
   	 }
}




/*****************************************************
Fonction :
Retour :
*****************************************************/
Liste_Ville* Ajouter_debut_voisins(Liste_Ville* L, Ville V,float dist){
    Liste_Ville* Nouvelle_Ville;
    Nouvelle_Ville= (Liste_Ville*)malloc(sizeof(Liste_Ville));
   	Nouvelle_Ville->v = V;
  	Nouvelle_Ville->Ville_Suivant = L;
	Nouvelle_Ville->dist=dist;
	L=Nouvelle_Ville;
	return L;
}
