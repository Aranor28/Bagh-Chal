#include <stdio.h>
#include <string.h>

#include "chargement.h"
#include "main.h"
#include "affichage.h"
#include "entree_souris.h"

int charger_partie () {
	int i, j;
	char temp;
	char chaine[15];
	int retour = VIDE;
	FILE * fich;
	do {
		affichage_emplacements_sauvegarde();
		retour = ES_recuperer_sauvegarde ();
	} while (retour == VIDE);

	switch (retour) {
		case FICH1:
			fich = fopen(NOM_FICHIER_SAUVEGARDE1, "r");
			break;

		case FICH2:
			fich = fopen(NOM_FICHIER_SAUVEGARDE2, "r");
			break;

		case FICH3:
			fich = fopen(NOM_FICHIER_SAUVEGARDE3, "r");
			break;

		case CHARGER:
			return (1);
			break;

		case ANNULER:
			return (1);
			break;
	}
	affichage_emplacements_sauvegarde_vider ();
	if (fich == NULL){
		affichage_ligne_info("Erreur lors de l'ouverture du fichier");
		return (0);
	}

	fscanf(fich, "%s", chaine);
	if (strcmp(chaine, "\\board")) {
		affichage_ligne_info("Erreur de fichier sur board");
		return (0);
	}

	int cpt_chevres = 0;
	for (j = 0; j < 5; j++) {
		fscanf(fich, "%s", chaine);
		for (i = 0; i < 5; i++) {
			if ( chaine[i] == 'T')
				plateau.grille[i][j] = TIGRE;
			else if (chaine[i] == 'G') {
				plateau.grille[i][j] = CHEVRE;
				cpt_chevres++;
			}
			else if (chaine[i] == '.')
				plateau.grille[i][j] = VIDE;
		}
	}

	/*VERIFICATION QUE LE TABLEAU SE FINIT PAR \endboard\n*/
	fscanf(fich, "%s", chaine);
	if (strcmp(chaine, "\\endboard")) {
		affichage_ligne_info("Erreur de fichier sur endboard");
		return (0);
	}

	/*VERIFICATION DU JOUEUR*/
	fscanf(fich, "%s ", chaine);
	if (strcmp(chaine, "\\player")) {
		affichage_ligne_info("Erreur de fichier sur player");
		return (0);
	}

	temp = fgetc(fich);
	if (temp != 'T' && temp != 'G') {
		affichage_ligne_info("Erreur de joueur");
		return (0);
	}
	if (temp == 'T')
		plateau.joueur_courant = TIGRE;
	else
		plateau.joueur_courant = CHEVRE;

	/*VERIFICATION DE LA PHASE*/
	fscanf(fich, "%s ", chaine);
	if (strcmp(chaine, "\\phase")) {
		affichage_ligne_info("Erreur de fichier sur phase");
		return (0);
	}
	fscanf(fich, "%d", &(plateau.phase));
	if (plateau.phase != PLACEMENT && plateau.phase != DEPLACEMENT){
		affichage_ligne_info("Erreur de fichier");
		return (0);
	}

	/*VERIFICATION DES CHEVRES CAPTUREES*/
	fscanf(fich, "%s ", chaine);
	if (strcmp(chaine, "\\captured")){
		affichage_ligne_info("Erreur de fichier sur captured");
		return (0);
	}
	fscanf(fich, "%d", &(plateau.nb_chevres_mangees));
	if (plateau.nb_chevres_mangees < 0 && plateau.nb_chevres_mangees > 20) { // >= 20 plutot ?
		affichage_ligne_info("Erreur de fichier sur le nombre de chevres capturées");
		return (0);
	}
	fclose(fich);

	if (plateau.phase == PLACEMENT) {
		plateau.nb_chevres_placees = cpt_chevres + plateau.nb_chevres_mangees;
	}
	else {
		plateau.nb_chevres_placees = 20;
	}
	affichage_ligne_info("Chargement effectué");
	return (1);
}

