#include <stdlib.h>
#include <stdio.h>
#define WIDTH 5
#define HEIGT 5

int plateau [WIDTH][HEIGT];

void initialiser_plateau (){
  int i,j;
  for (i=0; i < HEIGT ;i++){
    for (j=0 ; j < WIDTH ; j++){
      plateau[i][j]=0;
    }
  }
  plateau[0][4]=1;
  plateau[0][0]=1;
  plateau[4][0]=1;
  plateau[4][4]=1;
}

void affichage_plateau(){
  int i,j;
    for (i=0; i< HEIGT ;i++){
      printf("|");
      for (j=0 ; j < WIDTH ; j++){
	if ( plateau[i][j] == 0 )
	  printf(" |");
	else if ( plateau[i][j] == 1 )
	  printf("T|");
	else 
	  printf("C|");
      }
      printf("\n");
  }
}

void placer_chevre ( int x, int y){
  if ( plateau[y][x] == 0)
    plateau[y][x]=2;
  else
    printf("Erreur case déjà occupée\n");
}

int main (){
  int x, y;
  initialiser_plateau();
  affichage_plateau();
  printf("Entrez la position a laquelle vous voulez mettre la chèvre ");
  scanf("%d",&x);
  scanf("%d",&y);
  placer_chevre(x,y);
  affichage_plateau();
  return 0;
}