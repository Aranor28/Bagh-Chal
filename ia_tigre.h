#ifndef IA_TIGRE_H
#define IA_TIGRE_H

#include <stdbool.h>

#include "main.h"

/*
 * Déplace un tigre sur le plateau de jeu 
 * Vérifie la légalité du coup 
 * Déplace en priorité un tigre qui peut manger une chèvre
 */
void ia_tigre_deplacement();

/*
 * Calcule si un tigre peut manger une chèvre à proximité de lui
 */
bool ia_tigre_mange_chevre(int x, int y, int * x2, int * y2);

/* 
 * Vérifie qu'un déplacement soit bien valide
 * Vérifie si le tigre peut se déplacer en diagonnale ou non
 */
bool ia_tigre_deplacment_valide (int x, int y);

#endif