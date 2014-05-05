#ifndef PARTIE_H
#define PARTIE_H

#include <stdbool.h>

void detection_fin_partie (int nb_chevre_mangee, int nb_tigre_bloque);
int partie_detection_vainqueur ();
bool partie_tigre_bloque (int x, int y);

#endif