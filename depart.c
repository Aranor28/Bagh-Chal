#include "affichage.c"
#include "entreeSouris.c"

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

void initialiser_ncurses() {
	initscr();
	clear();
	noecho();
	cbreak();
}

int main (){
	endwin(); // j'en avais besoin pour avoir des coordonnées correctes, je quittais avec ctrl+c
	initialiser_ncurses();
	curs_set(0);
	initialiser_plateau();
	affichage_plateau(0);
	recupererSouris();
	endwin();
	return 0;
}