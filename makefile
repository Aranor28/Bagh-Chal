#makefile bagh_chal
CC=gcc
CFLAGS=-Wall -std=c99 -lncurses
EXEC=bagh_chal

all : $(EXEC)

$(EXEC): main.o affichage.o entreeSouris.o deplacement_tigre.o placement_chevre.o
	$(CC) main.o affichage.o entreeSouris.o deplacement_tigre.o placement_chevre.o -o $(EXEC) $(CFLAGS)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

affichage.o: affichage.c
	$(CC) -c affichage.c -o affichage.o $(CFLAGS)

entreeSouris.o: entreeSouris.c
	$(CC) -c entreeSouris.c -o entreeSouris.o $(CFLAGS)

deplacement_tigre.o: deplacement_tigre.c
	$(CC) -c deplacement_tigre.c -o deplacement_tigre.o $(CFLAGS)

placement_chevre.o: placement_chevre.c
	$(CC) -c placement_chevre.c -o placement_chevre.o $(CFLAGS)


clean:
	rm -rf *.o

maxclean:
	rm -rf *.o $(EXEC)