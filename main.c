
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "hypergraphe.h"











int main()
{
	srand(time(NULL));
	long int **g=NULL;
	long int sommets;
	long int aretes;
	float proba;
	int res;
	puts("nombre sommets : ");
	scanf("%ld",&sommets);
	puts("nombre aretes : ");
	scanf("%ld",&aretes);
	puts("probablilite : ");
	scanf("%f",&proba);
	
	g = creation_hypergraphe(sommets,aretes);
	generation_aleatoire(g,sommets,aretes,proba);
	res = grahpe_est_simple(g,sommets,aretes);
	afficher(g,sommets,aretes);
	/*taille_aretes_ok(g,sommets,aretes);*/
	printf("********** RES = %d ***********\n",res);
	return EXIT_SUCCESS;



}
