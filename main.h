#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>

#define WIDTH 22    /* LARGEUR DU PLATEAU */
#define HEIGHT 16    /* LONGUEUR DU PLATEAU */
// #define 5 5
// #define 5 5

#define STARTX 50  /*Position a laquelle va commencer l'affichage en x*/
#define STARTY 10   /*Position a laquelle va commencer l'affichage en y*/

#define PLACEMENT 1
#define DEPLACEMENT 2

#define NOM_FICHIER_SAUVEGARDE "sauvegarde.txt"

/* *** Définition des cases *** */
#define VIDE 0

/* Différentes cases pendent la partie */
#define TIGRE 1
#define CHEVRE 2
#define PAS_CASE 3
#define SAUVEGARDER 4
#define CHARGER 5
#define ANNULER 6
#define QUITTER 7
#define HORS_PLATEAU 9

/* Différentes cases pendent le menu */
#define JCJ 1
#define IA_TIGRE 2
#define IA_CHEVRE 3
#define AIDE 8

/* DEFINITION DU PLATEAU */
typedef struct et_plateauBC {
	int grille [5][5];
	int nb_chevres_placees;
	int nb_chevres_mangees;
	int joueur_courant;
	int phase;
} PlateauBC;

/* Prototypes */
void main_initialisation ();
void main_joueur_suivant ();
void debug (char str[], int n);

/* Déclaration de la variable globale */
PlateauBC plateau;

#endif