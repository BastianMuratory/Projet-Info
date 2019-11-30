#ifndef __VECTEUR__
#define __VECTEUR__


struct sVecteur{
	float x;
	float y;
	float z;
};

typedef struct sVecteur Vecteur;


void parametrage(Vecteur *p , float *sigma , float *rho , float *beta);

void vitesse(Vecteur *v , Vecteur p , float sigma , float rho , float beta);

int trajectoire(Vecteur p , Vecteur v , float Tmax);


#endif
