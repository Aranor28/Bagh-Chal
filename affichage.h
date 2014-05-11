#ifndef AFFICHAGE_H
#define AFFICHAGE_H

/* 
 * Position et affichage des informations de la partie
 */
#define X_NBCHEVRES 90
#define Y_NBCHEVRES 15

#define X_TOUR_JOUEUR 45
#define Y_TOUR_JOUEUR 8 	

/* 
 * Position et contenu des boutons utilitaires
 */
#define BOUTTON_SAUVEGARDER " SAUVEGARDER "
#define X_SAUVEGARDER 15
#define Y_SAUVEGARDER 15

#define BOUTTON_CHARGER "   CHARGER   "
#define X_CHARGER 15
#define Y_CHARGER 17

#define BOUTTON_ANNULER "   ANNULER   "
#define X_ANNULER 15
#define Y_ANNULER 19

#define BOUTTON_QUITTER "   QUITTER   "
#define X_QUITTER 15
#define Y_QUITTER 21

#define X_CHAMP_ERREUR 4
#define Y_CHAMP_ERREUR LINES-1

#define X_LIGNE_INFO 2
#define Y_LIGNE_INFO 30	

/* 
 * Position et contenu des boutons du menu 
 */
#define BIENVENUE "Bienvenue sur le jeu du Bagh-Chal ! Sélectionnez ce que vous voulez faire :"
#define X_BIENVENUE 20
#define Y_BIENVENUE 8

#define BOUTTON_JcJ " Joueur contre Joueur "
#define X_MENU_JcJ 35
#define Y_MENU_JcJ 10

#define BOUTTON_JcIA_CHEVRE " Jouer Tigre contre Ordinateur Chèvre "
#define X_MENU_JcIA_CHEVRE 35
#define Y_MENU_JcIA_CHEVRE 14

#define BOUTTON_JcIA_TIGRE " Jouer Chevre contre Ordinateur Tigre "
#define X_MENU_JcIA_TIGRE 35
#define Y_MENU_JcIA_TIGRE 12

#define BOUTON_AFFICHER_AIDE "Afficher l'aide"
#define X_MENU_AIDE 100
#define Y_MENU_AIDE 1


/*
 * Paires de couleurs 
 */
#define COULEURS_NBCHEVRES_PLACEES 1
#define COULEURS_NBCHEVRES_MANGEES 2
#define COULEURS_TOUR_TIGRE 3
#define COULEURS_TOUR_CHEVRE 4
#define COULEURS_CASE_VIDE 5
#define COULEURS_CASE_TIGRE 6
#define COULEURS_CASE_CHEVRE 7
#define COULEURS_CASE_TIGRE_SURBRILLANCE 8
#define COULEURS_CASE_CHEVRE_SURBRILLANCE 9
#define COULEURS_BOUTON_SAUVEGARDE 10
#define COULEURS_BOUTON_CHARGER 11
#define COULEURS_BOUTON_ANNULER 12
#define COULEURS_BOUTON_JcJ 13
#define COULEURS_BOUTON_JcIA_CHEVRE 14
#define COULEURS_BOUTON_JcIA_TIGRE 15
#define COULEURS_BOUTON_QUITTER 16
#define COULEURS_BIENVENUE 17
#define COULEURS_AIDE 18
#define COULEURS_INFO 19


/*
 * Initialise les paires de couleurs utilisees pour l'affichage 
 */
void affichage_init_color_pairs ();

/* 
 * Affiche le plateau de jeu, les boutons, et les informations relatives à la partie 
 */
void affichage ();

/*
 * Affiche les pions (Tigre ou Chèvre ou un espace s'il n'y a pas de pion) 
 * par dessus le plateau de jeu
 */
void affichage_pion ();

/* 
 * Affiche le plateau de jeu 
 */
void affichage_plateau ();

/* 
 * Affiche les informations relatives à la partie :
 * - Le nombre de chèvres en réserve
 * - Le nombre de chèvres mangées
 * - Le tour du joueur
 */
void affichage_info ();


/* 
 * Affiche les boutons utilitaires :
 * - Le bouton "Sauvegarder"
 * - Le bouton "Charger"
 * - Le bouton "Annuler"
 * - Le bouton "Quitter"
 */
void affichage_bouttons();


/* 
 * Met en surbrillance un pion sélectionné 
 */
void affichage_surbrillance (int x, int y);


/* 
 * Affiche le gagnant en fin de partie
 */
void affichage_gagnant (int gagnant);


/* 
 * Affiche des informations au cours de la partie :
 * En cas de sauvegarde ou de chargement.
 * En cas de déplacement impossible.
 */
void affichage_ligne_info (char s[]);

/*
 * Permet d'enlever l'affichage d'une information au cours de la partie 
 */
void affichage_vider_info ();


/*
 * Affiche le menu de départ 
 * L'utilisateur peut choisir 3 modes de jeu, ou afficher l'aide 
 */
void affichage_menu ();

/* 
 * Affiche l'aide à tout moment du jeu si l'utilisateur clique sur le bouton
 */
void affichage_aide ();

#endif