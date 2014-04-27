#include <stdio.h>
#include <string.h>
#include "main.h"
#include "ouverture.h"


int ouverture (char * nomFich, int * tigre_bloque, int * phase, int * joueur){
	int i,j,valeur;
	//char * temp;
	char temp;
	char chaine[13];

	FILE * fich = fopen(nomFich,"r");
	if (fich == NULL){
		fprintf(stderr, "Erreur lors de l'ouverture du fichier\n");
		return (1);
	}

	fscanf(fich, "%s", chaine);
	if ( !strcmp(chaine,"\board") ){
		fprintf(stderr, "Erreur de fichier\n");
		return (1);
	}
	fscanf(fich,"%c",&temp);

	for (i = 0; i < 5; i++){
		for (j = 0; j < 5; j++){
			fscanf(fich,"%c",&temp);
			if ( temp == 'T')
				plateau[i][j] = 'T';
			else if (temp == 'G')
				plateau[i][j] = 'G';
			else if (temp == '.')
				plateau[i][j] = ' ';
		}
		fscanf(fich,"%c",&temp);
		printf("\n");
	}

	/*VERIFICATION QUE LE TABLEAU SE FINIT PAR \endboard\n*/
	fscanf(fich, "%s", chaine);
	if ( !strcmp(chaine,"\endboard") ){
		fprintf(stderr, "Erreur de fichier\n");
		return (1);
	}

	/*VERIFICATION DU JOUEUR*/
	fscanf(fich, "%c%s",&temp,chaine);
	if ( !strcmp(chaine,"\player") ){
		fprintf(stderr, "Erreur de fichier\n");
		return (1);
	}

	fscanf(fich,"%c",&temp);
	fscanf(fich,"%c",&temp);
	if (temp != 'T' && temp != 'G'){
		fprintf(stderr, "Erreur de joueur\n");
		return (1);
	}
	if (temp == 'T')
		*joueur = 1;
	else
		*joueur = 0;

	/*VERIFICATION DE LA PHASE*/
	fscanf(fich,"%c",&temp);
	fscanf(fich, "%s", chaine);
	if ( !strcmp(chaine,"\phase") ){
		fprintf(stderr, "Erreur de fichier\n");
		return (1);
	}

	fscanf(fich,"%c%d",&temp,phase);
	if (valeur != 1 && valeur != 2){
		fprintf(stderr, "Erreur de fichier\n");
		return (1);
	}

	/*VERIFICATION DES TIGRES CAPTURES*/
	fscanf(fich, "%c%s",&temp, chaine);
	if ( !strcmp(chaine,"\captured") ){
		fprintf(stderr, "Erreur de fichier\n");
		return (1);
	}

	fscanf(fich,"%c%d",&temp,tigre_bloque);
	if (valeur < 0 && valeur > 4){
		fprintf(stderr, "Erreur de fichier\n");
		return (1);
	}

	return (0);

}

