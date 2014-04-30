#include <stdio.h>
#include <assert.h>
#include "chevre.h"
#include "main.h"
#include "affichage.h"
#include "entree_souris.h"

/* Place une chèvre aux coordonnées x, y */
void chevre_placement (int x, int y) {
	/* On vérifie que la case soit valide (elle doit l'être, d'où le assert) */
	assert(x >= 0 && x <= 4 && y >= 0 && y <= 4 && plateau.grille[x][y] == VIDE);
	plateau.grille[x][y] = CHEVRE;
	plateau.nb_chevres_placees++;
}

void chevre_deplacement (int x1, int y1) {
	affichage_surbrillance (x1, y1);

	int x2, y2, retour_case;
	while (1) {
		retour_case = ES_recuperer_action(&x2, &y2);
		if (retour_case == VIDE && cases_adjacentes(x1, y1, x2, y2)) {
			plateau.grille[x1][y1] = VIDE;
			plateau.grille[x2][y2] = CHEVRE;
			return;
		}
	}	
}


