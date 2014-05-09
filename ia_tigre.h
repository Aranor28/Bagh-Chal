#ifndef IA_TIGRE_H
#define IA_TIGRE_H

#include <stdbool.h>
#include "main.h"

void ia_tigre_deplacement();
bool ia_tigre_mange_chevre(int x, int y, int * x2, int * y2);
bool ia_deplacer_tigre (int x, int y);

#endif