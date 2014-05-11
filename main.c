#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <stdbool.h>
#include <unistd.h>

#include "main.h"
#include "affichage.h"
#include "entree_souris.h"
#include "partie.h"
#include "tigre.h"
#include "chevre.h"
#include "sauvegarde.h"
#include "chargement.h"
#include "ia_tigre.h"
#include "ia_chevre.h"

int main () {
	int x_grille, y_grille;
	int gagnant = VIDE; // == 0
	int retour = VIDE;
	bool ia_chevre = false;
	bool ia_tigre = false;

	main_initialisation();
	PlateauBC plateauAvant = plateau; // servira pour annuler le dèrnier coup joué

	/* Première boucle, affiche le menu et récupère le choix du type de partie */
	do {
		affichage_menu ();
		retour = ES_recuperer_choix_menu();

		switch(retour) {
			/* rien à faire dans le cas joueur contre joueur, les booléens des ia sont déjà à false */
			case IA_TIGRE:
				ia_tigre = true;
				break;

			case IA_CHEVRE:
				ia_chevre = true;
				break;
				
			case AIDE:
				affichage_aide();
				getch();
				clear();
				break;
		}
	} while(retour == VIDE || retour == AIDE);

	clear(); 
	affichage();
	affichage_ligne_info("Début de la partie");
	refresh();
	
	/* Boucle principale du programme */
	while (!gagnant) {
		/* Si c'est au tour d'un joueur humain */
		if ((plateau.joueur_courant == TIGRE && !ia_tigre) || (plateau.joueur_courant == CHEVRE && !ia_chevre)) {
			
			/* On récupère le type de case cliquée et ses coordonnées sur la grille */
			retour = ES_recuperer_action(&x_grille, &y_grille); 

			affichage_vider_info();
			if (retour == SAUVEGARDER) {
				sauvegarder_partie();
				affichage_ligne_info("Sauvegarde effectuée");
			}
			else if (retour == CHARGER) {
				plateauAvant = plateau; // On peut ainsi revenir en arrière si le chargement était une erreur
				charger_partie(NOM_FICHIER_SAUVEGARDE);
				affichage_ligne_info("Chargement effectué");
			}
			else if (retour == ANNULER) {
				/* On rétablit le plateau à l'état qu'il était au tour précédent (de joueur humain) */
				plateau = plateauAvant;
			}
			else if (retour == QUITTER) {
				endwin();
				return 0;
			}
			else if (retour == AIDE) {
				affichage_aide();
				getch();
				clear();
			}
			else { // On gère les cas de jeu sur la grille
				if (plateau.joueur_courant == CHEVRE && plateau.phase == PLACEMENT && retour == VIDE) {
					chevre_placement(x_grille, y_grille, &gagnant, &plateauAvant);
				}
				else if (plateau.joueur_courant == CHEVRE && plateau.phase == DEPLACEMENT && retour == CHEVRE) {
					chevre_deplacement(x_grille, y_grille, &gagnant, &plateauAvant);
				}
				else if (plateau.joueur_courant == TIGRE && retour == TIGRE) { // Tour des tigres
					tigre_deplacement(x_grille, y_grille, &gagnant, &plateauAvant);
				}
				affichage_vider_info();
			}
		}
		else { // c'est au tour d'un joueur IA
			sleep(1); // le temps de jeu de l'IA, délai de une seconde

			if (ia_chevre && plateau.phase == PLACEMENT) {
				ia_chevre_placement();
			}
			else if (ia_chevre && plateau.phase == DEPLACEMENT) {
				ia_chevre_deplacement();
			}
			else if (ia_tigre) {
				ia_tigre_deplacement();
			}
			/* À l'inverse du tour d'un joueur humain, le fonction de jeu de l'ia
			 * ne modifient pas la variable gagnant et ne passent pas au tour suivant,
			 * on le fait à la suite */
			gagnant = partie_detection_vainqueur();
			main_joueur_suivant();
		}

		if (plateau.nb_chevres_placees == 20) {
			plateau.phase = DEPLACEMENT;
		}
		affichage();
	}
	affichage_gagnant (gagnant);
	getch();
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
	int i, j;
	for (i=0; i < 5; i++) {
		for (j=0; j < 5; j++) {
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