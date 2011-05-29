all:projet

projet: ./objet/main.o ./objet/ville.o ./objet/graphe.o ./objet/Liste_ville.o ./objet/noeud.o ./objet/menu.o ./objet/kruskal.o
	gcc -o projet ./objet/main.o ./objet/ville.o ./objet/graphe.o ./objet/Liste_ville.o ./objet/noeud.o ./objet/menu.o ./objet/kruskal.o -lm -ansi

./objet/main.o :./src/source/main.c ./src/headers/ville.h ./src/headers/graphe.h ./src/headers/Liste_ville.h ./src/headers/noeud.h ./src/headers/kruskal.h
	gcc -o ./objet/main.o  -c ./src/source/main.c -lm  -W -Wall -ansi

./objet/ville.o : ./src/source/ville.c ./src/headers/ville.h
	gcc -o ./objet/ville.o -c ./src/source/ville.c -lm  -W -Wall -ansi 

./objet/Liste_ville.o : ./src/source/Liste_ville.c ./src/headers/Liste_ville.h ./src/headers/noeud.h
	gcc -o ./objet/Liste_ville.o -c ./src/source/Liste_ville.c -lm -W -Wall -ansi

./objet/noeud.o : ./src/source/noeud.c ./src/headers/noeud.h ./src/headers/ville.h
	gcc -o ./objet/noeud.o -c ./src/source/noeud.c -lm -W -Wall -ansi

./objet/graphe.o : ./src/source/graphe.c ./src/headers/graphe.h ./src/headers/noeud.h
	gcc -o ./objet/graphe.o -c ./src/source/graphe.c -lm -W -Wall -ansi

./objet/menu.o : ./src/source/menu.c ./src/headers/menu.h ./src/headers/noeud.h
	gcc -o ./objet/menu.o -c ./src/source/menu.c -lm -W -Wall -ansi

./objet/kruskal.o : ./src/source/kruskal.c ./src/headers/kruskal.h ./src/headers/graphe.h
	gcc -o ./objet/kruskal.o -c ./src/source/kruskal.c -lm -W -Wall -ansi

clean:
	rm projet ./objet/main.o ./objet/ville.o ./objet/graphe.o ./objet/Liste_ville.o ./objet/noeud.o ./objet/kruskal.o
