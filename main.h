#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>

#define WIDTH 22    /* LARGEUR DU PLATEAU */
#define HEIGHT 16    /* LONGUEUR DU PLATEAU */

#define STARTX 50  /*Position a laquelle va commencer l'affichage en x*/
#define STARTY 10   /*Position a laquelle va commencer l'affichage en y*/

/* Définition des phases de jeu */
#define PLACEMENT 1
#define DEPLACEMENT 2

/* Nom du fichier dans lequel sera écrit la sauvegarde */
#define NOM_FICHIER_SAUVEGARDE1 "sauvegarde1.txt"
#define NOM_FICHIER_SAUVEGARDE2 "sauvegarde2.txt"
#define NOM_FICHIER_SAUVEGARDE3 "sauvegarde3.txt"

/* Définition des cases */
#define VIDE 0
#define TIGRE 1
#define CHEVRE 2
#define PAS_CASE 3
#define HORS_PLATEAU 4

/* Définition des boutons */
#define SAUVEGARDER 5
#define CHARGER 6
#define ANNULER 7
#define QUITTER 8

/* Différentes cases pendant le menu */
#define JCJ 1
#define IA_TIGRE 2
#define IA_CHEVRE 3
#define AIDE 9

/* Emplacements de sauvegarde */
#define FICH1 10
#define FICH2 11
#define FICH3 12

/* DEFINITION DU PLATEAU */
typedef struct et_plateauBC {
	int grille [5][5];
	int nb_chevres_placees;
	int nb_chevres_mangees;
	int joueur_courant;
	int phase;
} PlateauBC;

/* Prototypes */

/* 
 * Initialise le plateau de jeu
 * Place les tigres dans chaque angles.
 * Initialise le nombre de chèvres en réserve, et le nombre mangées
 * Initialise la phase de jeu
 * Initialise NCURSES
 */
void main_initialisation ();

/* 
 * Incrémente le tour du joueur 
 */
void main_joueur_suivant ();

/* Déclaration de la variable globale */
PlateauBC plateau;

#endif