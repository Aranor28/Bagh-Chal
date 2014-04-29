#include <stdlib.h>
#include "fin_partie.h"

int detection_fin_partie (int nb_chevre_mangee, int nb_tigre_bloque){
	if (nb_chevre_mangee == 2)
		return (1);
	if (nb_tigre_bloque == 4)
		return (2);
	else 
		return (0);
}
