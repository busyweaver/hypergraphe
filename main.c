
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "hypergraphe.h"





#define NUMBER_OF_TEST 1000





int main(int argc,char**argv)
{
	srand(time(NULL));
	long int **g=NULL;
	long int sommets;
	long int aretes;
	double proba;
	int res;
	double cmp=0,cmp2=0;
	int i;

	if(argc==4)
	{

	sommets=atoi(argv[1]);

	aretes=atoi(argv[2]);

	proba=atof(argv[3]);
	g = creation_hypergraphe(sommets,aretes);
	for(i=0;i<NUMBER_OF_TEST;i++)
	{
	generation_aleatoire(g,sommets,aretes,proba);
	/*afficher(g,sommets,aretes);*/
	cmp += grahpe_type(g,sommets,aretes,1);
	cmp2+= grahpe_type(g,sommets,aretes,2);
	}
	printf("simple %g, sperner %g\n",cmp/NUMBER_OF_TEST,cmp2/NUMBER_OF_TEST);
	/*taille_aretes_ok(g,sommets,aretes);*/

	liberer_graphe(g,sommets);
	}
	return EXIT_SUCCESS;



}
