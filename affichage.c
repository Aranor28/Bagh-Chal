#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include "affichage.h"
#include "main.h"

 /**** AFFICHAGE DES PIONS PLACES SUR LE PLATEAU ****/
 void affichage_pion(){
  int i,j;

  start_color();

  /*PARCOURS DE CHAQUE CASE DU TABLEAU*/
  for (i=0; i< HEIGHT ;i++){
     for (j=0 ; j < WIDTH ; j++){
       
          if ( plateau[i][j] == 0 ){ /*Si la case est vide, on y laisse un espace */
            init_pair(6, COLOR_BLACK,COLOR_BLACK);
            attron(A_BOLD | COLOR_PAIR(6));
            mvprintw(i*4 + STARTX,j*5 + STARTY,"[ ]");
            attroff(A_BOLD | COLOR_PAIR(6));
          }
          
          else if ( plateau[i][j] == TIGRE ){ /*Si il y a un tigre, on affiche un 'T' rouge*/
            init_pair(4, COLOR_RED,COLOR_BLACK);
            attron(A_BOLD | COLOR_PAIR(4));
            mvprintw(i*4 + STARTX ,j*5 + STARTY,"[T]");
            attroff(A_BOLD | COLOR_PAIR(4));
          }
          else { /* Si il y a une chèvre, on affiche un 'C' vert*/
            init_pair(5, COLOR_GREEN,COLOR_BLACK);
            attron(A_BOLD | COLOR_PAIR(5));
            mvprintw(i*4 + STARTX,j*5 + STARTY,"[C]");
            attroff(A_BOLD | COLOR_PAIR(5));
          }
      }
  }

}


/**** AFFICHAGE DE LA GRILLE DU PLATEAU DE JEU ****/
void affichage_plateau(){

  /*Affichage de la grille*/

  mvprintw(STARTX,STARTY,"   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   \n");
  mvprintw(STARTX +1,STARTY ," | \\  |  / | \\  |  / |\n");
  mvprintw(STARTX +2,STARTY ," |  \\ | /  |  \\ | /  |\n");
  mvprintw(STARTX +3,STARTY ," |   \\|/   |   \\|/   |\n");
  mvprintw(STARTX +4,STARTY ,"   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   \n");
  mvprintw(STARTX +5,STARTY ," |   /|\\   |   /|\\   |\n");
  mvprintw(STARTX +6,STARTY ," |  / | \\  |  / | \\  |\n");
  mvprintw(STARTX +7,STARTY ," | /  |  \\ | /  |  \\ |\n");
  mvprintw(STARTX +8,STARTY ,"   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   \n");
  mvprintw(STARTX +9,STARTY ," | \\  |  / | \\  |  / |\n");
  mvprintw(STARTX +10,STARTY ," |  \\ | /  |  \\ | /  |\n");
  mvprintw(STARTX +11,STARTY ," |   \\|/   |   \\|/   |\n");
  mvprintw(STARTX +12,STARTY ,"   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   \n");
  mvprintw(STARTX +13,STARTY ," |   /|\\   |   /|\\   |\n");
  mvprintw(STARTX +14,STARTY ," |  / | \\  |  / | \\  |\n");
  mvprintw(STARTX +15,STARTY ," | /  |  \\ | /  |  \\ |\n");
  mvprintw(STARTX +16,STARTY ,"   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   ");addch(ACS_HLINE);addch(ACS_HLINE);printw("   \n");
  
   
}

/****  AFFICHAGE DES INFORMATIONS CONCERNANT LE DEROULEMENT DU JEU ****/
void affichage_info(int nb_chevre_reserve, int nb_chevre_mangee,int joueur){
  start_color();

  /*Affichage du nombre de chèvres*/
  init_pair(1, COLOR_BLACK,COLOR_CYAN);
  attron(A_BOLD | COLOR_PAIR(1));
  mvprintw(STARTX -3, STARTY - 10, "%d Chevre(s) en réserve, %d Chevre(s) mangée(s)\n",20-nb_chevre_reserve,nb_chevre_mangee);
  attroff(A_BOLD | COLOR_PAIR(1));

  /*Affichage du tour du joueur*/
  if (joueur == JOUEUR_TIGRE){
    init_pair(2, COLOR_WHITE,COLOR_RED);
    attron(A_BOLD | COLOR_PAIR(2));
    mvprintw(STARTX -5, STARTY - 5, "C'est au joueur TIGRE de commencer\n");
    attroff(A_BOLD | COLOR_PAIR(2));
  }
  else if (joueur == JOUEUR_CHEVRE){
    init_pair(3, COLOR_WHITE,COLOR_GREEN);
    attron(A_BOLD | COLOR_PAIR(3));
    mvprintw(STARTX -5, STARTY - 5, "C'est au joueur CHEVRE de commencer\n");
    attroff(A_BOLD | COLOR_PAIR(3));
  }
  
}

void affichage (int nb_chevre_reserve, int nb_chevre_mangee, int joueur){
  affichage_plateau();
  affichage_info(nb_chevre_reserve, nb_chevre_mangee, joueur);
  affichage_pion();

}

