#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "ia_tigre.h"



void ia_tigre_deplacement(){
	bool deplace = true;
	int i,j, x_final, y_final;
	for (i=0; i< NB_CASES_X ;i++){
		for (j=0 ; j < NB_CASES_Y ; j++){
			if ( plateau.grille[i][j] == TIGRE && ia_tigre_mange_chevre(i, j, &x_final, &y_final) ){
				plateau.grille[x_final][y_final] = TIGRE;
				plateau.grille[i][j] = VIDE;
				return;
			}
		}
	}
	while (deplace){
		for (i=0; i< NB_CASES_X ;i++){
			for (j=0 ; j < NB_CASES_Y ; j++){
				if ( plateau.grille[i][j] == TIGRE && deplacer_tigre(i,j))
					return;
			}
		}
	}


}


bool deplacer_tigre (int x, int y){
	int i, j, depart_x, depart_y, fin_x, fin_y;

	if (x == 0)
		depart_x = 0;
	else
		depart_x = x - 1;

	if (y == 0)
		depart_y = 0;
	else
		depart_y = y - 1;

	if (x == 4)
		fin_x = 4;
	else
		fin_x = x + 1;

	if (y == 4)
		fin_y = 4;
	else
		fin_y = y + 1;

	for (i = depart_x; i <= fin_x; i++){
		for (j = depart_y; j <= fin_y; j++){
			if (plateau.grille[i][j] == VIDE){
				plateau.grille[i][j] = TIGRE;
				plateau.grille[x][y] = VIDE;
				return(true);
			}
		}
	}
	return(false);
}

bool ia_tigre_mange_chevre(int x, int y, int * x2, int * y2){
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

	if (x == 4)
		fin_x = 4;
	else
		fin_x = x + 1;

	if (y == 4)
		fin_y = 4;
	else
		fin_y = y + 1;

	for (i = depart_x; i <= fin_x; i++){
		for (j = depart_y; j <= fin_y; j++){
			if (plateau.grille[i][j] == CHEVRE ){
				x_final = 2 * i - x;
				y_final = 2 * j - y;
				/* Si la case d'arrivée du tigre est valide */
				if (x_final >= 0 && x_final <= 4 && y_final >= 0 && y_final <= 4 && plateau.grille[x_final][y_final] == VIDE){
					plateau.grille [i][j] = VIDE;
					plateau.nb_chevres_mangees = plateau.nb_chevres_mangees + 1;
					chevre_mangee = true;
					*x2 = x_final;
					*y2 = y_final;
					return (chevre_mangee);
				}
			}
		}
	}
	return(chevre_mangee);
}	

