#include <stdbool.h>
#include "main.h"
#include "tigre.h"
#include "ia_chevre.h"
#include <stdio.h>
#include <ncurses.h>

void ia_chevre_placement () {
	int i,j;
	for (i=0; i< NB_CASES_X ;i++){
		for (j=0 ; j < NB_CASES_Y ; j++){
			if (plateau.grille[i][j] == VIDE && !ia_chevre_en_danger(i,j)) {
				plateau.grille[i][j] = CHEVRE;
				plateau.nb_chevres_placees++;
				return;
			}
		}
	}
	/* Si aucun emplacement "sûr" n'à été trouvé 
	 * On reboucle et on prend le premier disponible.
	 * Moin coûteux que de mémoriser la première position disponible ??? */
	for (i=0; i< NB_CASES_X ;i++){
		for (j=0 ; j < NB_CASES_Y ; j++){
			if (plateau.grille[i][j] == VIDE) {
				plateau.grille[i][j] = CHEVRE;
				plateau.nb_chevres_placees++;
				return;
			}
		}
	}
}

/* Fonction qui recherche si il y a un tigre dans les cases adjacentes 
	et s'il peut manger la chevre */
bool ia_chevre_en_danger (int x, int y) {
	int i, j, depart_x, depart_y, fin_x, fin_y, x_final, y_final;
	bool acces_diag = ((x + y) % 2 == 0);

	depart_x = (x == 0) ? 0 : x-1;
	depart_y = (y == 0) ? 0 : y-1;
	fin_x = (x == 4) ? 4 : x+1;
	fin_y = (y == 4) ? 4 : y+1;

	/* On recherche un tigre dans les cases adjacentes à la chevre */
	for (i = depart_x; i <= fin_x; i++) {
		for (j = depart_y; j <= fin_y; j++) {
			if (plateau.grille[i][j] == TIGRE && (acces_diag || i == x || j == y)) {
				x_final = 2 * x - i; // x + (x - i) || point + vecteur
				y_final = 2 * y - j;

				/* Si la case d'arrivée du tigre est valide */
				if (x_final >= 0 && x_final <= 4 && y_final >= 0 && y_final <= 4 && plateau.grille[x_final][y_final] == VIDE)
					return(true);
			}
		}
	}
	return(false);
}	

