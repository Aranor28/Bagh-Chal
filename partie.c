#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "partie.h"
#include "main.h"

bool partie_cases_adjacentes (int x1, int y1, int x2, int y2) {
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

int partie_detection_vainqueur () {
	if (plateau.joueur_courant == TIGRE) {
		debug("ici", 0);
		if (plateau.nb_chevres_mangees >= 7)
			return(TIGRE);
		else if (partie_chevres_bloquees())
			return(CHEVRE);
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
	x1 = (x == 0) ? 0 : x-1;
	y1 = (y == 0) ? 0 : y-1;
	x2 = (x == 4) ? 4 : x+1;
	y2 = (y == 4) ? 4 : y+1;

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

bool partie_chevres_bloquees () {
	int i, j, temp1, temp2;

	for (i=0; i< NB_CASES_X ;i++){
		for (j=0 ; j < NB_CASES_Y ; j++){
			/* On choisi de parcourir les cases vides plutot que les chèvres 
			 * car si les chèvres sont bloquées il y a surement plus de chèvres
			 * que de cases vides */
			if (plateau.grille[i][j] == VIDE && partie_pion_adjacent(i, j, CHEVRE, &temp1, &temp2))
				return(false);
		}
	}
	return(true);
}

bool partie_pion_adjacent (int x, int y, int type, int * x_pion, int * y_pion) {
	int i, j, depart_x, depart_y, fin_x, fin_y;
	bool acces_diag = ((x + y) % 2 == 0);

	depart_x = (x == 0) ? 0 : x-1;
	depart_y = (y == 0) ? 0 : y-1;
	fin_x = (x == 4) ? 4 : x+1;
	fin_y = (y == 4) ? 4 : y+1;

	for (i = depart_x; i <= fin_x; i++) {
		for (j = depart_y; j <= fin_y; j++) {
			if ((i == x || j == y || acces_diag) && plateau.grille[i][j] == type) { // corriger l'ordre ailleur
				*x_pion = i;
				*y_pion = j;
				return(true);
			}
		}
	}
	return(false);
}