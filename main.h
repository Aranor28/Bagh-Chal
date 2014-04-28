#ifndef MAIN_H
#define MAIN_H

#define WIDTH 22    /* LARGEUR DU PLATEAU */
#define HEIGHT 16    /* LONGUEUR DU PLATEAU */
#define NB_CASES_X 5
#define NB_CASES_Y 5

#define STARTX 50  /*Position a laquelle va commencer l'affichage en x*/
#define STARTY 10   /*Position a laquelle va commencer l'affichage en y*/

#define PLACEMENT 1
#define DEPLACEMENT 2

#define NOM_FICHIER_SAUVEGARDE "sauvegarde.txt"

/* Différentes cases */
#define VIDE 0
#define TIGRE 1
#define CHEVRE 2
#define PAS_CASE 3
#define SAUVEGARDER 4
#define CHARGER 5

/* DEFINITION DU PLATEAU */
typedef struct et_plateauBC {
	int grille [NB_CASES_X][NB_CASES_Y];
	int nb_chevres_placees;
	int nb_chevres_mangees;
	int joueur_courant;
	int phase;
} PlateauBC;

/* Prototypes */
void main_initialisation ();
void main_joueur_suivant ();
void debug (char str[]);

/* Déclaration de la variable globale */
PlateauBC plateau;

#endif