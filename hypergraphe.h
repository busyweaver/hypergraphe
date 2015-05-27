#ifndef __HYPERGRAPHE__
#define __HYPERGRAPHE__




#include <stdio.h>
#include <stdlib.h>



double nombre_aleatoire();
long int** creation_hypergraphe(long int sommets,long int hyperaretes);
void generation_aleatoire(long int**g,long int sommets,long int hyperaretes,float proba);
int grahpe_est_simple(long int **g,long int s,long int h);
int verifier(long int*arete,long int**g,long int s,long int deb,long int h);
int est_egal(long int* arete,long int**g,long int s,long int j);
void arete_courante(long int**g,long int s,long int j,long int* arete);
int taille_aretes_ok(long int **g,long int s,long int h);
long int taille_arete(long int **g,long int s,long j);
void afficher(long int**g,long int s,long int h);



#endif