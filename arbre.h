#include <stdio.h>
#include <stdlib.h>

typedef  struct arbre{
	int val;
	struct arbre *sag;
	struct arbre *sad;
} NOEUD, *ARBRE;

void parcours_pre_g(ARBRE);

ARBRE 	inserer(ARBRE, int);
ARBRE 	saisir(ARBRE, int);



int niveau_moins_profond(ARBRE);
int minimum(int, int);
int nbre_solitaire(ARBRE);
int plus_fourni(ARBRE);
int compt_noeud(ARBRE);