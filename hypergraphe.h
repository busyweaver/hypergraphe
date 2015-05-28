#ifndef __HYPERGRAPHE__
#define __HYPERGRAPHE__




#include <stdio.h>
#include <stdlib.h>



double nombre_aleatoire();
long int** creation_hypergraphe(long int sommets,long int hyperaretes);
void generation_aleatoire(long int**g,long int sommets,long int hyperaretes,long double proba);
int grahpe_type(long int **g,long int s,long int h,int type);
int est_simple(long int*arete,long int**g,long int s,long int deb,long int h);
int est_egal(long int* arete,long int**g,long int s,long int j);
void arete_courante(long int**g,long int s,long int j,long int* arete);
int taille_aretes_ok(long int **g,long int s,long int h);
long int taille_arete(long int **g,long int s,long j);
void afficher(long int**g,long int s,long int h);
void liberer_graphe(long int **g,long int s);
int est_sperner(long int*arete,long int**g,long int s,long int indice,long int h);
int est_inclus_dans(long int *arete,long int**g,long int s,long int j);
long double proba_theorique(long int sommets,long int aretes,long double proba);
long int fact(long int x);
long double coeff_bino(long int n,long int k);



#endif
