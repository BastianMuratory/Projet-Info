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



void EntrerParam(float *x , float *y , float *z , float *sigma , float *beta , float *rho){
    printf("Entrez la coordonée X : \n");
    lire_decimale(x);
    printf("Entrez la coordonée Y : \n");
    lire_decimale(y);
    printf("Entrez la coordonée Z : \n");
    lire_decimale(z);
    printf("Entrez le paramètre σ : \n");
    lire_decimale(sigma);
    printf("Entrez le paramètre β : \n");
    lire_decimale(beta);
    printf("Entrez le paramètre ρ : \n");
    lire_decimale(rho);
}

void affPoint(Point p){
	printf("les coordonnées du point sont : x=%f y=%f z=%f au temp t = %f \n",p.x ,p.y ,p.z ,p.time);
}

int main(int argc,char *argv[]){
    Point p1;
    p1=initPoint(p1);
    affPoint(p1);
    for(int i=0; i<3;i =i+1){
    	p1.x = p1.x+1;
    	p1.z = p1.z+2;
    	affPoint(p1);
    }
    return 0;
}