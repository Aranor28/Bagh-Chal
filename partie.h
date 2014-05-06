#ifndef PARTIE_H
#define PARTIE_H

#include <stdbool.h>

bool cases_adjacentes (int x1, int y1, int x2, int y2);
void detection_fin_partie (int nb_chevre_mangee, int nb_tigre_bloque);
int partie_detection_vainqueur ();
bool partie_tigre_bloque (int x, int y);
bool partie_prolongation_vide (int x1, int y1, int x2, int y2);

#endif