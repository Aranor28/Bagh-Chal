
void recupererSouris() {
	int c;
	MEVENT event; // récupèrera l'évènement

	mousemask(ALL_MOUSE_EVENTS, NULL); // permet de récupérer tous les évènements de la souris
	while(1) {
		keypad(stdscr, TRUE); // permet de récupérer les entrées souris
		c = getch(); // récupère une entrée 
		switch(c) {
			case KEY_MOUSE:
			if (getmouse(&event) == OK) {
				if(event.bstate & BUTTON1_CLICKED) { // si le bouton gauche a été préssé
					mvprintw(LINES-1, 4, "position x=%d, y=%d", event.x, event.y);
					refresh();
				}
			}
			break;

			default:
				mvprintw(LINES-1,0, "pas un clic de souris");
				break;
		}
	}
}