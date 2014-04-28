#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <assert.h>
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

	int x_grille, y_grille;
	int retour;
	while (plateau.nb_chevres_placees < 20){
		/* l'utilisateur doit pouvoir à partir de maintenant 
		   placer une chèvre, quitter, sauvegarder, charger une autre partie.
		   On veut donc tou d'abord récupérer un clic de souris
		*/
		retour = ES_recuperer_action(&x_grille, &y_grille); // récupère le type de case cliquée et ses coordonnées sur la grille

		if (retour == SAUVEGARDER) {
			sauvegarder_partie();
			debug("sauvegarde effectuée.");
		}
		else if (retour == CHARGER) {
			charger_partie(NOM_FICHIER_SAUVEGARDE);
			debug("chargement effectué.");
		}
		if (plateau.joueur_courant == CHEVRE) {
			if (plateau.phase == PLACEMENT && retour == VIDE) {
				chevre_placement(x_grille, y_grille);
				main_joueur_suivant();
			}
			else if (plateau.phase == DEPLACEMENT && retour == CHEVRE) {
				// déplacer chèvre
			}
		}
		else {
			if (retour == TIGRE) {
				tigre_deplacement(x_grille, y_grille);
				main_joueur_suivant();
			}
		}
		affichage();

		// verification_placement_chevre(&chevre_placee);
		// affichage_pion();
		// affichage_info(chevre_placee, chevre_mangee,JOUEUR_TIGRE);

		// refresh();
		// verification_deplacement_tigre(&chevre_mangee);
		// affichage_pion();
		// affichage_info(chevre_placee, chevre_mangee,JOUEUR_CHEVRE);
		// refresh();
		// detection_fin_partie(chevre_mangee,0);
		//getch();
	}  

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

void debug (char str[]) {
	mvprintw(Y_CHAMP_ERREUR, X_CHAMP_ERREUR, "debug: %s", str);
	refresh();
}