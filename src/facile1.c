#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

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