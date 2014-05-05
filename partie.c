#include <stdlib.h>
#include "partie.h"
#include "main.h"

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
				if (plateau.grille[i][j] == TIGRE && partie_tigre_bloque(i, j))
					cpt_tigres_bloques++;
			}
		}
		return(cpt_tigres_bloques == 4);
	}
}

bool partie_tigre_bloque (int x, int y) {
	int x1, y1, x2, y2;
	x1 = (x - 1 < 0) ? -1 : x-1;
	y1 = (y - 1 < 0) ? -1 : y-1;
	x2 = (x + 1 > 4) ? -1 : x+1;
	y2 = (y + 1 > 4) ? -1 : y+1;

	if (x1 > 0 && plateau.grille[x1][y] == VIDE)
		return(false);
	else if (y1 > 0 && plateau.grille[x][y1] == VIDE)
		return(false);
	else if (x2 > 0 && plateau.grille[x2][y] == VIDE)
		return(false);
	else if (y2 > 0 && plateau.grille[x][y2] == VIDE)
		return(false);
	else if ((x1 + y1) % 2 == 0) {
		if (x1 > 0 && y1 > 0 && plateau.grille[x1][y1] == VIDE)
			return(false);
		else if (x1 > 0 && y2 > 0 && plateau.grille[x1][y2] == VIDE)
			return(false);
		else if (x2 > 0 && y2 > 0 && plateau.grille[x2][y2] == VIDE)
			return(false);
		else if (x2 > 0 && y1 > 0 && plateau.grille[x2][y1] == VIDE)
			return(false);
	}
	return(true);
}