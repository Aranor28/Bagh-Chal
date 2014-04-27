#include <stdlib.h>
#include <ncurses.h>
#include "entree_souris.h"
#include "main.h"

int ES_recuperer_case (int * x_grille, int * y_grille) {
	int x_win, y_win;
	ES_recuperer_souris (&x_win, &y_win);

	if (y_win < STARTY || y_win > (STARTY + HEIGHT) || x_win < STARTX || x_win > (STARTX + WIDTH))
		return(PAS_CASE); // hors du plateau

	if ((y_win-STARTY) % 4 != 0 || (x_win-STARTX) % 5 > 2)
		return(PAS_CASE); // dans le plateau mais pas une case

	*x_grille = (x_win-STARTX) / 5;
	*y_grille = (y_win-STARTY) / 4;
	return(plateau.grille[*x_grille][*y_grille]);
}

void ES_recuperer_souris (int * x_win, int * y_win) {
	int c;
	MEVENT event; // récupèrera l'évènement
	keypad(stdscr, TRUE); // permet de récupérer les entrées souris
	mousemask(ALL_MOUSE_EVENTS, NULL); // permet de récupérer tous les évènements de la souris

	while(1) {
		c = getch(); // récupère une entrée 
		switch(c) {
			case KEY_MOUSE:
				if (getmouse(&event) == OK) {
					if (event.bstate & BUTTON1_CLICKED) { // si le bouton gauche a été préssé
						*x_win = event.x;
						*y_win = event.y;
						return;
					}
				}
				break;

			case 'q':
				endwin();
				exit(0);
				break;

			default:
				mvprintw(LINES-1,0, "pas un clic de souris");
				refresh();
				break;
		}
	}
}