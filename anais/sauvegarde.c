
/* AFFICHE DANS LE FICHIER DE SAUVEGARDE :
 * LE PLATEAU LIGNE PAR LIGNE
 * LE NOMBRE DE CHEVRES PLACEES
 * LE NOMBRE DE CHEVRES MANGEES
 * LE TOUR DU JOUEUR SUIVANT
 */


void sauvegarde (chevre_placee,chevre_mangee,joueur){
	int i,j;

	FILE * fich = fopen("sauvegarde.txt","w");
	if (fich == NULL){
		fprintf(stderr, "Erreur lors de la sauvegarde du plateau\n");
		return;
	}

	for (i = 0; i < 5; i++){
		for (j = 0; i < 5; j++)	{
			fprintf(fich,"%d",plateau[i][j]);
		}
		fprintf(fich,"\n");
	}
	fprintf(fich,"%d\n",chevre_placee);
	fprintf(fich,"%d\n",chevre_mangee);
	fprintf(fich,"%d\n",joueur);
	
}