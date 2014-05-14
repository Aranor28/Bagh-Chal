#include <stdio.h>

#include "sauvegarde.h"
#include "main.h"
#include "affichage.h"
#include "entree_souris.h"

/* AFFICHE DANS LE FICHIER DE SAUVEGARDE :
 * LE PLATEAU LIGNE PAR LIGNE
 * LE NOMBRE DE CHEVRES PLACEES
 * LE NOMBRE DE CHEVRES MANGEES
 * LE TOUR DU JOUEUR SUIVANT
 */
void sauvegarder_partie () {
	int retour = VIDE;
	FILE * fich;
	do {
		affichage_emplacements_sauvegarde();
		retour = ES_recuperer_sauvegarde ();
	} while (retour == VIDE);

	switch (retour) {
		case FICH1:
			fich = fopen(NOM_FICHIER_SAUVEGARDE1, "w");
			break;

		case FICH2:
			fich = fopen(NOM_FICHIER_SAUVEGARDE2, "w");
			break;

		case FICH3:
			fich = fopen(NOM_FICHIER_SAUVEGARDE3, "w");
			break;

		case SAUVEGARDER:
			return;
			break;

		case ANNULER:
			return;
			break;
	}
	affichage_emplacements_sauvegarde_vider ();
	int i,j;

	if (fich == NULL){
		affichage_ligne_info("Erreur lors de la sauvegarde du plateau\n");
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
	affichage_ligne_info("Sauvegarde effectuée");
}