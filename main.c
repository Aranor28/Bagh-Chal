#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <assert.h>
#include <stdbool.h>
#include <unistd.h>
#include "main.h"

#include "affichage.h"
#include "tigre.h"
#include "chevre.h"
#include "partie.h"
#include "entree_souris.h"
#include "sauvegarde.h"
#include "chargement.h"
#include "ia_tigre.h"
#include "ia_chevre.h"

int main () {
	int gagnant = VIDE; // == 0
	int x_grille, y_grille;
	int retour = VIDE;
	bool ia_chevre = false, ia_tigre = false;

	main_initialisation();
	PlateauBC plateauAvant = plateau;

	do {
		affichage_menu ();
		retour = ES_recuperer_choix_menu();

		switch(retour) {
			case JCJ:
				// rien à faire, les ia sont déjà à false
				break;

			case IA_TIGRE:
				ia_tigre = true;
				break;

			case IA_CHEVRE:
				ia_chevre = true;
				break;
				
			case AIDE:
				affichage_aide ();
				getch();
				clear();
				/* Revenir a l'affichage du menu ? */
				break;
		}
	} while(retour == VIDE || retour == AIDE);


	clear(); 
	affichage();
	// pour tester
	affichage_ligne_info("Début de la partie");
	
	while (!gagnant){
		/* l'utilisateur doit pouvoir à partir de maintenant
		placer une chèvre, quitter, sauvegarder, charger une autre partie.
		On veut donc tou d'abord récupérer un clic de souris
		*/
		retour = ES_recuperer_action(&x_grille, &y_grille); // récupère le type de case cliquée et ses coordonnées sur la grille

		if (retour == SAUVEGARDER) {
			affichage_vider_info();
			sauvegarder_partie();
			affichage_ligne_info("Sauvegarde effectuée");
		}
		else if (retour == CHARGER) {
			affichage_vider_info();
			charger_partie(NOM_FICHIER_SAUVEGARDE);
			affichage_ligne_info("Chargement effectué");
		}
		else if (retour == ANNULER) {
			affichage_vider_info();
			plateau = plateauAvant;
		}
		else if (retour == QUITTER) {
			sleep(1);
			endwin();
			return 0;
		}
		else if (retour == AIDE) {
			affichage_vider_info();
			affichage_aide();
			getch();
			clear();
		}
		else {
			affichage_vider_info();
			if (plateau.joueur_courant == CHEVRE) { // Tour des chèvres
				if (ia_chevre && plateau.phase == PLACEMENT) {
					ia_chevre_placement();
					gagnant = partie_detection_vainqueur();
					main_joueur_suivant();
				}
				else if (ia_chevre && plateau.phase == DEPLACEMENT) {
					ia_chevre_deplacement();
					gagnant = partie_detection_vainqueur();
					main_joueur_suivant();
				}
				else { // pas ia
					if (plateau.phase == PLACEMENT && retour == VIDE) {
						plateauAvant = plateau;
						chevre_placement(x_grille, y_grille, &gagnant);
					}
					else if (plateau.phase == DEPLACEMENT && retour == CHEVRE) {
						plateauAvant = plateau;
						chevre_deplacement(x_grille, y_grille, &gagnant);
					}
				}
			}
			else { // Tour des tigres
				if (ia_tigre){
					ia_tigre_deplacement();
					gagnant = partie_detection_vainqueur();
					main_joueur_suivant();
				}
				else if (retour == TIGRE && !ia_tigre) {
					plateauAvant = plateau;
					tigre_deplacement(x_grille, y_grille, &gagnant);
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