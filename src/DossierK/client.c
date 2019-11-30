#include <stdio.h>
#include "../../include/vecteur.h"


int main(int argc , char *argv[]){
	Vecteur M,vM;
	float param1,param2,param3;
	FILE* data = NULL;
	
	parametrage(&M , &param1 , &param2 , &param3);
	vitesse(&vM , M , param1 , param2 , param3);
	trajectoire(M , vM , 2);
	return 0;
}
