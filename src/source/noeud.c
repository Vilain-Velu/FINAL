#include "../headers/noeud.h"

/*****************************************************
Fonction : Prend un Noeud* en param�tre et regarde si il est vide
Retour :
*****************************************************/
int Est_Vide_noeud(Noeud *N){
    return (N == NULL);
}


/*****************************************************
Fonction : Prend un Noeud* en param�tre
Retour : renvoie le Noeud suivant
*****************************************************/
Noeud* Suivant_noeud(Noeud *N){
	return N->Ville_Suivante;
}


/*****************************************************
Fonction :
Retour :
*****************************************************/
void Ajouter_Fin(Noeud* N, Ville V){
   	 Noeud* New = malloc(sizeof(Noeud));
   	 New->v = V;
   	 New->Ville_Suivante = NULL;

   	 if(Est_Vide_noeud(N)){
        N=New;
  	 }else{
        Noeud* Tmp = N;

        while(!Est_Vide_noeud(Suivant_noeud(Tmp)) && Suivant_noeud(Tmp)->v.Hbts >= New->v.Hbts){
            Tmp = Suivant_noeud(Tmp);
      	}

        if (Est_Vide_noeud(Suivant_noeud(Tmp))) {
            Tmp->Ville_Suivante = New;
        }else{
            New->Ville_Suivante = Suivant_noeud(Tmp);
            Tmp->Ville_Suivante = New;
        }
   	 }
}


/*****************************************************
Fonction : Affiche les noms des villes commen�ant par les caract�res donn�s en param�tre
Retour :
*****************************************************/
void completion (char* c, Noeud* N){
    int i;
    int j;
    char* ville;
    ville=(char*)malloc(sizeof(char));
    i=strlen(c)-1;
    printf("\n");
    printf("**Ville incorrecte, voir ci-apres les villes disponibles commencant par : %s\n",c);

    while(!Est_Vide_noeud(N)){
        ville=N->v.Nom;
        j=0;
        while(j<i && ville[j+1]==c[j]){
        j++;
        }
		if (j==i){
            printf("%s\t",ville);
        }
	    N = Suivant_noeud(N);
	}
    printf("\n");
}


/*****************************************************
Fonction :
Retour :
*****************************************************/
int Rechercher_Noeud(Noeud* N, char* id){
	char* ville;
	int trouve = 0;
	int i,j;

	while (!Est_Vide_noeud(N) && trouve != 1){
	    ville=N->v.Nom;
		i=strlen(ville)-1;
        j=0;
        while(j<i && ville[j+1]==id[j]){
            j++;
        }

        if (j==i){
            trouve=1;
        }else{
        trouve=0;
        }
        N = Suivant_noeud(N);
    }

	if (trouve == 1){
		printf(" * Ville enregistree! *\n\n");
		return 1;
    }else{
        return 0;
	}
}


/*****************************************************
Fonction : Ajoute des indices dans le graphe, correspondant � la position des noeuds
Retour :
*****************************************************/
void Remplirindice( Noeud* N){
    Noeud* tmp;
    tmp =N;
    int i=0;

    while(tmp!=NULL){
        tmp->v.indice=i;
        tmp=tmp->Ville_Suivante;
        i++;
    }
}


/*****************************************************
Fonction : calcule la distance entre la ville d'indice v1 et celle d'indice v2
Retour :
*****************************************************/
float distance2(Noeud* N,int v1, int v2){
    int i,j;
    Ville V1,V2;
    Noeud* tmp;
    tmp=N;

    for (i=0;i<v1;i++){
        tmp=tmp->Ville_Suivante;
    }

    V1=tmp->v;
    tmp=N;

    for (j=0;j<v2;j++){
        tmp=tmp->Ville_Suivante;
    }
    V2=tmp->v;
    return distance(V1,V2);
}


/*****************************************************
Fonction : renvoie la liste des fils du noeud N
Retour :
*****************************************************/
Liste_Ville* fils(Noeud* N, int indice){
    Noeud* noeudcourant;
    noeudcourant=N;
    int i=0;

    for (i=0;i<indice;i++){
        noeudcourant =noeudcourant->Ville_Suivante;
    }

    return noeudcourant->Voisins_Ville;
}

/*****************************************************
Fonction : Prend un noeud* en param�tre et affiche la ville courante
Retour : pas de retour
*****************************************************/
void Afficher_Noeud(Noeud* N,FILE* f){
	Afficher_Ville (N->v,f);
}


