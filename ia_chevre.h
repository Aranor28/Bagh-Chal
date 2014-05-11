#ifndef IA_CHEVRE_H
#define IA_CHEVRE_H

#include <stdbool.h>

#include "main.h"


/* 
 * Place une chèvre sur une case libre .
 * Vérifie qu'un tigre ne puisse pas la manger au tour suivant.
 */
void ia_chevre_placement ();

/* Sélectionne une chèvre du plateau et la place sur l'une des cases vides où elle peut accéder
 * Vérifie la légalité du déplacement
 * Fait attention à ne pas placer une chèvre si elle peut se faire manger par un tigre au tour suivant
 * Si tous les déplacements amènent à ce qu'une chèvre soit mangée, il en déplace une malgrès tout
 */
void ia_chevre_deplacement ();


/* 
 * Calcule, à partir d'une case où serait une chèvre, si un tigre peut la manger au tour suivant
 */
bool ia_chevre_en_danger (int x, int y);

#endif