#ifndef CHEVRE_H
#define CHEVRE_H

#include "main.h"


/* 
 * Place une chèvre sur le plateau et vérifie la légalité du coup 
 */
void chevre_placement (int x, int y, int * gagnant, PlateauBC * plateauAvant);


/* 
 * Prend une chèvre et la place à un autre case de plateau 
 * Vérifie que l'utilisateur sélectionne une case valide (où il y a une chèvre)
 * et la place sur une case vide.
 */
void chevre_deplacement (int x1, int y1, int * gagnant, PlateauBC * plateauAvant);

#endif