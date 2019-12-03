#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


//////////////////////////////////////Structures////////////////////////////////////////////////

struct Point{
	float x;
	float y;
	float z;
	float t;
};
typedef struct Point Point;

struct Vecteur{
	float x;
	float y;
	float z;
};
typedef struct Vecteur Vecteur;

struct Param{
	float sigma;
	float rho;
	float beta;
	float mu;
	float dt;
	float Tmax;
};
typedef struct Param Param;

//////////////////////////////////////Entrées///////////////////////////////////////////

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

void lire_format(char format[], void*a){
	int lu;
	int nb;	
	do{
		lu=scanf(format,a);
		nb=lire_fin_ligne();
	}while((lu!=1)||(nb>0));
}

void lire_decimale(float *a){
	int lu;
	int nb;	
	do{
		lu=scanf("%f",a);
		nb=lire_fin_ligne();
	}while((lu!=1)||(nb>0));
}

//////////////////////////////////////////////Trucs qui servent à rien//////////////////////////////////

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

///////////////////////////////////////////Lib///////////////////////////////////////////////

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
	}
	printf("Entrez la valeur de temps élémentaire (dt) : ");
	lire_decimale(&pa.dt);
	printf("Entrez le temps de simulation (Tmax) : ");
	lire_decimale(&pa.Tmax);
	return pa;
}

Point position_initiale(Point p , int choix){
	if(choix == 1){
		p.x = 1;
		p.y = 2;
		p.z = 3;
	}else if(choix == 2){
		printf("Entrez la coordonée x : ");
		lire_decimale(&p.x);
		printf("Entrez la coordonée y : ");
		lire_decimale(&p.y);
		printf("Entrez la coordonée z : ");
		lire_decimale(&p.z);
	}
	p.t = 0;
	return p;
}

Vecteur vitesse(Point p , Vecteur v , Param pa , int choix){
	if(choix == 1){
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

///////////////////////////////////////////test.c////////////////////////////////////////

int main(int argc , char *argv[]){
	//variables
	Point p;
	Vecteur v;
	Param pa1;
	FILE* data;
	int choix;
	
	//choix du système
	printf("\nProgramme de modélisation de la trajectoire d'un point\n\n");
	printf("Menu :\n\n");
	printf("1 : Système de Lorenz\n");
	printf("2 : Oscillateur de Van der Pol\n");
	printf("[autre entrée] : Quitter le programme\n\n");
	printf("Entrez le numéro correspondant à l'action de votre choix : ");
	scanf("%d" , &choix);
	
	if((choix == 1) || (choix == 2)){
		//entrées
		parametrage(pa1 , choix);
		position_initiale(p , choix);
		
		//calcul de la trajectoire
		data = fopen("data.dat" , "a");
		saveP(p , data);
		while(p.t < pa1.Tmax){
			v = vitesse(p , v , pa1 , choix);
			p = position_suivante(p , v , pa1);
			saveP(p , data);
		}
		fclose(data);
	}
	
	//fin d'execution
	printf("Fin du programme.\n");
	return 0;
}
