#include "arbre.h"

/*----------------------------------------------------------------------------------------*/
int minimum(int x, int y){
	return	x<y?x:y;
};
/*------------------------------------ QUESTION 1 ---------------------------------------*/
int niveau_moins_profond(ARBRE a){
	if(a == NULL)
		return 0;
	else
		return(1+minimum(niveau_moins_profond(a->sag),niveau_moins_profond(a->sad)));
}
/*------------------------------------- QUESTION 2 -------------------------------------*/
int nbre_solitaire(ARBRE a){

	if(a == NULL)
		return 0;
	else{
		if(a->sag == NULL && a->sad != NULL)
			return	1+nbre_solitaire(a->sad);
		else
			if(a->sag != NULL && a->sad == NULL)
				return	1+nbre_solitaire(a->sag);
		else
			return nbre_solitaire(a->sag) + nbre_solitaire(a->sad);		
	}
}
/*--------------------- utiliser dans la fonction plus_fourni -----------------------------*/
int compt_noeud(ARBRE a){
	if(a == NULL)
		return 0;
	else
		return (1 + compt_noeud(a->sag) + compt_noeud(a->sad));
}
/*------------------------------------ QUESTION 3 -----------------------------------------*/
int 	plus_fourni(ARBRE a){
	if(a == NULL)
		return -1;
	else
		return compt_noeud(a->sag) > compt_noeud(a->sad) ? 1 : 0;
}
/*--------------------------------Affichage----------------------------------------*/
void parcours_pre_g(ARBRE a){
	if(a!=NULL){
		printf("%d\n",a->val);
		parcours_pre_g(a->sag);
		parcours_pre_g(a->sad);
	}
}
/*----------------------------------------------------------------------------------------*/
ARBRE inserer(ARBRE racine, int valeur){
	ARBRE p;

	p = (ARBRE)malloc(sizeof(NOEUD));
	p->val = valeur;
	p->sag = p->sad = NULL;
	if(racine == NULL) return p;
	else if(valeur <= racine->val)racine->sag=inserer(racine->sag,valeur);
	else racine->sad = inserer(racine->sad, valeur);
   return racine;
}
/*----------------------------------------------------------------------------------------*/
ARBRE 	saisir(ARBRE a, int n){
	int valeur;
	for (int i = 0; i < n; ++i){
		printf("donner la valeur : ");
		scanf("%d", &valeur);
		a = inserer(a, valeur);
	}
	return a;
}
/*----------------------------------------------------------------------------------------*/