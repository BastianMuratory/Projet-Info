#ifndef VARIABLE
#define VARIABLE


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


#endif