#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "../include/structures.h"

//////////////////////////////////////Entrées/////////////////////////////////////////

int lire_fin_ligne(){
	int x=0; // le nombre de charactères
	char c;
	c=getchar();
	while (c!='\n' && c != EOF){
		if (!isspace(c)){
			x++;
		}
		c=getchar();
	}
    return(x);
}

void lire_decimale(float *a){
	int lu;
	int nb;	
	do{
		lu=scanf("%f",a);
		nb=lire_fin_ligne();
	}while((lu!=1)||(nb>0));
}

//////////////////////////////////////////////////////////////

Point initPoint(Point p){
	p.x = 0;
	p.y = 0;
	p.z = 0;
	p.t = 0;
	return p;
}

void affPoint(Point p){
	//cette fonction servait de vérification durant la création du projet
	printf("les coordonnées du point sont : x=%f y=%f z=%f au temp t = %f \n", p.x, p.y, p.z, p.t);
}

void saveP(Point p1,FILE* data){
	fprintf(data,"%f %f %f %f \n", p1.t, p1.x, p1.y, p1.z);
}

void affiche(int choix){
	if (choix == 1){
		printf("Vous avez choisis le système de Lorenz.\n\n");
	}else if (choix == 2){
		printf("Vous avez choisis le système de Van der Pol.\n\n");
	}else if (choix == 3){
		printf("Vous avez choisis le système de Lorenz avec les coordonées initiales (1,2,3) ainsi que sigma=10, rho=28 et beta=8/3.\n\n");
	}else{
		printf("Veuillez choisir entre 1,2 ou 3. \nLe programme va maintenant se terminer.\n");
	}
}

void affmenu(){
	printf("\nProgramme de modélisation de la trajectoire d'un point.\n\n");
	printf("Menu :\n\n");
	printf("  - 1 : Système de Lorenz.\n");
	printf("  - 2 : Oscillateur de Van der Pol.\n");
	printf("  - 3 : Système de Lorentz prédéfinit.\n");
	printf("  - [autre entrée] : Quitter le programme.\n\n");
	printf("Entrez le numéro correspondant à l'action de votre choix : ");
}
///////////////////////////////////////////////////////////////////////////////////

Param parametrage(Param pa , int choix){
	if(choix == 1){
		printf("Entrez le paramètre σ : ");
		lire_decimale(&pa.sigma);
		printf("Entrez le paramètre ρ : ");
		lire_decimale(&pa.rho);
		printf("Entrez le paramètre β : ");
		lire_decimale(&pa.beta);
	}else if(choix == 2){
		printf("Entrez le paramètre µ : ");
		lire_decimale(&pa.mu);
	}else if (choix == 2){
		pa.sigma = 10;
		pa.rho = 28;
		pa.beta = (8/3);
	}
	printf("Entrez le temps de simulation (Tmax) : ");
	lire_decimale(&pa.Tmax);
	printf("Entrez la valeur de temps élémentaire (dt) : ");
	lire_decimale(&pa.dt);
	return pa;
}

Point position_initiale(Point p , int choix){
	if (choix == 3){
		p.x = 1;
		p.y = 2;
		p.z = 3;
	}else{
		printf("Entrez la coordonée x initiale : ");
		lire_decimale(&p.x);
		printf("Entrez la coordonée y initiale : ");
		lire_decimale(&p.y);
		printf("Entrez la coordonée z initiale : ");
		lire_decimale(&p.z);
	}
	p.t = 0;
	return p;
}

Vecteur vitesse(Point p , Vecteur v , Param pa , int choix){
	if((choix == 1) || (choix == 3)){
		v.x = pa.sigma*(p.y-p.x);
		v.y = p.x*(pa.rho-p.z)-p.y;
		v.z = p.x*p.y-pa.beta*p.z;
	}else if(choix == 2){
		v.x = pa.mu*(p.x-(p.x*p.x*p.x/3)-p.y);
		v.y = p.x/pa.mu;
		v.z = 0;	
	}
	return v;
}

Point position_suivante(Point p, Vecteur v, Param pa){
	p.x += v.x;
	p.y += v.y;
	p.z += v.z;
	p.t += pa.dt;
	return p;
}
