#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tigre.h"
#include "main.h"
#include "entree_souris.h"
#include "affichage.h"

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
	plateau.grille[x2][y2] = TIGRE;
}

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

// int deplacement_tigre (int x1, int y1, int x2, int y2, int * nb_chevre_mangee){
// 	int retour = 0;

// 	if (plateau[x1][y1] == TIGRE && plateau[x2][y2] == VIDE){
// 		if ((abs(x1-x2) == 1)&& (abs(y1-y2) == 1) && ((((y1 % 2) == 0) && ((x1 % 2) == 0)) || (((y1 % 2) != 0) && ((x1 % 2) != 0)))){
// 					plateau[x1][y1] = VIDE;
// 					plateau[x2][y2] = TIGRE;
// 		}
// 		else if ((abs(x1-x2) == 1)&& (abs(y1-y2) == 0)){
// 					plateau[x1][y1] = VIDE;
// 					plateau[x2][y2] = TIGRE;
// 		}
// 		else if ((abs(x1-x2) == 0)&& (abs(y1-y2) == 1)){
// 					plateau[x1][y1] = VIDE;
// 					plateau[x2][y2] = TIGRE;
// 		}
// 		else if ((abs(x1-x2) == 2) && (abs(y1-y2) == 0) && (plateau[(x1+x2)/2][(y1+y2)/2] == CHEVRE)){
// 					plateau[x1][y1] = VIDE;
// 					plateau[x2][y2] = TIGRE;
// 					plateau[(x1+x2)/2][(y1+y2)/2] = VIDE;
// 					*nb_chevre_mangee = *nb_chevre_mangee + 1;
// 		}
// 		else if ((abs(x1-x2) == 0) && (abs(y1-y2) == 2) && (plateau[(x1+x2)/2][(y1+y2)/2] == CHEVRE)){
// 					plateau[x1][y1] = VIDE;
// 					plateau[x2][y2] = TIGRE;
// 					plateau[(x1+x2)/2][(y1+y2)/2] = VIDE;
// 					*nb_chevre_mangee = *nb_chevre_mangee + 1;
// 		}
// 		else if (((x1 % 2) == 0) && ((x2 % 2) == 0) && ((y1 % 2) == 0) && ((y2 % 2) == 0) && (plateau[(x1+x2)/2][(y1+y2)/2] == CHEVRE)){
// 					plateau[x1][y1] = VIDE;
// 					plateau[x2][y2] = TIGRE;
// 					plateau[(x1+x2)/2][(y1+y2)/2] = VIDE;
// 					*nb_chevre_mangee = *nb_chevre_mangee + 1;
// 		}
// 		else
// 			retour = 1;
// 	}
// 	else 
// 		retour = 1;

// 	return(retour);
// }


// void verification_deplacement_tigre (int * nb_chevre_mangee){
// 	int retour, x, y, x2, y2;

// 	do {
// 		scanf("%d %d %d %d",&x,&y,&x2,&y2);
// 		retour = deplacement_tigre(x,y,x2,y2,nb_chevre_mangee);
// 	}while(retour != 0);
// }


