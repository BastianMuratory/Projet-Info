#ifndef __FONCTION__
#define __FONCTION__

//fonctions pour les entrées
int lire_fin_ligne();
void lire_format(char format[] , void*a);
void lire_decimale(float *a);

//fonctions pour le point
Point initPoint(Point p);
void affPoint(Point p);
void saveP(Point p1,FILE* data);

//affichage
void affiche(int choix);
void affmenu();


//fonction pour les parametres et la position initiale
Param parametrage(Param pa , int choix);
Point position_initiale(Point p , int choix);

//fonctions de calcul
Vecteur vitesse(Point p , Vecteur v , Param pa , int choix);
Point position_suivante(Point p, Vecteur v, Param pa);
#endif