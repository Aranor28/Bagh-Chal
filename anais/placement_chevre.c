
int placement_chevre (int x, int y){
	int retour=0;

	/*Si l'intersection souhaitée n'est pas valide*/
	if (x > 4 || y > 4 || plateau[x][y] != VIDE)
		retour=1;
	else
		plateau[x][y] = CHEVRE;

	return(retour);
}


void verification_placement_chevre (int * nb_chevre_reserve){
	int retour, x, y;

	do {
		scanf("%d %d",&x,&y);
		retour = placement_chevre (x,y);
	}while(retour != 0);

	*nb_chevre_reserve = *nb_chevre_reserve + 1;
}


