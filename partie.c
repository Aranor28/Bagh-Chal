#include <stdlib.h>
#include <stdbool.h>
#include "partie.h"

bool detection_fin_partie (int nb_chevre_mangee, int nb_tigre_bloque){
		return (nb_chevre_mangee == 7 || nb_tigre_bloque == 4);
}
