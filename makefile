#makefile bagh_chal
CC=gcc
CFLAGS=-Wall -std=c99 -lncurses
EXEC=bagh_chal

all : $(EXEC)

$(EXEC): main.o affichage.o entree_souris.o tigre.o chevre.o partie.o sauvegarde.o chargement.o
	$(CC) main.o affichage.o entree_souris.o tigre.o chevre.o partie.o sauvegarde.o chargement.o -o $(EXEC) $(CFLAGS)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

affichage.o: affichage.c
	$(CC) -c affichage.c -o affichage.o $(CFLAGS)

entree_souris.o: entree_souris.c
	$(CC) -c entree_souris.c -o entree_souris.o $(CFLAGS)

tigre.o: tigre.c
	$(CC) -c tigre.c -o tigre.o $(CFLAGS)

chevre.o: chevre.c
	$(CC) -c chevre.c -o chevre.o $(CFLAGS)

partie.o: partie.c
	$(CC) -c partie.c -o partie.o $(CFLAGS)

sauvegarde.o: sauvegarde.c
	$(CC) -c sauvegarde.c -o sauvegarde.o $(CFLAGS)

chargement.o: chargement.c
	$(CC) -c chargement.c -o chargement.o $(CFLAGS)

clean:
	rm -rf *.o

maxclean:
	rm -rf *.o $(EXEC)