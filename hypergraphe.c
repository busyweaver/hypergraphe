#include "hypergraphe.h"
#include <stdlib.h>
#include <time.h> 
#include <math.h> 




/*genere un nombre aleatoire entre 0 et 1*/
double nombre_aleatoire()
{
    return ( rand()/(double)RAND_MAX );
}


void liberer_graphe(long int **g,long int s)
{
	long int i;
	for(i=0;i<s;i++)
	{
		free(g[i]);
	}
	free(g);
}





long int** creation_hypergraphe(long int sommets,long int hyperaretes)
{
	/*puts("creation graphe");*/
	long int** g=NULL;
	long int i=0;
	g=(long int**)malloc(sommets*sizeof(long int*));
	for(i=0;i<sommets;i++)
		g[i]=(long int*)malloc(hyperaretes*sizeof(long int));

	/*puts("fin creation graphe");*/
	return g;

}

/*generation d'un hypergraphe aleatoire en remplissant sa matrice d'incidence avec des variables aleatoire de bernoulli iid*/
void generation_aleatoire(long int**g,long int sommets,long int hyperaretes,long double proba)
{
	/*puts("generation aleatoire");*/
	long int i,j;
	double alea;
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
	/*puts("fin generation aleatoire");*/
}


int grahpe_type(long int **g,long int s,long int h,int type)
{
	/*puts("grahpe type");*/
	if(taille_aretes_ok(g,s,h)==0)
		return 0;
	int collision;
	long int *arete=NULL;
	arete = (long int *) malloc(s*sizeof(long int));
	long int j;
	for(j=0;j<h-1;j++)
	{
		arete_courante(g,s,j,arete);
		/*printf("verification arete %ld\n",j);*/
		if(type==1)
			collision = est_simple(arete,g,s,j+1,h);
		else
			collision = est_sperner(arete,g,s,j+1,h);		
		if(!collision)
		{
			return 0;

		}
	}
	/*puts("fin grahpe type");*/
	return 1;
}


int est_simple(long int*arete,long int**g,long int s,long int deb,long int h)
{

	long int j;
	for(j=deb;j<h;j++)
	{
		if(est_egal(arete,g,s,j))
		{
			/*printf("collision... avec %ld\n",j);*/
			return 0;
		}

	}

	return 1;
}

int est_egal(long int* arete,long int**g,long int s,long int j)
{

	long int i;
	for(i=0;i<s;i++)
	{
		if(arete[i]!=g[i][j])
		{
			return 0;
		}
	}

	return 1;

}



void arete_courante(long int**g,long int s,long int j,long int* arete)
{

	long int i;
	for(i=0;i<s;i++)
		arete[i] = g[i][j];

}



int taille_aretes_ok(long int **g,long int s,long int h)
{

	long int j;
	long int t;
	for(j=0;j<h;j++)
	{
		t = taille_arete(g,s,j);
		if(t<2)
			return 0;
	}

	return 1;

}


long int taille_arete(long int **g,long int s,long j)
{

	long int i;
	long int cmp=0;
	for(i=0;i<s;i++)
	{
		if(g[i][j]==1)
			cmp++;

	}
	/*printf("taille arete %ld = %ld\n",j,cmp);*/

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




int est_sperner(long int*arete,long int**g,long int s,long int indice,long int h)
{
	indice=indice-1;

	long int j;
	for(j=0;j<h;j++)
	{
		if(j!=indice)
		{
			if(est_inclus_dans(arete,g,s,j))
			{
				/*printf("est inclus ... dans %ld\n",j);*/
				return 0;
			}
		}

	}

	return 1;
}

int est_inclus_dans(long int *arete,long int**g,long int s,long int j)
{
	

	long int i;
	for(i=0;i<s;i++)
	{
		if(arete[i]==1)
		{
			if(g[i][j]!=1)
			{
				return 0;
			}

		}
		
	}

	return 1;	


}


long double proba_theorique(long int sommets,long int aretes,long double p)
{
	long double produit=1;
	long int k;
	long double coeff;
	for(k=1;k<=aretes;k++)
	{

	coeff = (k*pow((1+((2*p)*(p-1))),sommets));
	produit = produit * ((1-((pow((1-p),sommets))+(sommets*(p*(pow((1-p),sommets-1))))))-coeff);
	/*produit=produit*((1)-(k*pow((double)(1+(2*p)*(p-1)),(double)sommets)));*/
	}
	return produit;



}


















