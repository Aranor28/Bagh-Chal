#ifndef PARTIE_H
#define PARTIE_H

#include <stdbool.h>

/* 
 * Renvoi vrai si les deux cases de coordonnées respectives
 * (x1, y1) et (x2, y2) sont adjacentes, en prenant comptes des diagonales.
 */
bool partie_cases_adjacentes (int x1, int y1, int x2, int y2);

/*
 * Effectue les vérification des conditions de victoire en fonction du joueur courant,
 * renvoi le vainqueur si il y en a un (TIGRE ou CHEVRE), sinon renvoi VIDE.
 */
int partie_detection_vainqueur ();

/* 
 * renvoi vrai si le tigre en position (x, y) ne peut pas se déplacer ni manger de chèvre
 */
bool partie_tigre_bloque (int x, int y);

/*
 * Renvoi vrai si la prolongation de la case (x1, y1) au dessus de la case (x2, y2) est vide,
 * tel la case de destination d'un tigre qui mangerait une chèvre 
 */
bool partie_prolongation_vide (int x1, int y1, int x2, int y2);

/*
 * Renvoi vrai si aucune case vide n'est accessible par une chèvre,
 * c'est à dire si toutes les chèvres sont bloquées
 */
bool partie_chevres_bloquees ();

/*
 * Fonction multi-usages, renvoi vrai si un pion de type "type" est adjacent
 * à la case (x, y), et renvoi les corrdonnées de ce pion (x_pion, y_pion).
 * type peut contenir CHEVRE, TIGRE ou VIDE.
 */
bool partie_pion_adjacent (int x, int y, int type, int * x_pion, int * y_pion);

#endif