game:main.o lifegame.o
	gcc main.o lifegame.o -o game

lifegame.o:lifegamecore.c
	gcc -c lifegamecore.c -o lifegame.o

main.o:main.c
	gcc -c main.c -o main.o

clean:
	rm -rf *.o