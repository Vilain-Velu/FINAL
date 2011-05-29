#include "../headers/ville.h"


/*****************************************************
Fonction : prend une ville en paramètre et affiche ses différentes caractéristiques
Retour :
*****************************************************/
void Afficher_Ville(Ville v,FILE* f){
 	fprintf(f,"Nom %s \n", v.Nom);
	fprintf(f,"Nb habitants %d \n", v.Hbts);
 	fprintf(f,"Coord 1 %f \n", v.C1);
	fprintf(f,"Coord 2 %f \n", v.C2);
}


/*****************************************************
Fonction : convertit une coordonnée de type caractère 00.00000A en une coordonnée de type float
Retour : renvoie un flottant (négatif si la chaine en entrée finie par O ou S)
*****************************************************/
float conversion_coordonnee (char *c){
    int i = 0;
    int j;
    float k;
    char temp[20] ;

    i = strlen(c);
    if ((c[i-1] == 'N' )||(c[i-1] == 'E' )){
        for(j=0;j<i;j++){
            temp[j]=c[j];
        }
        k = atof(temp);
    }else{
        for(j=0;j<i;j++){
            temp[j]=c[j];
        }
        k = atof(temp);
        k=0-k;
    }
    return k;
}


/*****************************************************
Fonction : calcule la distance entre 2 villes
Retour : un flottant
*****************************************************/
float distance(Ville v1 ,Ville v2){
    float theta, dist;
    theta = v1.C2 - v2.C2;
    dist = sin(deg2rad(v1.C1)) * sin(deg2rad(v2.C1)) + cos(deg2rad(v1.C1)) * cos(deg2rad(v2.C1)) * cos(deg2rad(theta));
    dist = acos(dist);
    dist = rad2deg(dist);
    dist = dist * 60 * 1.1515;
    dist = dist * 1.609344;
	return (dist);
}


/*****************************************************
Fonction : convertit des degré en radian
Retour : flottant
*****************************************************/
float deg2rad(float deg) {
    return (deg * pi / 180);
}


/*****************************************************
Fonction : convertit des radian en degré
Retour : flottant
*****************************************************/
float rad2deg(float rad) {
    return (rad * 180 / pi);
}
