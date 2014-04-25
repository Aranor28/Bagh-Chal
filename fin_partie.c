#include <stdlib.h>
#include "fin_partie.h"

void detection_fin_partie (int nb_chevre_mangee, int nb_tigre_bloque){
	if (nb_chevre_mangee == 7)
		exit(1);
	if (nb_tigre_bloque == 4)
		exit(2);
}
