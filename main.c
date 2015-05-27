
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
	int cmp=0;
	int i;
	puts("nombre sommets : ");
	scanf("%ld",&sommets);
	puts("nombre aretes : ");
	scanf("%ld",&aretes);
	puts("probablilite : ");
	scanf("%f",&proba);
	g = creation_hypergraphe(sommets,aretes);
	generation_aleatoire(g,sommets,aretes,proba);
	afficher(g,sommets,aretes);
	res = grahpe_type(g,sommets,aretes,1);
	printf("********** RES %d ***********\n",res);
	res = grahpe_type(g,sommets,aretes,2);
	printf("********** RES %d ***********\n",res);

	/*taille_aretes_ok(g,sommets,aretes);*/

	liberer_graphe(g,sommets);

	return EXIT_SUCCESS;



}
