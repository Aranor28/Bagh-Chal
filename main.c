#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <assert.h>
#include <stdbool.h>
#include "main.h"

#include "affichage.h"
#include "tigre.h"
#include "chevre.h"
#include "partie.h"
#include "entree_souris.h"
#include "sauvegarde.h"
#include "chargement.h"

int main () {
	main_initialisation();
	affichage();

	int gagnant = VIDE; // == 0
	int x_grille, y_grille;
	int retour;

	affichage_ligne_info("Début de la partie");

	while (!gagnant){
		/* l'utilisateur doit pouvoir à partir de maintenant
		placer une chèvre, quitter, sauvegarder, charger une autre partie.
		On veut donc tou d'abord récupérer un clic de souris
		*/
		retour = ES_recuperer_action(&x_grille, &y_grille); // récupère le type de case cliquée et ses coordonnées sur la grille

		if (retour == SAUVEGARDER) {
			sauvegarder_partie();
		}
		else if (retour == CHARGER) {
			charger_partie(NOM_FICHIER_SAUVEGARDE);
		}
		else if (retour == ANNULER) {
			// annuler dernier coup
		}
		else {
			if (plateau.joueur_courant == CHEVRE) {
				if (plateau.phase == PLACEMENT && retour == VIDE) {
					chevre_placement(x_grille, y_grille);
					gagnant = partie_detection_vainqueur();
				}
				else if (plateau.phase == DEPLACEMENT && retour == CHEVRE) {
					chevre_deplacement(x_grille, y_grille);
					gagnant = partie_detection_vainqueur();
				}
			}
			else { // joueur_courant == TIGRE
				if (retour == TIGRE) {
					tigre_deplacement(x_grille, y_grille);
					gagnant = partie_detection_vainqueur();
				}
			}
		}

		if (plateau.nb_chevres_placees == 20) {
			plateau.phase = DEPLACEMENT;
		}
		affichage();
	}
	affichage_gagnant (gagnant);
	getch();
	/* Fermeture de Ncurses */
	endwin();

	return 0;
}

void main_initialisation () {
	/* Initialisation de la structure PlateauBC */
	plateau.nb_chevres_placees = 0;
	plateau.nb_chevres_mangees = 0;
	plateau.joueur_courant = CHEVRE;
	plateau.phase = PLACEMENT;

	/* Initialisation de la grille
	* Place les tigres dans les angles et met à VIDE
	* les autres cases */
	int i,j;
	for (i=0; i < NB_CASES_X; i++) {
		for (j=0; j < NB_CASES_Y; j++) {
			plateau.grille[i][j] = VIDE;
		}
	}
	plateau.grille[0][4] = TIGRE;
	plateau.grille[0][0] = TIGRE;
	plateau.grille[4][0] = TIGRE;
	plateau.grille[4][4] = TIGRE;

	/* Initialisation de Ncurses */
	clear();
	initscr();
	curs_set(0);
	noecho();
	start_color();

	/* Initialisation des différentes paires de couleurs qui vont être utilisées */
	affichage_init_color_pairs();
}

/* Passe au joueur suivant */
void main_joueur_suivant () {
	if (plateau.joueur_courant == CHEVRE)
		plateau.joueur_courant = TIGRE;
	else
		plateau.joueur_courant = CHEVRE;
}

void main_verifier_extra_cases (int choix) {
// servira à vérifier si le joueur a cliqué sur quitter, sauvegarder, chager
}

void debug (char str[], int n) {
	mvprintw(Y_CHAMP_ERREUR, X_CHAMP_ERREUR, "debug: %s [%d]", str, n);
	refresh();
}