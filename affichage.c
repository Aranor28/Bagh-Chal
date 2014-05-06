#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include "affichage.h"
#include "main.h"

void affichage_init_color_pairs () {
	/* Paires de couleurs des lignes d'informations */
	init_pair(COULEURS_NBCHEVRES_PLACEES, COLOR_GREEN, COLOR_BLACK);
	init_pair(COULEURS_NBCHEVRES_MANGEES, COLOR_RED, COLOR_BLACK);
	init_pair(COULEURS_TOUR_TIGRE, COLOR_WHITE,COLOR_RED);
	init_pair(COULEURS_TOUR_CHEVRE, COLOR_WHITE,COLOR_GREEN);

	/* Paires de couleurs des cases de la grille */
	init_pair(COULEURS_CASE_VIDE, COLOR_BLACK,COLOR_BLACK);
	init_pair(COULEURS_CASE_TIGRE, COLOR_RED,COLOR_BLACK);
	init_pair(COULEURS_CASE_CHEVRE, COLOR_GREEN,COLOR_BLACK);

	/* Paires de couleurs des cases en surbrillance */
	init_pair(COULEURS_CASE_TIGRE_SURBRILLANCE, COLOR_WHITE, COLOR_RED);
	init_pair(COULEURS_CASE_CHEVRE_SURBRILLANCE, COLOR_WHITE, COLOR_GREEN);

	/* Paires de couleurs des boutons de sauvegarde et chargement */
	init_pair(COULEURS_BOUTON_SAUVEGARDE, COLOR_WHITE,COLOR_CYAN);
	init_pair(COULEURS_BOUTON_CHARGER, COLOR_WHITE,COLOR_CYAN);
	init_pair(COULEURS_BOUTON_ANNULER, COLOR_WHITE,COLOR_CYAN);
}

void affichage () {
	affichage_info();
	affichage_bouttons();
	affichage_plateau();
	affichage_pion();
	refresh();
}

/****  AFFICHAGE DES INFORMATIONS CONCERNANT LE DEROULEMENT DU JEU ****/
void affichage_info(){
	/*Affichage du nombre de chèvres placées*/
	attron(A_BOLD | COLOR_PAIR(COULEURS_NBCHEVRES_PLACEES));
	mvprintw(Y_NBCHEVRES, X_NBCHEVRES, "%02d Chevre(s) en réserve"
		,(20 - plateau.nb_chevres_placees));
	attroff(A_BOLD | COLOR_PAIR(COULEURS_NBCHEVRES_PLACEES));

	/*Affichage du nombre de chèvres mangées */
	attron(A_BOLD | COLOR_PAIR(COULEURS_NBCHEVRES_MANGEES));
	mvprintw(Y_NBCHEVRES + 1, X_NBCHEVRES, "%01d /7 Chevre(s) mangée(s)\n", plateau.nb_chevres_mangees);
	attroff(A_BOLD | COLOR_PAIR(COULEURS_NBCHEVRES_MANGEES));

	/*Affichage du tour du joueur*/
	if (plateau.joueur_courant == TIGRE){
		attron(A_BOLD | COLOR_PAIR(COULEURS_TOUR_TIGRE));
		mvprintw(Y_TOUR_JOUEUR, X_TOUR_JOUEUR, "C'est au joueur TIGRE de jouer\n");
		attroff(A_BOLD | COLOR_PAIR(COULEURS_TOUR_TIGRE));
	}
	else if (plateau.joueur_courant == CHEVRE){
		attron(A_BOLD | COLOR_PAIR(COULEURS_TOUR_CHEVRE));
		mvprintw(Y_TOUR_JOUEUR, X_TOUR_JOUEUR, "C'est au joueur CHEVRE de jouer\n");
		attroff(A_BOLD | COLOR_PAIR(COULEURS_TOUR_CHEVRE));
	}
}

/**** AFFICHAGE DES PIONS PLACES SUR LE PLATEAU ****/
void affichage_pion(){
	int i,j;
	/* On parcourt chaque case de la grille */
	for (i=0; i< NB_CASES_X ;i++){
		for (j=0 ; j < NB_CASES_Y ; j++){
			if (plateau.grille[i][j] == VIDE) { /* Si la case est vide, on y laisse un espace */
				attron(A_BOLD | COLOR_PAIR(COULEURS_CASE_VIDE));
				mvprintw(j*4 + STARTY, i*5 + STARTX,"[ ]");
				attroff(A_BOLD | COLOR_PAIR(COULEURS_CASE_VIDE));
			}
			else if (plateau.grille[i][j] == TIGRE) { /* Si il y a un tigre, on affiche un 'T' rouge*/
				attron(A_BOLD | COLOR_PAIR(COULEURS_CASE_TIGRE));
				mvprintw(j*4 + STARTY, i*5 + STARTX,"[T]");
				attroff(A_BOLD | COLOR_PAIR(COULEURS_CASE_TIGRE));
			}
			else { /* Si il y a une chèvre, on affiche un 'C' vert*/
				attron(A_BOLD | COLOR_PAIR(COULEURS_CASE_CHEVRE));
				mvprintw(j*4 + STARTY, i*5 + STARTX,"[C]");
				attroff(A_BOLD | COLOR_PAIR(COULEURS_CASE_CHEVRE));
			}
		}
	}
}

void affichage_bouttons() {
	
	attron(A_BOLD | COLOR_PAIR(COULEURS_BOUTON_SAUVEGARDE));
	mvprintw(Y_SAUVEGARDER, X_SAUVEGARDER,"[" BOUTTON_SAUVEGARDER "]");
	attroff(A_BOLD | COLOR_PAIR(COULEURS_BOUTON_SAUVEGARDE));

	attron(A_BOLD | COLOR_PAIR(COULEURS_BOUTON_CHARGER));
	mvprintw(Y_CHARGER, X_CHARGER,"[" BOUTTON_CHARGER "]");
	attroff(A_BOLD | COLOR_PAIR(COULEURS_BOUTON_CHARGER));

	attron(A_BOLD | COLOR_PAIR(COULEURS_BOUTON_ANNULER));
	mvprintw(Y_ANNULER, X_ANNULER,"[" BOUTTON_ANNULER "]");
	attroff(A_BOLD | COLOR_PAIR(COULEURS_BOUTON_ANNULER));
} 

/**** AFFICHAGE DE LA GRILLE DU PLATEAU DE JEU ****/
void affichage_plateau(){
	/*Affichage de la grille*/
	mvprintw(STARTY, STARTX, "   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   \n");
	mvprintw(STARTY+1, STARTX, " | \\  |  / | \\  |  / |\n");
	mvprintw(STARTY+2, STARTX, " |  \\ | /  |  \\ | /  |\n");
	mvprintw(STARTY+3, STARTX, " |   \\|/   |   \\|/   |\n");
	mvprintw(STARTY+4, STARTX, "   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   \n");
	mvprintw(STARTY+5, STARTX, " |   /|\\   |   /|\\   |\n");
	mvprintw(STARTY+6, STARTX, " |  / | \\  |  / | \\  |\n");
	mvprintw(STARTY+7, STARTX, " | /  |  \\ | /  |  \\ |\n");
	mvprintw(STARTY+8, STARTX, "   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   \n");
	mvprintw(STARTY+9, STARTX, " | \\  |  / | \\  |  / |\n");
	mvprintw(STARTY+10, STARTX," |  \\ | /  |  \\ | /  |\n");
	mvprintw(STARTY+11, STARTX," |   \\|/   |   \\|/   |\n");
	mvprintw(STARTY+12, STARTX, "   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   \n");
	mvprintw(STARTY+13, STARTX, " |   /|\\   |   /|\\   |\n");
	mvprintw(STARTY+14, STARTX, " |  / | \\  |  / | \\  |\n");
	mvprintw(STARTY+15, STARTX, " | /  |  \\ | /  |  \\ |\n");
	mvprintw(STARTY+16, STARTX, "   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   \n");
}

void affichage_surbrillance (int x, int y) {
	if (plateau.grille[x][y] == TIGRE) {
		attron(A_BOLD | COLOR_PAIR(COULEURS_CASE_TIGRE_SURBRILLANCE));
		mvprintw(y*4 + STARTY, x*5 + STARTX, "[T]");
		attroff(A_BOLD | COLOR_PAIR(COULEURS_CASE_TIGRE_SURBRILLANCE));
	}
	else {
		attron(A_BOLD | COLOR_PAIR(COULEURS_CASE_CHEVRE_SURBRILLANCE));
		mvprintw(y*4 + STARTY, x*5 + STARTX, "[C]");
		attroff(A_BOLD | COLOR_PAIR(COULEURS_CASE_CHEVRE_SURBRILLANCE));
	}
}


void affichage_gagnant (int gagnant){
	if (gagnant == TIGRE){
		attron(A_BOLD | COLOR_PAIR(COULEURS_CASE_TIGRE_SURBRILLANCE));
		mvprintw(STARTY + STARTY/2, STARTX - STARTX/8, "**************************************");
		mvprintw(STARTY + STARTY/2 +1, STARTX - STARTX/8, "*C'EST LE JOUEUR TIGRE QUI A GAGNE !!*");
		mvprintw(STARTY + STARTY/2 +2, STARTX - STARTX/8, "**************************************");
		attroff(A_BOLD  | COLOR_PAIR(COULEURS_CASE_TIGRE_SURBRILLANCE));
	}
	else {
		attron(A_BOLD | COLOR_PAIR(COULEURS_CASE_CHEVRE_SURBRILLANCE));
		mvprintw(STARTY + STARTY/2, STARTX - STARTX/8, "**************************************");
		mvprintw(STARTY + STARTY/2 +1, STARTX - STARTX/8, "*C'EST LE JOUEUR CHEVRE QUI A GAGNE !!*");
		mvprintw(STARTY + STARTY/2 +2, STARTX - STARTX/8, "**************************************");
		attroff(A_BOLD | COLOR_PAIR(COULEURS_CASE_CHEVRE_SURBRILLANCE));
	}
}