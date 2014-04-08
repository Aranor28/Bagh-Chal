#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#define TIGRE 1
#define CHEVRE 2
#define WIDTH 5
#define HEIGT 5
int plateau [WIDTH][HEIGT];
void affichage_plateau(int nb_chevre_reserve){
  int i,j;
  clear();
  start_color();
  plateau[2][2]=CHEVRE;//J'ai mis une chèvre pour tester doduou <3
  
  /*Affichage du nombre de chèvres*/
  init_pair(1, COLOR_BLACK,COLOR_CYAN);
  attron(A_BOLD | COLOR_PAIR(1));
  printw("%d Chevre(s) en réserve    %d Chevre(s) mangée(s)\n",20-nb_chevre_reserve,nb_chevre_reserve);
  attroff(A_BOLD | COLOR_PAIR(1));
  
  /*Affichage de la grille*/
  printw(" == == == == \n");
  printw("|\\\\|//|\\\\|//|\n");
  printw(" == == == == \n");
  printw("|//|\\\\|//|\\\\|\n");
  printw(" == == == == \n");
  printw("|\\\\|//|\\\\|//|\n");
  printw(" == == == == \n");
  printw("|//|\\\\|//|\\\\|\n");
  printw(" == == == == \n");
  
  /*Affichage des différents pions*/
  for (i=0; i< HEIGT ;i++){
    for (j=0 ; j < WIDTH ; j++){
    	if ( plateau[i][j] == 0 ) // Si il n'y pas de pion
    	  mvprintw(i*2+1,j*3," ");
    	
    	else if ( plateau[i][j] == TIGRE ){ // Si il y a un tigre
    	  init_pair(2, COLOR_RED,COLOR_BLACK);
    	  attron(A_BOLD | COLOR_PAIR(2));
    	  mvprintw(i*2+1,j*3,"T");
    	  attroff(A_BOLD | COLOR_PAIR(2));
    	}
    	else { // Si il y a une chèvre
    	  init_pair(3, COLOR_GREEN,COLOR_BLACK);
    	  attron(A_BOLD | COLOR_PAIR(3));
    	  mvprintw(i*2+1,j*3,"C");
    	  attroff(A_BOLD | COLOR_PAIR(3));
    	}
    }
  }
}

