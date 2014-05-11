#ifndef TIGRES_H
#define TIGRES_H

#include "main.h"

/* 
 * Sélectionne un tigre et le place dans une de ces cases adjacentes.
 * Vérifie que l'utilisateurs ait bien sélectionner un tigre.
 * Vérifie que la case d'arrivée soit vide et la légalité du coup
 */
void tigre_deplacement (int x1, int y1, int * gagnant, PlateauBC * plateauAvant);

/* 
 * Calcule si un tigre peut manger une chèvre au alentour de lui
 */
bool saute_chevre (int x1, int y1, int x2, int y2);

#endif