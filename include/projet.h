#ifndef __FONCTION__
#define __FONCTION__

typedef struct Point Point;
struct Point{
	float x;
	float y;
	float z;
	float time;
};

typedef struct Vitesse Vitesse;
struct Vitesse{
	float x;
	float y;
	float z;
};

typedef struct Param Param;
struct Param{
	float sigma;
	float rho;
	float beta;
};

//fonctions pour les entrées
int lire_fin_ligne();
void lire_format(char format[], void*a);
void lire_decimale(float *a);

//fonctions pour le point
Point initPoint(Point p);
void affPoint(Point p);
void saveP(Point p1,FILE* data);

//fonction pour les parrametres et la position initiale
Param parametrage(Param pa, float *Tmax, float *dt);
Point pointInitial(Point p);

//fonctions de calcul
Vitesse vitesse(Vitesse v , Point p , Param pa);
Point positionSuivante(Point p, Vitesse v, Param pa, float dt);

#endif