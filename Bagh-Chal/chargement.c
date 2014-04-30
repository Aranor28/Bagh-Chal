#include <stdio.h>
#include <string.h>
#include "main.h"
#include "chargement.h"

// a modifier pour récupérer le nombre de chevres qu'il reste à placer si phase placement

int charger_partie (char * nomFich) {
	int i, j;
	char temp;
	char chaine[13];

	FILE * fich = fopen(nomFich, "r");
	if (fich == NULL){
		fprintf(stderr, "Erreur lors de l'ouverture du fichier\n");
		return (1);
	}

	fscanf(fich, "%s", chaine);
	if (strcmp(chaine, "\\board")){
		fprintf(stderr, "Erreur de fichier sur board\n");
		return (1);
	}

	int cpt_chevres = 0;
	for (j = 0; j < NB_CASES_Y; j++) {
		fscanf(fich, "%s", chaine);
		for (i = 0; i < NB_CASES_X; i++) {
			if ( chaine[i] == 'T')
				plateau.grille[i][j] = TIGRE;
			else if (chaine[i] == 'G') {
				plateau.grille[i][j] = CHEVRE;
				cpt_chevres++;
			}
			else if (chaine[i] == '.')
				plateau.grille[i][j] = VIDE;
			else
				debug("caractere invalide");
		}
	}

	/*VERIFICATION QUE LE TABLEAU SE FINIT PAR \endboard\n*/
	fscanf(fich, "%s", chaine);
	if (strcmp(chaine, "\\endboard")){
		fprintf(stderr, "Erreur de fichier sur endboard\n");
		return (1);
	}

	/*VERIFICATION DU JOUEUR*/
	fscanf(fich, "%s ", chaine);
	if (strcmp(chaine, "\\player")){
		fprintf(stderr, "Erreur de fichier sur player\n");
		return (1);
	}

	temp = fgetc(fich);
	if (temp != 'T' && temp != 'G'){
		fprintf(stderr, "Erreur de joueur\n");
		return (1);
	}
	if (temp == 'T')
		plateau.joueur_courant = TIGRE;
	else
		plateau.joueur_courant = CHEVRE;

	/*VERIFICATION DE LA PHASE*/
	fscanf(fich, "%s ", chaine);
	if (strcmp(chaine, "\\phase")){
		fprintf(stderr, "Erreur de fichier sur phase\n");
		return (1);
	}
	fscanf(fich, "%d", &(plateau.phase));
	if (plateau.phase != PLACEMENT && plateau.phase != DEPLACEMENT){
		fprintf(stderr, "Erreur de fichier\n");
		return (1);
	}

	/*VERIFICATION DES CHEVRES CAPTUREES*/
	fscanf(fich, "%s ", chaine);
	if (strcmp(chaine, "\\captured")){
		fprintf(stderr, "Erreur de fichier sur captured\n");
		return (1);
	}
	fscanf(fich, "%d", &(plateau.nb_chevres_mangees));
	if (plateau.nb_chevres_mangees < 0 && plateau.nb_chevres_mangees > 20) { // >= 20 plutot ?
		fprintf(stderr, "Erreur de fichier sur le nombre de chevres capturées\n");
		return (1);
	}

	if (plateau.phase == 1) {
		plateau.nb_chevres_placees = cpt_chevres + plateau.nb_chevres_mangees;
	}
	return (0);
}

