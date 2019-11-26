#include <stdio.h>

void EntrerParam(int *x , int *y , int *z , int *sigma , int *beta , int *rho){
    printf("Entrez la coordonée X : \n");
    entrerfloat(x);
    printf("Entrez la coordonée Y : \n");
    entrerfloat(y);
    printf("Entrez la coordonée Z : \n");
    entrerfloat(z);
    printf("Entrez le paramètre σ : \n");
    entrerfloat(sigma);
    printf("Entrez le paramètre β : \n");
    entrerfloat(beta);
    printf("Entrez le paramètre ρ : \n");
    entrerfloat(rho);
}