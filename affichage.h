#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#define X_NBCHEVRES 45
#define Y_NBCHEVRES 5

#define X_TOUR_JOUEUR 45
#define Y_TOUR_JOUEUR 8 	

#define BOUTTON_SAUVEGARDER " SAUVEGARDER "
#define X_SAUVEGARDER 5
#define Y_SAUVEGARDER 15

#define BOUTTON_CHARGER " CHARGER "
#define X_CHARGER 5
#define Y_CHARGER 17

#define BOUTTON_ANNULER " ANNULER "
#define X_ANNULER 5
#define Y_ANNULER 19

#define X_CHAMP_ERREUR 4
#define Y_CHAMP_ERREUR LINES-1

#define X_LIGNE_INFO 45
#define Y_LIGNE_INFO 28

#define BOUTTON_JcJ " Joueur contre Joueur "
#define X_MENU_JcJ 35
#define Y_MENU_JcJ 10

#define BOUTTON_JcIA_CHEVRE " Jouer Tigre contre Ordinateur Chèvre "
#define X_MENU_JcIA_CHEVRE 35
#define Y_MENU_JcIA_CHEVRE 14

#define BOUTTON_JcIA_TIGRE " Jouer Chevre contre Ordinateur Tigre "
#define X_MENU_JcIA_TIGRE 35
#define Y_MENU_JcIA_TIGRE 12

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
#define COULEURS_BOUTON_JcJ 12
#define COULEURS_BOUTON_JcIA_CHEVRE 13
#define COULEURS_BOUTON_JcIA_TIGRE 14

void affichage_init_color_pairs ();
void affichage ();
void affichage_pion ();
void affichage_plateau ();
void affichage_info ();
void affichage_bouttons();
void affichage_surbrillance (int x, int y);
void affichage_gagnant (int gagnant);
void affichage_ligne_info (char s[]);
void affichage_menu ();

#endif