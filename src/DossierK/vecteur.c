#include <stdio.h>
#include <stdlib.h>
#include "../../include/entrees.h"
#include "../../include/vecteur.h"

#define dt 0.01


void parametrage(Vecteur *p , float *sigma , float *rho , float *beta, float *Tmax){
	printf("Entrez la coordonée x : ");
	lire_decimale(p.x);
	printf("Entrez la coordonée y : ");
	lire_decimale(p.y);
	printf("Entrez la coordonée z : ");
	lire_decimale(p.z);
	printf("Entrez le paramètre σ : ");
	lire_decimale(sigma);
	printf("Entrez le paramètre ρ : ");
	lire_decimale(rho);
	printf("Entrez le paramètre β : ");
	lire_decimale(beta);
	printf("Entrez le paramètre Tmax : ");
	lire_decimale(Tmax);
}


void vitesse(Vecteur *v , Vecteur p , float sigma , float rho , float beta){
	v.x = sigma*(p.y-p.x);
	v.y = p.x*(rho-p.z)-p.y;
	v.z = p.x*p.y-beta*p.z;
}


int trajectoire(Vecteur p , Vecteur v , float Tmax , FILE *data){
	data = fopen("data.txt" , "r+");
	if(data == NULL){
		printf("Impossible d'ouvrir le fichier .txt.\n");
		return 1;
	}
	for(int t=0 ; t<Tmax ; t+=dt){
		p.x += v.x;
		p.y += v.y;
		p.z += v.z;
		fprintf(data , "%f %f %f" , p.x,p.y,p.z);
	}
	fclose(data);
	return 0;
}
