#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

#include "entree_souris.h"
#include "main.h"
#include "affichage.h"

int ES_recuperer_action (int * x_grille, int * y_grille) {
	int x_win, y_win;
	ES_recuperer_entree (&x_win, &y_win);

	/* Si le clic est hors de la grille */
	if (y_win < STARTY || y_win > (STARTY + HEIGHT) || x_win < STARTX || x_win > (STARTX + WIDTH)) {
		if (y_win == Y_SAUVEGARDER && x_win >= X_SAUVEGARDER && x_win <= (X_SAUVEGARDER + strlen(BOUTON_SAUVEGARDER))) {
			// Si on a appuyé sur sauvegarder
			return(SAUVEGARDER);
		}
		else if (y_win == Y_CHARGER && x_win >= X_CHARGER && x_win <= (X_CHARGER + strlen(BOUTON_CHARGER))) {
			// Si on a appuyé sur charger
			return(CHARGER);
		}
		else if (y_win == Y_ANNULER && x_win >= X_ANNULER && x_win <= (X_ANNULER + strlen(BOUTON_ANNULER))) {
			// Si on a appuyé sur charger
			return(ANNULER);
		}
		else if (y_win == Y_QUITTER && x_win >= X_QUITTER && x_win <= (X_QUITTER + strlen(BOUTON_QUITTER))) {
			// Si on a appuyé sur charger
			return(QUITTER);
		}
		else if (y_win == Y_MENU_AIDE && x_win >= X_MENU_AIDE && x_win <= (X_MENU_AIDE + strlen(BOUTON_AFFICHER_AIDE))){
			//Si on veut afficher l'aide
			return(AIDE);
		}
		else {
			// N'importe où ailleur
			return(HORS_PLATEAU);
		}
	}
	else if ((y_win-STARTY) % 4 != 0 || (x_win-STARTX) % 5 > 2) // si dans la grille mais pas une case
		return(PAS_CASE);
	else {
		// on a cliqué sur une case de la grille, on renvoi son type (CHEVRE, TIGRE ou VIDE)
		*x_grille = (x_win-STARTX) / 5;
		*y_grille = (y_win-STARTY) / 4;
		return(plateau.grille[*x_grille][*y_grille]);
	}
}

int ES_recuperer_choix_menu() {
	int x_win, y_win;
	ES_recuperer_entree (&x_win, &y_win);

	if (y_win == Y_MENU_JcJ && x_win >= X_MENU_JcJ && x_win <= (X_MENU_JcJ + strlen(BOUTON_JcJ))) {
		return(JCJ);
	}
	else if (y_win == Y_MENU_JcIA_TIGRE && x_win >= X_MENU_JcIA_TIGRE && x_win <= (X_MENU_JcIA_TIGRE + strlen(BOUTON_JcIA_TIGRE))) {
		return(IA_TIGRE);
	}
	else if (y_win == Y_MENU_JcIA_CHEVRE && x_win >= X_MENU_JcIA_CHEVRE && x_win <= (X_MENU_JcIA_CHEVRE + strlen(BOUTON_JcIA_CHEVRE))) {
		return(IA_CHEVRE);
	}
	else if (y_win == Y_MENU_AIDE && x_win >= X_MENU_AIDE && x_win <= (X_MENU_AIDE + strlen(BOUTON_AFFICHER_AIDE))){
		return(AIDE);
	}
	else {
		return(VIDE);
	}
}
	
void ES_recuperer_entree (int * x_win, int * y_win) {
	int c;
	MEVENT event; // récupèrera l'évènement
	keypad(stdscr, TRUE); // permet de récupérer les entrées souris
	mousemask(ALL_MOUSE_EVENTS, NULL); // permet de récupérer tous les évènements de la souris

	while(1) {
		c = getch(); // récupère une entrée
		if (c == KEY_MOUSE && getmouse(&event) == OK) {
			if (event.bstate & BUTTON1_CLICKED) { // si le bouton gauche a été préssé
				*x_win = event.x;
				*y_win = event.y;
				return;
			}
		}
	}
}

bool ES_dans_plateau (int type) {
	return(type == TIGRE || type == CHEVRE || type == PAS_CASE || type == VIDE);
}

int ES_recuperer_sauvegarde () {
	int x_win, y_win;
	ES_recuperer_entree (&x_win, &y_win);

	if (y_win == Y_EMPL1 && x_win >= X_EMPL1 && x_win <= (X_EMPL1 + strlen(BOUTON_EMPL1))) {
		return(FICH1);
	}
	else if (y_win == Y_EMPL2 && x_win >= X_EMPL2 && x_win <= (X_EMPL2 + strlen(BOUTON_EMPL2))) {
		return(FICH2);
	}
	else if (y_win == Y_EMPL3 && x_win >= X_EMPL3 && x_win <= (X_EMPL3 + strlen(BOUTON_EMPL3))) {
		return(FICH3);
	}
	else if (y_win == Y_SAUVEGARDER && x_win >= X_SAUVEGARDER && x_win <= (X_SAUVEGARDER + strlen(BOUTON_SAUVEGARDER))) {
		return(SAUVEGARDER);
	}
	else if (y_win == Y_ANNULER && x_win >= X_ANNULER && x_win <= (X_ANNULER + strlen(BOUTON_ANNULER))) {
		return(ANNULER);
	}
	else {
		return(VIDE);
	}
}