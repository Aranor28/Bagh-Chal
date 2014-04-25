#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "main.h"

#include "affichage.h"
#include "deplacement_tigre.h"
#include "placement_chevre.h"
#include "fin_partie.h"
#include "entree_souris.h"
#include "sauvegarde.h"

/**** FONCTION D'INITIALISATION DU PLATEAU ****/
/**** PLACE LES TIGRES DANS LES ANGLES DU PLATEAU ET MET A VIDE LES AUTRES CASES ****/
void initialiser_plateau (){
  int i,j;
  for (i=0; i < HEIGHT ;i++){
    for (j=0 ; j < WIDTH ; j++){
      plateau[i][j]=0;
    }
  }
  /*Placement des tigres dans chaque angles du plateau*/
  plateau[0][4]=TIGRE;
  plateau[0][0]=TIGRE;
  plateau[4][0]=TIGRE;
  plateau[4][4]=TIGRE;
}



int main (){
  int chevre_placee = 0, chevre_mangee = 0;
  int joueur = JOUEUR_CHEVRE  ;

  /* Préparation de Ncurses */
  initscr();
  curs_set(0);
  noecho();
  clear();

  /* Départ de la partie */
  initialiser_plateau();
  affichage(chevre_placee,chevre_mangee,joueur);
  refresh();

  /* Phase de placement */
  while (chevre_placee < 20){

        refresh();
        verification_placement_chevre(&chevre_placee);
        affichage_pion();
        affichage_info(chevre_placee, chevre_mangee,JOUEUR_TIGRE);

        refresh();
        verification_deplacement_tigre(&chevre_mangee);
        affichage_pion();
        affichage_info(chevre_placee, chevre_mangee,JOUEUR_CHEVRE);
        refresh();
        detection_fin_partie(chevre_mangee,0);
        //getch();();

   }  


  /* Fermeture de Ncurses */
  endwin();

  return 0;
}