#ifndef PARTIE_H
#define PARTIE_H

#include <stdbool.h>

bool partie_cases_adjacentes (int x1, int y1, int x2, int y2);
int partie_detection_vainqueur ();
bool partie_tigre_bloque (int x, int y);
bool partie_prolongation_vide (int x1, int y1, int x2, int y2);
bool partie_chevres_bloquees ();
bool partie_pion_adjacent (int x, int y, int type, int * x_pion, int * y_pion);

#endif