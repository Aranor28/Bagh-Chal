#include <stdbool.h>
#include "main.h"
#include "tigre.h"
#include "ia_chevre.h"


void placement_chevre_ordi() {
	int i,j;
	for (i=0; i< NB_CASES_X ;i++){
		for (j=0 ; j < NB_CASES_Y ; j++){
			if (plateau.grille[i][j] == VIDE && !chevre_en_danger(i,j)) {
				plateau.grille[i][j] = CHEVRE;
				return;
			}
		}
	}
}

/* Fonction qui recherche si il y a un tigre dans les cases adjacentes 
	et s'il peut manger la chevre */
bool chevre_en_danger (int x, int y) {
	int i, j, depart_x, depart_y, fin_x, fin_y, x_final, y_final;
	bool chevre_mangee = false;

	if (x == 0)
		depart_x = 0;
	else
		depart_x = x - 1;

	if (y == 0)
		depart_y = 0;
	else
		depart_y = y - 1;

	if (x == 5)
		fin_x = 5;
	else
		fin_x = x + 1;

	if (y == 5)
		fin_y = 5;
	else
		fin_y = y + 1;

	/* On recherche un tigre dans les cases adjacentes de la chevre */
	for (i = depart_x; i < fin_x; i++){
		for (j = depart_y; j < fin_y; j++){
			if (plateau.grille[i][j] == TIGRE ){
				x_final = 2 * x - i;
				y_final = 2 * y - j;
				/* Si la case d'arrivée du tigre est valide */
				if (x_final >= 0 && x_final <= 4 && y_final >= 0 && y_final <= 4 && plateau.grille[x_final][y_final] == VIDE)
					chevre_mangee = true;
			}
		}
	}
	return(chevre_mangee);
}	

