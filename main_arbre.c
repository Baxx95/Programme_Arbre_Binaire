#include "arbre.h"

int main(){

	ARBRE a,b = NULL;
	
	b = saisir(a, 5);

	printf("le profondeur de l'arbre est : %d\n",niveau_moins_profond(b));
	printf("le nombre de noeud qui n'ont pas de frere de l'arbre est : %d\n",nbre_solitaire(b));

	if(plus_fourni(b) == 1)
		printf("le sous arbre le plus fourni est celui de gauche\n");
	else
		printf("le sous arbre le plus fourni est celui de droite\n");

	return 0;
}