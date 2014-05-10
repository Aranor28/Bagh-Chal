#ifndef ENTREE_SOURIS_H
#define ENTREE_SOURIS_H

int ES_recuperer_action (int * x_grille, int * y_grille);
int ES_recuperer_choix_menu();
void ES_recuperer_entree (int * x_win, int * y_win);
bool ES_dans_plateau (int type);

#endif