#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include "affichage.h"
#include "main.h"

void affichage () {
	affichage_info();
	affichage_plateau();
	affichage_pion();
	refresh();
}

/****  AFFICHAGE DES INFORMATIONS CONCERNANT LE DEROULEMENT DU JEU ****/
void affichage_info(){
	start_color();

	/*Affichage du nombre de chèvres*/
	init_pair(COULEURS_NBCHEVRES, COLOR_BLACK,COLOR_CYAN);
	attron(A_BOLD | COLOR_PAIR(COULEURS_NBCHEVRES));
	mvprintw(Y_NBCHEVRES, X_NBCHEVRES, "%02d Chevre(s) en réserve, %d  Chevre(s) mangée(s)\n"
		,(20 - plateau.nb_chevres_placees), plateau.nb_chevres_mangees);
	attroff(A_BOLD | COLOR_PAIR(COULEURS_NBCHEVRES));

	/*Affichage du tour du joueur*/
	if (plateau.joueur_courant == TIGRE){
		init_pair(COULEURS_TOUR_TIGRE, COLOR_WHITE,COLOR_RED);
		attron(A_BOLD | COLOR_PAIR(COULEURS_TOUR_TIGRE));
		mvprintw(Y_TOUR_JOUEUR, X_TOUR_JOUEUR, "C'est au joueur TIGRE de jouer\n");
		attroff(A_BOLD | COLOR_PAIR(COULEURS_TOUR_TIGRE));
	}
	else if (plateau.joueur_courant == CHEVRE){
		init_pair(COULEURS_TOUR_CHEVRE, COLOR_WHITE,COLOR_GREEN);
		attron(A_BOLD | COLOR_PAIR(COULEURS_TOUR_CHEVRE));
		mvprintw(Y_TOUR_JOUEUR, X_TOUR_JOUEUR, "C'est au joueur CHEVRE de jouer\n");
		attroff(A_BOLD | COLOR_PAIR(COULEURS_TOUR_CHEVRE));
	}
}

/**** AFFICHAGE DES PIONS PLACES SUR LE PLATEAU ****/
void affichage_pion(){
	int i,j;

	start_color();

	/* On parcourt chaque case de la grille */
	for (i=0; i< NB_CASES_X ;i++){
		for (j=0 ; j < NB_CASES_Y ; j++){
			if (plateau.grille[i][j] == VIDE) { /* Si la case est vide, on y laisse un espace */
				init_pair(COULEURS_CASE_VIDE, COLOR_BLACK,COLOR_BLACK);
				attron(A_BOLD | COLOR_PAIR(COULEURS_CASE_VIDE));
				mvprintw(j*4 + STARTY, i*5 + STARTX,"[ ]");
				attroff(A_BOLD | COLOR_PAIR(COULEURS_CASE_VIDE));
			}
			else if (plateau.grille[i][j] == TIGRE) { /* Si il y a un tigre, on affiche un 'T' rouge*/
				init_pair(COULEURS_CASE_TIGRE, COLOR_RED,COLOR_BLACK);
				attron(A_BOLD | COLOR_PAIR(COULEURS_CASE_TIGRE));
				mvprintw(j*4 + STARTY, i*5 + STARTX,"[T]");
				attroff(A_BOLD | COLOR_PAIR(COULEURS_CASE_TIGRE));
			}
			else { /* Si il y a une chèvre, on affiche un 'C' vert*/
				init_pair(COULEURS_CASE_CHEVRE, COLOR_GREEN,COLOR_BLACK);
				attron(A_BOLD | COLOR_PAIR(COULEURS_CASE_CHEVRE));
				mvprintw(j*4 + STARTY, i*5 + STARTX,"[C]");
				attroff(A_BOLD | COLOR_PAIR(COULEURS_CASE_CHEVRE));
			}
		}
	}
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