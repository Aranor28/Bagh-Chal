#include <stdio.h>
#include <assert.h>
#include "chevre.h"
#include "main.h"

/* Place une chèvre aux coordonnées x, y */
void chevre_placement (int x, int y) {
	/* On vérifie que la case soit valide (elle doit l'être, d'où le assert) */
	assert(x >= 0 && x <= 4 && y >= 0 && y <= 4 && plateau.grille[x][y] == VIDE);
	plateau.grille[x][y] = CHEVRE;
	plateau.nb_chevres_placees++;
}


