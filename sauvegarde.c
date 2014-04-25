
/* AFFICHE DANS LE FICHIER DE SAUVEGARDE :
 * LE PLATEAU LIGNE PAR LIGNE
 * LE NOMBRE DE CHEVRES PLACEES
 * LE NOMBRE DE CHEVRES MANGEES
 * LE TOUR DU JOUEUR SUIVANT
 */


void sauvegarde (int phase,int tigre_capture,int joueur){
	int i,j;

	FILE * fich = fopen("sauvegarde.txt","w");
	if (fich == NULL){
		fprintf(stderr, "Erreur lors de la sauvegarde du plateau\n");
		return;
	}
	fprintf(fich, "\\board\n");
	printf("La\n");
	for (i = 0; i < 5; i++){
		for (j = 0; j < 5; j++)	{
			if (plateau[j][i] == TIGRE)
				fprintf(fich,"T");
			else if (plateau[j][i] == CHEVRE)
				fprintf(fich,"G");
			else
				fprintf(fich,".");
		}
		printf("\n");
	}
	fprintf(fich,"\\endboard\n");
	if (joueur == TIGRE)
		fprintf(fich,"\\player T\n");
	else
		fprintf(fich,"\\player G\n");
	fprintf(fich,"\\phase %d\n",phase);
	fprintf(fich,"\\captured %d\n",tigre_capture);
	fclose(fich);

	
}