#include "affichage.c"

void initialiser_plateau (){
  int i,j;
  for (i=0; i < HEIGT ;i++){
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
  initscr();
  curs_set(0);
  initialiser_plateau();
  affichage_plateau(0);
  endwin();
  return 0;
}