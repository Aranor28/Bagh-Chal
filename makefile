#makefile bagh_chal
CC=gcc
CFLAGS=-Wall -std=c99 -lncurses
EXEC=bagh_chal

all : $(EXEC)

$(EXEC): main.o affichage.o entree_souris.o deplacement_tigre.o placement_chevre.o fin_partie.o sauvegarde.o
	$(CC) main.o affichage.o entree_souris.o deplacement_tigre.o placement_chevre.o fin_partie.o sauvegarde.o -o $(EXEC) $(CFLAGS)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

affichage.o: affichage.c
	$(CC) -c affichage.c -o affichage.o $(CFLAGS)

entree_souris.o: entree_souris.c
	$(CC) -c entree_souris.c -o entree_souris.o $(CFLAGS)

deplacement_tigre.o: deplacement_tigre.c
	$(CC) -c deplacement_tigre.c -o deplacement_tigre.o $(CFLAGS)

placement_chevre.o: placement_chevre.c
	$(CC) -c placement_chevre.c -o placement_chevre.o $(CFLAGS)

fin_partie.o: fin_partie.c
	$(CC) -c fin_partie.c -o fin_partie.o $(CFLAGS)

sauvegarde.o: sauvegarde.c
	$(CC) -c sauvegarde.c -o sauvegarde.o $(CFLAGS)

clean:
	rm -rf *.o

maxclean:
	rm -rf *.o $(EXEC)