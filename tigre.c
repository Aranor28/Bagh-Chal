#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tigre.h"
#include "main.h"
#include "entree_souris.h"
#include "affichage.h"
#include "partie.h"

void tigre_deplacement (int x1, int y1) {
	affichage_surbrillance (x1, y1);

	int x2, y2, retour_case;
	while (1) {
		retour_case = ES_recuperer_action(&x2, &y2);
		if (retour_case == VIDE) {
			if (cases_adjacentes(x1, y1, x2, y2)) {
				plateau.grille[x1][y1] = VIDE;
				plateau.grille[x2][y2] = TIGRE;
				return;
			}
			else if (saute_chevre(x1, y1, x2, y2)) {
				plateau.grille[x1][y1] = VIDE;
				plateau.grille[x2][y2] = TIGRE;
				plateau.grille[(x1+x2)/2][(y1+y2)/2] = VIDE; // la chèvre est mangée
				plateau.nb_chevres_mangees++;
				return;
			}
		}
	}	
}

bool saute_chevre (int x1, int y1, int x2, int y2) {
	if (plateau.grille[(x1+x2)/2][(y1+y2)/2] != CHEVRE) // si il n'y a pas de chevre entre les cases
		return false;

	if ((abs(x1-x2) == 0 && abs(y1-y2) == 2) || (abs(x1-x2) == 2 && abs(y1-y2) == 0)) { // si déplacement "carré" de 2
		return true;
	}

	if ((x1 + y1) % 2 == 0 && (abs(x1-x2) == 2 && abs(y1-y2) == 2)) {
		// Si la case a accès aux diagonales et à fait un déplacement diagonal de 2
		return true;
		}
	return false;
}