
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
	
	for(i=0;i<200;i++)
	{
		generation_aleatoire(g,sommets,aretes,proba);
		res = grahpe_est_simple(g,sommets,aretes);
		if(res==1)
			cmp++;
	}
	/*afficher(g,sommets,aretes);*/
	/*taille_aretes_ok(g,sommets,aretes);*/
	printf("********** RES pour 200 hypergraphes  %d sont simples***********\n",cmp);
	liberer_graphe(g,sommets);

	return EXIT_SUCCESS;



}
