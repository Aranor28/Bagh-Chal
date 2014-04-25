#ifndef MAIN_H
#define MAIN_H

#define WIDTH 5    /* LARGEUR DU PLATEAU */
#define HEIGHT 5    /* LONGUEUR DU PLATEAU */

#define VIDE 0
#define TIGRE 1
#define CHEVRE 2

#define JOUEUR_CHEVRE 0
#define JOUEUR_TIGRE 1

/* DEFINITION DU PLATEAU */
int plateau [WIDTH][HEIGHT];

void initialiser_plateau ();

#endif