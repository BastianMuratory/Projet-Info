#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "include/projet.h"


int main(int argc,char *argv[]){
	//les différentes variables nécessaires
    Point p;
    Param pa1;
    float Tmax;
    float dt;
    Vitesse v1;
    FILE* data;
    
    //entrée des coordonées initiales par l'utilisateur
    p = pointInitial(p);
    pa1 = parametrage(pa1,&Tmax,&dt);
    
    //boucle permettant de calculer chacun des points gràce à leur vecteur vitesse associé
    data = fopen("data.dat" , "a");
    saveP(p,data);
	while(p.time<Tmax){
		v1 = vitesse(v1,p,pa1);
		p = positionSuivante(p,v1,pa1,dt);
		saveP(p,data);
	}
    fclose(data);
    
    
    
    return 0;
}