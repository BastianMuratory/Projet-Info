#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "../include/structures.h"
#include "../include/fonctions.h"


int main(int argc , char *argv[]){
	//variables
	Point p;
	Vecteur v;
	Param pa1;
	FILE* data;
	int choix;
	
	//choix du système
	affmenu();
	scanf("%d" , &choix);
	affiche(choix);
	
	if((choix == 1) || (choix == 2) || (choix == 3)){
		//entrées
		pa1 = parametrage(pa1 , choix);
		p = position_initiale(p , choix);
		
		//calcul de la trajectoire
		data = fopen("data.dat" , "w");
		saveP(p , data);
		while(p.t < pa1.Tmax){
			v = vitesse(p , v , pa1 , choix);
			p = position_suivante(p , v , pa1);
			saveP(p , data);
		}
		fclose(data);
	}
	if(pa1.Tmax < pa1.dt){
		printf("le fichier data est erroné, dt est supposé être plus petit que Tmax.\n");
	}
	
	//fin d'execution
	printf("Fin du programme.\n");
	return 0;
}
