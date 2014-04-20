


int deplacement_tigre (int x1, int y1, int x2, int y2, int * nb_chevre_mangee){
	int retour = 0;

	if (plateau[x1][y1] == TIGRE && plateau[x2][y2] == VIDE){
		if ((abs(x1-x2) == 1)&& (abs(y1-y2) == 1) && ((((y1 % 2) == 0) && ((x1 % 2) == 0)) || (((y1 % 2) != 0) && ((x1 % 2) != 0)))){
					plateau[x1][y1] = VIDE;
					plateau[x2][y2] = TIGRE;
		}
		else if ((abs(x1-x2) == 1)&& (abs(y1-y2) == 0)){
					plateau[x1][y1] = VIDE;
					plateau[x2][y2] = TIGRE;
		}
		else if ((abs(x1-x2) == 0)&& (abs(y1-y2) == 1)){
					plateau[x1][y1] = VIDE;
					plateau[x2][y2] = TIGRE;
		}
		else if ((abs(x1-x2) == 2) && (abs(y1-y2) == 0) && (plateau[(x1+x2)/2][(y1+y2)/2] == CHEVRE)){
					plateau[x1][y1] = VIDE;
					plateau[x2][y2] = TIGRE;
					plateau[(x1+x2)/2][(y1+y2)/2] = VIDE;
					*nb_chevre_mangee = *nb_chevre_mangee + 1;
		}
		else if ((abs(x1-x2) == 0) && (abs(y1-y2) == 2) && (plateau[(x1+x2)/2][(y1+y2)/2] == CHEVRE)){
					plateau[x1][y1] = VIDE;
					plateau[x2][y2] = TIGRE;
					plateau[(x1+x2)/2][(y1+y2)/2] = VIDE;
					*nb_chevre_mangee = *nb_chevre_mangee + 1;
		}
		else if (((x1 % 2) == 0) && ((x2 % 2) == 0) && ((y1 % 2) == 0) && ((y2 % 2) == 0) && (plateau[(x1+x2)/2][(y1+y2)/2] == CHEVRE)){
					plateau[x1][y1] = VIDE;
					plateau[x2][y2] = TIGRE;
					plateau[(x1+x2)/2][(y1+y2)/2] = VIDE;
					*nb_chevre_mangee = *nb_chevre_mangee + 1;
		}
		else
			retour = 1;
	}
	else 
		retour = 1;

	return(retour);
}


void verification_deplacement_tigre (int * nb_chevre_mangee){
	int retour, x, y, x2, y2;

	do {
		scanf("%d %d %d %d",&x,&y,&x2,&y2);
		retour = deplacement_tigre(x,y,x2,y2,nb_chevre_mangee);
	}while(retour != 0);
}


