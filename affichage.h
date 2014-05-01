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

#define X_CHAMP_ERREUR 4
#define Y_CHAMP_ERREUR LINES-1

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

void affichage_init_color_pairs ();
void affichage ();
void affichage_pion ();
void affichage_plateau ();
void affichage_info ();
void affichage_bouttons();
void affichage_surbrillance (int x, int y);
void affichage_gagnant (int nb_chevres_mangees, int nb_tigres_bloques);

#endif