#include "../headers/kruskal.h"


void Inserer_trier(Arbre* A, Ville V1, Ville V2, float dist)
{

	Arbre* New = malloc(sizeof(Arbre));
	New->V1 = V1;
	New->V2 = V2;
	New->dist = dist;
	New->Suivant = NULL;

	if(A == NULL)
	{
	A=New;
	}

	else
	{ 
	Arbre* Tmp = A;

		while(Tmp->Suivant !=NULL && Tmp->Suivant->dist <= New->dist)
		{
 		Tmp = Tmp->Suivant;
		}

		if (strcmp(Tmp->V1.Nom,New->V2.Nom)!=0 && strcmp(Tmp->V2.Nom,New->V1.Nom)!=0){

			if (Tmp->Suivant ==NULL) 
			{ 
			Tmp->Suivant = New;
			}

			else 
			{
			New->Suivant = Tmp->Suivant;
			Tmp->Suivant = New;
			}


		}
	}
}





Arbre* RemplirArbre(Arbre* A,Noeud* N, int M)
{
	float dist=0.0;

	Arbre* Ab;
	Ville V1;
	Ville V2;
	Liste_Ville* Voisins;
	Noeud* No =N;



	while (No->v.indice< M)
	{ 

	V1=No->v;
	Voisins= No->Voisins_Ville;
	
		while (Voisins != NULL)
		{

			if(Voisins->v.indice >= M || Voisins->dist ==0) 
			{
			Voisins= Voisins->Ville_Suivant;
			}

			else
			{ 
			V2 = Voisins->v; dist= Voisins->dist;
			A=Ajouter_debut( A, V1,V2,dist) ;
			Voisins= Voisins->Ville_Suivant;
			}
		}
	No=No->Ville_Suivante;
	}

	Ab=A;
	A= quick_sort (A);


	return A->Suivant;
}






Arbre* Ajouter_debut(Arbre* A, Ville V1,Ville V2,float dist) 
{
	if (dist!=0.0)
	{ 
	Arbre* Nouveau;
	Nouveau= (Arbre*)malloc(sizeof(Arbre));
	Nouveau->V1 = V1;
	Nouveau->V2 = V2;
	Nouveau->dist=dist;
	Nouveau->Suivant = A;
	A=Nouveau;
	}
return A;
}








void initialisation_Mat(int Nb, float Mat[Nb][Nb])
{
	int i,j;
	for (i=0;i<Nb;i++)
	{
		for(j=0;j<Nb;j++)
		{
		Mat[i][j]=0;
		}
	}
}





Liste* Inserer(Liste* Li, int j)
{													/*au début*/                
	Liste* Nouveau;
	Nouveau= (Liste*)malloc(sizeof(Liste));
	Nouveau->val = j;
	Nouveau->Suivant = Li;
	Li=Nouveau;
return Li;
}





Liste* Voisin(int N, float Mat[N][N], int i)
{
	int j=0;
	Liste* L =NULL;
	/*L=(Liste*)malloc(sizeof(Liste));*/

	for(j=0;j<N;j++)
	{

		if(Mat[i][j] !=0)
		{ 
		L=Inserer(L,j);
		}
	}
return L;
}




int SS_circuit_prof(int N, float Mat[N][N], int i, int etat[N])
{

	int circ =1;									/*faux*/
	etat[i]=1; 										/*atteint*/
	Liste* L;
	L=(Liste*)malloc(sizeof(Liste));
	L=Voisin(N,Mat,i);


	while(L!=NULL && circ ==1)
	{
		if (etat[L->val]==0) 
		{
			if (SS_circuit_prof(N,Mat,L->val,etat) ==1 && circ ==1)
			{
			circ=1;
			}
			else
			{
			circ=0;
			}
		}
		else if (etat[L->val]==1) {circ=0;
		}
		L=L->Suivant;
	}
	etat[i]=2;
return circ;
}




void initialiser_etat(int Nb, int etat[Nb])
{
	int i;
	for(i=0; i<Nb; i++)
	{
	etat[i]=0;
	}
}




int sans_circuit2(int N, float Mat[N][N],int i, int etat[N])
{
	int u;
	Liste* L =NULL;
	Liste* Voisins;
	Voisins=(Liste*)malloc(sizeof(Liste));
	etat[i]=1;
	L=Ajouter_fin(L,i);

	while(L!=NULL)
	{
	u=L->val; L=L->Suivant;
	Voisins=Voisin(N, Mat, u);
		while(Voisins!= NULL)
		{ 
			if (etat[Voisins->val]==0)
			{
			etat[Voisins->val]=etat[u]+1;L=Ajouter_fin(L,Voisins->val);
			}
			else if (etat[Voisins->val]>=etat[u])
			{
			return 1;
			}
		Voisins=Voisins->Suivant;}
		}
return 0;
}






int Est_sans_circuit2(int N, float Mat[N][N])
{
	int etat[N];
	int circuit=1;
	int i;
	
	for(i=0; i<N; i++)
	{
	etat[i]=0; 										/*Non rencontré*/
	}

	i=0;

	while (i<N && circuit ==1) 
	{
		if (etat[i]==0) 
		{
			if (circuit==1 && sans_circuit2(N,Mat,i,etat) ==1)
			{
			return 1;									/*circuit=1*/
			}

		}

	i++;
	}
return 0;
}




Arbre* Ligne(Arbre* A,int N)
{

	int etat[N];
	initialiser_etat(N,etat);
	int IV1, IV2;
	float dist;
	float Mat[N][N];
	initialisation_Mat( N, Mat);
	Arbre* Ab;
	Ab=(Arbre*)malloc(sizeof(Arbre));


	while(A!=NULL)
	{
	IV1=A->V1.indice;
	IV2=A->V2.indice;
	dist = A->dist;
	Mat[IV1][IV2]=dist;
	Mat[IV2][IV1]=dist;


		if (Est_sans_circuit2(N,Mat) ==0)
		{ 

		Ab=Ajouter_debut(Ab,A->V1,A->V2,dist);
		A=A->Suivant->Suivant;
		}
		
		else 
		{

		Mat[IV1][IV2]=0.0;
		Mat[IV2][IV1]=0.0;
		A=A->Suivant->Suivant;
		}

	}
return Ab;
}




Liste* Ajouter_fin(Liste *L, int i) 
{
   	 Liste* N;
N = (Liste*)malloc(sizeof(Liste));
   	 N->val = i;
   	 N->Suivant = NULL;
		

   	 if(L == NULL )
	  		{
			L=N;


    	    return L;
  	  		}
    	else
   	 {
       	  Liste* Tmp = L;
       	  
      	  while(Tmp->Suivant !=NULL)
      	  {
     	       Tmp = Tmp->Suivant;
      	  }
      	  
          Tmp->Suivant = N;


	return L;
          
   	 }
}






/* tri rapide sur une liste chainée - choix du pivot naïf */
Arbre* _quick_sort (Arbre* L1, Arbre* end)
{
    Arbre *pivot, *tmp, *next, *prec, *suiv;
    if ( L1!= end && L1->Suivant != end )
    {
        /* partitionnement (fin liste 'prec' : 'pivot'; fin liste 'suiv' : 'end') */
        pivot = L1, prec = pivot, suiv = end;
        for ( tmp=L1->Suivant; tmp != end; tmp=next )
        {
            next = tmp->Suivant;
            if (tmp->dist > pivot->dist)
               { tmp->Suivant = suiv; suiv = tmp; }/* ajoute la cellule a la liste 'suiv' */
            else
               { tmp->Suivant = prec; prec = tmp; }/* ajoute la cellule a la liste 'prec' */
        }
        /* appels recursifs */
        prec = _quick_sort (prec, pivot);
        suiv = _quick_sort (suiv, end);
        /* recolle la liste */
        pivot->Suivant = suiv;
        return prec;
    }
    return L1;
}



Arbre* quick_sort (Arbre* list)
{
    return _quick_sort (list, NULL);
}
