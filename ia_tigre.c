#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "ia_tigre.h"
#include "main.h"
#include "affichage.h"

void ia_tigre_deplacement () {
	int i, j, x_final, y_final;
	for (i=0; i< 5; i++) {
		for (j=0; j < 5; j++) {
			if (plateau.grille[i][j] == TIGRE && ia_tigre_mange_chevre(i, j, &x_final, &y_final)) {
				plateau.grille[i][j] = VIDE;
				plateau.grille[(i+x_final)/2][(j+y_final)/2] = VIDE; // la chèvre est mangée
				plateau.grille[x_final][y_final] = TIGRE;
				plateau.nb_chevres_mangees++;
				affichage_ligne_info("Chèvre mangée !");
				return;
			}
		}
	}
	// Aucune chèvre n'est mangeable
	for (i=0; i< 5; i++) {
		for (j=0; j < 5; j++) {
			if (plateau.grille[i][j] == TIGRE && ia_tigre_deplacment_valide(i,j))
				return;
		}
	}
	// tests amélioration
	// int x1, y1, x2, y2;
	// for (i=0; i< 5; i++) {
	// 	for (j=0; j < 5; j++) {
	// 		if (plateau.grille[i][j] == CHEVRE && partie_chevre_vulnerable(i, j, &x1, &y1, &x2, &y2) {
				
	// 		}
	// 	}
	// }
}

bool ia_tigre_deplacment_valide (int x, int y){
	int i, j, depart_x, depart_y, fin_x, fin_y;
	bool acces_diag = ((x + y) % 2 == 0);

	depart_x = (x == 0) ? 0 : x-1;
	depart_y = (y == 0) ? 0 : y-1;
	fin_x = (x == 4) ? 4 : x+1;
	fin_y = (y == 4) ? 4 : y+1;

	for (i = depart_x; i <= fin_x; i++){
		for (j = depart_y; j <= fin_y; j++){
			if (plateau.grille[i][j] == VIDE  && (acces_diag || i == x || j == y)){
				plateau.grille[x][y] = VIDE;
				plateau.grille[i][j] = TIGRE;
				return(true);
			}
		}
	}
	return(false);
}

bool ia_tigre_mange_chevre(int x, int y, int * x2, int * y2) {
	int i, j, depart_x, depart_y, fin_x, fin_y, x_final, y_final;
	bool acces_diag = ((x + y) % 2 == 0);

	depart_x = (x == 0) ? 0 : x-1;
	depart_y = (y == 0) ? 0 : y-1;
	fin_x = (x == 4) ? 4 : x+1;
	fin_y = (y == 4) ? 4 : y+1;

	for (i = depart_x; i <= fin_x; i++) {
		for (j = depart_y; j <= fin_y; j++) {
			if (plateau.grille[i][j] == CHEVRE && (acces_diag || i == x || j == y)) {
				x_final = 2 * i - x;
				y_final = 2 * j - y;
				// Si la case d'arrivée du tigre est valide 
				if (x_final >= 0 && x_final <= 4 && y_final >= 0 && y_final <= 4 && plateau.grille[x_final][y_final] == VIDE){
					*x2 = x_final;
					*y2 = y_final;
					return (true);
				}
			}
		}
	}
	return(false);
}
