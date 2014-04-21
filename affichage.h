#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#define STARTX 10  /*Position a laquelle va commencer l'affichage en x*/
#define STARTY 50   /*Position a laquelle va commencer l'affichage en y*/

void affichage_pion();
void affichage_plateau();
void affichage_info(int nb_chevre_reserve, int nb_chevre_mangee,int joueur);
void affichage (int nb_chevre_reserve, int nb_chevre_mangee, int joueur);

#endif