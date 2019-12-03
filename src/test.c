#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct Point Point;

struct Point{
	float x;
	float y;
	float z;
	float time;
};


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
};

typedef struct Param Param;

/////////////////////////////////////////////////////////////////////////////////

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

Point initPoint(Point p){
	p.x = 0;
	p.y = 0;
	p.z = 0;
	p.time = 0;
	return p;
}

void affPoint(Point p){
	//cette fonction servait de vérification durant la création du projet
	printf("les coordonnées du point sont : x=%f y=%f z=%f au temp t = %f \n",p.x ,p.y ,p.z ,p.time);
}

void saveP(Point p1,FILE* data){
	fprintf(data,"%f %f %f %f \n",p1.time ,p1.x ,p1.y ,p1.z);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////

Param parametrage(Param pa, float *Tmax, float *dt){
	printf("Entrez le paramètre σ : ");
	lire_decimale(&pa.sigma);
	printf("Entrez le paramètre ρ : ");
	lire_decimale(&pa.rho);
	printf("Entrez le paramètre β : ");
	lire_decimale(&pa.beta);
	printf("Entrez le Temps maximal de la simulation (Tmax) : ");
	lire_decimale(Tmax);
	printf("Entrez le petit temps (dt) : ");
	lire_decimale(dt);
	return pa;
}

Point pointInitial(Point p){
	printf("Entrez la coordonée x : ");
	lire_decimale(&p.x);
	printf("Entrez la coordonée y : ");
	lire_decimale(&p.y);
	printf("Entrez la coordonée z : ");
	lire_decimale(&p.z);
	p.time = 0;
	return p;
}

//premier systeme
Vecteur vitesse1(Vecteur v , Point p , Param pa){
	v.x = pa.sigma*(p.y-p.x);
	v.y = p.x*(pa.rho-p.z)-p.y;
	v.z = p.x*p.y-pa.beta*p.z;
	return v;
}
//deuxieme systeme
Vecteur vitesse2(Vecteur v , Point p , Param pa){
	return v;
}

Point positionSuivante(Point p, Vecteur v, Param pa, float dt){
	p.x += v.x;
	p.y += v.y;
	p.z += v.z;
	p.time += dt;
	return p;
}

///////////////////////////////////////////////////////

int main(int argc,char *argv[]){
	//les différentes variables nécessaires
    Point p;
    Param pa1;
    float Tmax;
    float dt;
    Vecteur v;
    FILE* data;
    
    //choix du systeme
    int syst;
    syst = 1;
    
    
    //entrée des coordonées initiales par l'utilisateur
    p = pointInitial(p);
    pa1 = parametrage(pa1,&Tmax,&dt);
    
    //boucle permettant de calculer chacun des points gràce à leur vecteur vitesse associé
    data = fopen("data.dat" , "a");
    saveP(p,data);
    if(syst == 1){
    	while(p.time<Tmax){
			v = vitesse1(v,p,pa1);
			p = positionSuivante(p,v,pa1,dt);
			saveP(p,data);
		}
    }
    fclose(data);
    return 0;
}