


int deplacement_tigre (int x1, int y1, int x2, int y2){
	int retour=0;

	if (plateau[x1][y1] == TIGRE && plateau[x2][y2] == VIDE){
		plateau[x1][y1] = VIDE;
		plateau[x2][y2] = TIGRE;
	}
	else 
		retour = 1;

	return(retour);
}


void verification_deplacement_tigre (){
	int retour, x, y, x2, y2;

	do {
		scanf("%d %d %d %d",&x,&y,&x2,&y2);
		retour = deplacement_tigre(x,y,x2,y2);
	}while(retour != 0);
}


