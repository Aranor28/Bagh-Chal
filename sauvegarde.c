#include <stdio.h>
#include "sauvegarde.h"
#include "main.h"

/* AFFICHE DANS LE FICHIER DE SAUVEGARDE :
 * LE PLATEAU LIGNE PAR LIGNE
 * LE NOMBRE DE CHEVRES PLACEES
 * LE NOMBRE DE CHEVRES MANGEES
 * LE TOUR DU JOUEUR SUIVANT
 */
void sauvegarder_partie () {
	int i,j;

	FILE * fich = fopen(NOM_FICHIER_SAUVEGARDE, "w");
	if (fich == NULL){
		fprintf(stderr, "Erreur lors de la sauvegarde du plateau\n");
		return;
	}
	fprintf(fich, "\\board\n");
	for (j = 0; j < 5; j++){
		for (i = 0; i < 5; i++)	{
			if (plateau.grille[i][j] == TIGRE)
				fprintf(fich,"T");
			else if (plateau.grille[i][j] == CHEVRE)
				fprintf(fich, "G");
			else if (plateau.grille[i][j] == VIDE)
				fprintf(fich, ".");
		}
		fprintf(fich,"\n");
	}
	fprintf(fich, "\\endboard\n");
	if (plateau.joueur_courant == TIGRE)
		fprintf(fich,"\\player T\n");
	else
		fprintf(fich,"\\player G\n");

	fprintf(fich,"\\phase %d\n", plateau.phase);
	fprintf(fich,"\\captured %d\n", plateau.nb_chevres_mangees);
	fclose(fich);
}