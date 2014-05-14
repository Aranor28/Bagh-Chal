#ifndef ENTREE_SOURIS_H
#define ENTREE_SOURIS_H

/*
 * Récupère un clic de souris et renvoi le type de bouton cliqué au cours de la partie
 * en fonction des coordonnées du clic
 */
int ES_recuperer_action (int * x_grille, int * y_grille);

/*
 * Récupère un clic de souris et renvoi le type de bouton cliqué dans le menu 
 * en fonction des coordonnées du clic.
 */
int ES_recuperer_choix_menu();

/*
 * Attends un clic gauche de souris.
 * Si le bouton gauche est cliqué on met à jour les coordonnées.
 * Out : - l'abscisse cliquée
 * 		 - l'ordonnée cliquée
 */
void ES_recuperer_entree (int * x_win, int * y_win);

/* 
 * Retourne vrai si le type de case est situé dans le plateau de jeu
 */
bool ES_dans_plateau (int type);
int ES_recuperer_sauvegarde ();

#endif