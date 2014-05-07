#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "partie.h"
#include "main.h"

bool cases_adjacentes (int x1, int y1, int x2, int y2) {
	if ((abs(x1-x2) == 1 && abs(y1-y2) == 0) || (abs(x1-x2) == 0 && abs(y1-y2) == 1)) {// si déplacement "carré" de 1
		return true;
	}
	else if ((x1 + y1) % 2 == 0) { // si la case de départ a accès aux diagonales de la grille
		if (abs(x1-x2) == 1 && abs(y1-y2) == 1) {
			return true;
		}
	}
	return false;
}

void detection_fin_partie (int nb_chevre_mangee, int nb_tigre_bloque){
	if (nb_chevre_mangee == 7)
		exit(1);
	if (nb_tigre_bloque == 4)
		exit(2);
}

int partie_detection_vainqueur () {
	if (plateau.joueur_courant == TIGRE) {
		if (plateau.nb_chevres_mangees >= 7)
			return(TIGRE);
		else
			return(VIDE);
	}
	else { // joueur_courant == CHEVRE
		int cpt_tigres_bloques = 0;
		for (int j=0; j < NB_CASES_Y; j++) {
			for (int i=0; i < NB_CASES_X; i++) {
				if (plateau.grille[i][j] == TIGRE && partie_tigre_bloque(i, j)) {
					cpt_tigres_bloques++;
				}
			}
		}
		if (cpt_tigres_bloques == 4)
			return(CHEVRE);
		else
			return(VIDE);
	}
}

bool partie_tigre_bloque (int x, int y) {
	int x1, y1, x2, y2, i, j;
	bool acces_diag = ((x + y) % 2 == 0);
	x1 = (x - 1 < 0) ? x : x-1;
	y1 = (y - 1 < 0) ? y : y-1;
	x2 = (x + 1 > 4) ? x : x+1;
	y2 = (y + 1 > 4) ? y : y+1;

	for (i = x1; i <= x2; i++) {
		for (j = y1; j <= y2; j++) {
			if (i != x || j != y) { // si on est pas sur la case centrale
				if (acces_diag || i == x || j == y) { // si on a accès aux diagonales où qu'on est pas sur une diag
					if (plateau.grille[i][j] == VIDE) {
						return(false);
					}
					else if (plateau.grille[i][j] == CHEVRE && partie_prolongation_vide(x, y, i, j))
						return(false);
				}
			}
		}
	}
	return(true);
}

bool partie_prolongation_vide (int x1, int y1, int x2, int y2) {
	int x3 = x1 + 2*(x2-x1);
	int y3 = y1 + 2*(y2-y1);

	return((x3 >= 0 && x3 <= 4) && (y3 >= 0 && y3 <= 4) && (plateau.grille[x3][y3] == VIDE));
}