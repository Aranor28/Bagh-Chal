#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

void testAffichage1 () {
	initscr();
	start_color();
	init_pair(1, COLOR_RED, COLOR_CYAN);
	init_pair(2, COLOR_YELLOW, COLOR_GREEN);
	attron(A_UNDERLINE | COLOR_PAIR(1));
	curs_set(0);
	mvprintw(5, 5, "Coucou doudou !!! <3");
	attroff(A_UNDERLINE | COLOR_PAIR(1));
	attron(A_BOLD | COLOR_PAIR(2));
	mvprintw(10, 5, "Coeur :*");
	attroff(A_BOLD | COLOR_PAIR(2));
	refresh();
	getch();
	endwin();
}

void testMouseInput () {
	 
	initscr(); // initialise Ncurses (vérifier la valeur de retour ?)
  	noecho(); // empêche l'affichage du caractère tapé sur la console
  	cbreak(); // block le buffering des caractères mais autorise le ctrl+c
  	keypad(stdscr, TRUE); // Autorise l'utilisation des touches F1... et des touches fléchées

  	mousemask(  mmask_t newmask,    /* The events you want to listen to */
                mmask_t *oldmask)    /* The old events mask                */

  	MEVENT event; // l'évènement récupéré

  	ch = getch();
  	if (ch == KEY_MOUSE) {
  		if (getmouse(&event) == OK) {
  			if(event.bstate & BUTTON1_PRESSED)
        		printw("Left Button Pressed");
  		}
  	}

 //  	raw (); 
 //  	nodelay(stdscr,1); 
 //  	curs_set(0); 
 //  	nonl(); 
 //  	keypad(stdscr,1); // active la détection du curseur et des touches pour le programme
 //  	mousemask (ALL_MOUSE_EVENTS, NULL);
	 
	// mvprintw (0,30, "Press q to quit");
	// refresh();
	
	// do { // A nasty 100% resource hogging loop, I know. Sorry about that.
	// 	input = wgetch(stdscr);
	
	//     if (input == KEY_MOUSE) {
	// 		getmouse (&mouseinput);
	// 		mvprintw (11, 30, "  x = %d  y = %d   ", mouseinput.x, mouseinput.y);
	// 		mvaddch (mouseinput.y, mouseinput.x, 'X');
	// 		refresh ();
	//     }
	 
	// } while (input != 'q');
	 
	endwin(); // restaure les paramètres du terminal
}