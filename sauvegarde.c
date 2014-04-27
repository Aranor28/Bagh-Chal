#include <stdio.h>
#include "sauvegarde.h"
#include "main.h"

/* AFFICHE DANS LE FICHIER DE SAUVEGARDE :
 * LE PLATEAU LIGNE PAR LIGNE
 * LE NOMBRE DE CHEVRES PLACEES
 * LE NOMBRE DE CHEVRES MANGEES
 * LE TOUR DU JOUEUR SUIVANT
 */
void sauvegarde (int tigre_bloque, int phase, int joueur){
	int i,j;

printf("ici\n");
	FILE * fich = fopen("sauvegarde.txt","w");
	if (fich == NULL){
		fprintf(stderr, "Erreur lors de la sauvegarde du plateau\n");
		return;
	}
	fprintf(fich, "\\board \n");
	for (i = 0; i < 5; i++){
		for (j = 0; j < 5; j++)	{
			if (plateau[i][j] == TIGRE)
				fprintf(fich,"T");
			else if (plateau[i][j] == CHEVRE)
				fprintf(fich, "G");
			else if (plateau[i][j] == VIDE)
				fprintf(fich, ".");
		}
		fprintf(fich,"\n");
	}
	fprintf(fich, "\\endboard\n");
	if (joueur == TIGRE)
		fprintf(fich,"\\player T\n");
	else
		fprintf(fich,"\\player G\n");

	fprintf(fich,"\\phase %d\n",phase);
	fprintf(fich,"\\captured %d\n",tigre_bloque);
	fclose(fich);
	
}