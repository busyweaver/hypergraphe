#include "hypergraphe.h"
#include <stdlib.h>
#include <time.h> 




/*genere un nombre aleatoire entre 0 et 1*/
double nombre_aleatoire()
{
    return ( rand()/(double)RAND_MAX );
}








long int** creation_hypergraphe(long int sommets,long int hyperaretes)
{
	puts("creation graphe");
	long int** g=NULL;
	long int i=0;
	g=(long int**)malloc(sommets*sizeof(long int*));
	for(i=0;i<sommets;i++)
		g[i]=(long int*)malloc(hyperaretes*sizeof(long int));

	puts("fin creation graphe");
	return g;

}

/*generation d'un hypergraphe aleatoire en remplissant sa matrice d'incidence avec des variables aleatoire de bernoulli iid*/
void generation_aleatoire(long int**g,long int sommets,long int hyperaretes,float proba)
{
	puts("generation aleatoire");
	long int i,j;
	float alea;
	for(i=0;i<sommets;i++)
	{
		for(j=0;j<hyperaretes;j++)
		{
			alea = nombre_aleatoire();
			if(alea<=proba)
				g[i][j]=1;
			else
				g[i][j]=0;
		}
	}
	puts("fin generation aleatoire");
}


int grahpe_est_simple(long int **g,long int s,long int h)
{
	puts("grahpe est simple");
	if(taille_aretes_ok(g,s,h)==0)
		return 0;
	int collision;
	long int *arete=NULL;
	arete = (long int *) malloc(s*sizeof(long int));
	long int j;
	for(j=0;j<h-1;j++)
	{
		arete_courante(g,s,j,arete);
		collision = verifier(arete,g,s,j+1,h);
		if(collision==1)
			return 0;
	}
	puts("fin grahpe est simple");
	return 1;
}


int verifier(long int*arete,long int**g,long int s,long int deb,long int h)
{
	puts("verifier");
	long int j;
	for(j=deb;j<h;j++)
	{
		if(est_egal(arete,g,s,j))
			return 1;

	}
	puts("fin verifier");
	return 0;
}

int est_egal(long int* arete,long int**g,long int s,long int j)
{
	puts("est egal");
	int x=1;
	long int i;
	for(i=0;i<s;i++)
	{
		if(arete[i]!=g[i][j])
		{
			x=0;
		}
	}
	puts("fin est egal");
	return x;

}



void arete_courante(long int**g,long int s,long int j,long int* arete)
{
	puts("arete courante");
	long int i;
	for(i=0;i<s;i++)
		arete[i] = g[i][j];
	puts("fin arete courante");
}



int taille_aretes_ok(long int **g,long int s,long int h)
{
	puts("taille aretes ok");
	long int j;
	long int t;
	for(j=0;j<h;j++)
	{
		t = taille_arete(g,s,j);
		if(t<2)
		{
			puts("fin taille aretes ok 0");
			return 0;
		}
	}
	puts("fin taille aretes ok 1");
	return 1;

}


long int taille_arete(long int **g,long int s,long j)
{
	puts("taille arete");
	long int i;
	long int cmp=0;
	for(i=0;i<s;i++)
	{
		if(g[i][j]==1)
			cmp++;

	}
	puts("fin taille arete");
	return cmp;

}

void afficher(long int**g,long int s,long int h)
{
	long int i,j;
	for(i=0;i<s;i++)
	{
		for(j=0;j<h;j++)
		{
			printf("%ld,",g[i][j]);
		}
		puts("");
	}

}















