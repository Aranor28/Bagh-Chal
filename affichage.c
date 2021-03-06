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
	init_pair(COULEURS_BOUTON_SAUVEGARDE, COLOR_BLACK,COLOR_CYAN);
	init_pair(COULEURS_BOUTON_CHARGER, COLOR_BLACK,COLOR_CYAN);
	init_pair(COULEURS_BOUTON_ANNULER, COLOR_BLACK,COLOR_CYAN);
	init_pair(COULEURS_BOUTON_QUITTER, COLOR_BLACK,COLOR_CYAN);

	/* Paires de couleurs des boutons du menu */
	init_pair(COULEURS_BIENVENUE, COLOR_WHITE,COLOR_MAGENTA);
	init_pair(COULEURS_BOUTON_JcJ, COLOR_WHITE,COLOR_CYAN);
	init_pair(COULEURS_BOUTON_JcIA_CHEVRE, COLOR_WHITE, COLOR_RED);
	init_pair(COULEURS_BOUTON_JcIA_TIGRE, COLOR_WHITE, COLOR_GREEN);

	/* Paire de couleur de l'aide */
	init_pair(COULEURS_AIDE, COLOR_WHITE, COLOR_BLACK);

	/* Paire de couleur des lignes d'informations */ 
	init_pair(COULEURS_INFO, COLOR_CYAN, COLOR_BLACK);

	/* Paire de couleur des boutons d'emplacement de sauvegarde */
	init_pair(COULEURS_EMPL, COLOR_CYAN, COLOR_BLACK);
}

void affichage () {

	affichage_bouttons();
	affichage_plateau();
	affichage_info();
	affichage_pion();
	refresh();
}

/****  AFFICHAGE DES INFORMATIONS CONCERNANT LE DEROULEMENT DU JEU ****/
void affichage_info(){
	/* Affichage du nombre de chèvres placées */
	attron(A_BOLD | COLOR_PAIR(COULEURS_NBCHEVRES_PLACEES));
	mvprintw(Y_NBCHEVRES, X_NBCHEVRES, "%02d Chevre(s) en réserve"
		,(20 - plateau.nb_chevres_placees));
	attroff(A_BOLD | COLOR_PAIR(COULEURS_NBCHEVRES_PLACEES));

	/* Affichage du nombre de chèvres mangées */
	attron(A_BOLD | COLOR_PAIR(COULEURS_NBCHEVRES_MANGEES));
	mvprintw(Y_NBCHEVRES + 1, X_NBCHEVRES, "%01d /7 Chevre(s) mangée(s)", plateau.nb_chevres_mangees);
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
void affichage_pion() {
	int i, j;
	/* On parcourt chaque case de la grille */
	for (i=0; i< 5; i++) {
		for (j=0; j < 5; j++) {
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
	mvprintw(Y_SAUVEGARDER, X_SAUVEGARDER,"[" BOUTON_SAUVEGARDER "]");
	mvprintw(Y_SAUVEGARDER + 1, X_SAUVEGARDER , "               ");
	attroff(A_BOLD | COLOR_PAIR(COULEURS_BOUTON_SAUVEGARDE));

	attron(A_BOLD | COLOR_PAIR(COULEURS_BOUTON_CHARGER));
	mvprintw(Y_CHARGER, X_CHARGER,"[" BOUTON_CHARGER "]");
	mvprintw(Y_CHARGER + 1, X_CHARGER , "               ");
	attroff(A_BOLD | COLOR_PAIR(COULEURS_BOUTON_CHARGER));

	attron(A_BOLD | COLOR_PAIR(COULEURS_BOUTON_ANNULER));
	mvprintw(Y_ANNULER, X_ANNULER,"[" BOUTON_ANNULER "]");
	mvprintw(Y_ANNULER + 1, X_ANNULER , "               ");
	attroff(A_BOLD | COLOR_PAIR(COULEURS_BOUTON_ANNULER));

	attron(A_BOLD | COLOR_PAIR(COULEURS_BOUTON_QUITTER));
	mvprintw(Y_QUITTER, X_QUITTER,"[" BOUTON_QUITTER "]");
	attroff(A_BOLD | COLOR_PAIR(COULEURS_BOUTON_QUITTER));

	attron(A_BOLD | COLOR_PAIR(COULEURS_AIDE));
	mvprintw(Y_MENU_AIDE, X_MENU_AIDE, BOUTON_AFFICHER_AIDE);
	attroff(A_BOLD | COLOR_PAIR(COULEURS_AIDE));
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
		mvprintw(STARTY + STARTY/2, STARTX - STARTX/8, "***************************************");
		mvprintw(STARTY + STARTY/2 +1, STARTX - STARTX/8, "*C'EST LE JOUEUR CHEVRE QUI A GAGNE !!*");
		mvprintw(STARTY + STARTY/2 +2, STARTX - STARTX/8, "***************************************");
		attroff(A_BOLD | COLOR_PAIR(COULEURS_CASE_CHEVRE_SURBRILLANCE));
	}
}

void affichage_ligne_info (char s[]) {
	attron(A_BOLD | COLOR_PAIR(COULEURS_INFO));
	mvprintw(Y_LIGNE_INFO, X_LIGNE_INFO, "%s", s);
	attroff(A_BOLD | COLOR_PAIR(COULEURS_AIDE));
}

void affichage_menu (){

	attron(A_BOLD | COLOR_PAIR(COULEURS_BIENVENUE));
	mvprintw(Y_BIENVENUE, X_BIENVENUE,BIENVENUE);
	attroff(A_BOLD | COLOR_PAIR(COULEURS_BIENVENUE));

	attron(A_BOLD | COLOR_PAIR(COULEURS_BOUTON_JcJ));
	mvprintw(Y_MENU_JcJ, X_MENU_JcJ,"[" BOUTON_JcJ "]");
	attroff(A_BOLD | COLOR_PAIR(COULEURS_BOUTON_JcJ));

	attron(A_BOLD | COLOR_PAIR(COULEURS_BOUTON_JcIA_TIGRE));
	mvprintw(Y_MENU_JcIA_TIGRE, X_MENU_JcIA_TIGRE,"[" BOUTON_JcIA_TIGRE"]");
	attroff(A_BOLD | COLOR_PAIR(COULEURS_BOUTON_JcIA_TIGRE));

	attron(A_BOLD | COLOR_PAIR(COULEURS_BOUTON_JcIA_CHEVRE));
	mvprintw(Y_MENU_JcIA_CHEVRE, X_MENU_JcIA_CHEVRE,"[" BOUTON_JcIA_CHEVRE "]");
	attroff(A_BOLD | COLOR_PAIR(COULEURS_BOUTON_JcIA_CHEVRE));

	attron(A_BOLD | COLOR_PAIR(COULEURS_AIDE));
	mvprintw(Y_MENU_AIDE, X_MENU_AIDE, BOUTON_AFFICHER_AIDE);
	attroff(A_BOLD | COLOR_PAIR(COULEURS_AIDE));

}

void affichage_aide () {
	clear();
	attron(COLOR_PAIR(COULEURS_AIDE));
	mvprintw(10,0,"Ce jeu se joue à 2 : un joueur ayant quatre tigres et son adversaire vingt chevres\nL'objectif des chevres est d'immobiliser les tigres.\nLes tigres gagnent s'ils capturent suffisamment de chevres pour que celle-ci ne puissent plus les immobiliser (7 chevres).\nLes joueurs doivent chacun leur tour deplacer un de leur pion. Ce sont les chevres qui commencent.\nChaque pion peut se deplacer d'une intersection vers une autre libre en suivant le trace du diagramme.\nLes chevres rentrent en jeu une a une, sur une intersection libre. Tant que toutes les chevres ne sont pas placees, elles ne peuvent pas se deplacer. \nLes tigres peuvent se deplacer meme si toutes les chevres ne sont pas placees.\nUn tigre capture une chevre en sautant par dessus elle, lorsque l'intersection suivante est libre. Un tigre ne peut manger qu'une chevre par coup.\n*******************************************\nPour placer une chevre, cliquez sur une intersection libre.\nPour déplacer un pion (tigre ou chevre) cliquez sur le pion à deplacer puis cliquez sur l'intersection d'arrivee.\nPour de-selection un pion, cliquez sur un autre.\nPour faire jouer l'ordinateur, cliquez n'importe où sur votre terminal.\n\n CLIQUEZ POUR QUITTER CETTE AIDE.\n");
	attroff( COLOR_PAIR(COULEURS_AIDE));
	refresh();
}

void affichage_vider_info () {
	mvprintw(Y_LIGNE_INFO, X_LIGNE_INFO, "										");
	refresh();
}

void affichage_emplacements_sauvegarde(){
	attron(A_BOLD | COLOR_PAIR(COULEURS_EMPL));
	mvprintw(Y_EMPL1, X_EMPL1, BOUTON_EMPL1);
	mvprintw(Y_EMPL2, X_EMPL2, BOUTON_EMPL2);
	mvprintw(Y_EMPL3, X_EMPL3, BOUTON_EMPL3);
	attroff(A_BOLD | COLOR_PAIR(COULEURS_AIDE));
}

void affichage_emplacements_sauvegarde_vider () {
	mvprintw(Y_EMPL1, X_EMPL1, "         ");
	mvprintw(Y_EMPL2, X_EMPL2, "         ");
	mvprintw(Y_EMPL3, X_EMPL3, "         ");
}