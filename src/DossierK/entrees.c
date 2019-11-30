#include <stdio.h>
#include <ctype.h>
#include "../../include/entrees.h"


int lire_fin_ligne(){
	int a = 0;
	char b = getchar();
	
	while((b != '\n') && (b != EOF)){
		if(!isspace(b)){
			a++;
		}
		b = getchar();
	}
	return a;
}


void lire_format(char format[] , void *a){
	int lu,nb;
	
	do{
		lu = scanf(format , a);
		nb = lire_fin_ligne();
	}while((lu != 1) || (nb > 0));
}


void lire_entier(int *n){
	lire_format("%d", n);
}


void lire_decimal(float *n){
	lire_format("%f", n);
}


void lire_entier_positif(int *n){
	do{
		lire_entier(n);
	}while(*n <= 0);
}
