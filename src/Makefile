puissance4: main.o display.o game.o grid.o minimax.o
	gcc -o puissance4 main.o display.o game.o grid.o minimax.o

main.o: main.c
	gcc -c main.c

display.o: display.c
	gcc -c display.c

game.o: game.c
	gcc -c game.c

grid.o: grid.c
	gcc -c grid.c

minimax.o: minimax.c
	gcc -c minimax.c

clean:
	rm *.o *~
