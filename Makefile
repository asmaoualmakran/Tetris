CC = gcc
OBJ = Block.o Cell.o Game.o Grid.o GUI.o High_score.o main.o Score.o
LIBS = -lSDL -lSDLmain -lSDL_image
CFLAGS = "-D_SDL_main_h"



Block.o: Block.c Block.h Block_data.h Grid.h
	$(CC) Block.c $(FLAGS) -c -o Block.o

Cell.o: Cell.c Cell.h 
	$(CC) Block.c $(FLAGS) -c -o Cell.o

Game.o: Game.c Game.h High_score.h Hold.h GUI.h 
	$(CC) Game.c $(FLAGS) -c -o Game.o

Grid.o: Grid.c Grid.h Cell.h Block.h
	$(CC) Grid.c $(FLAGS) -c -o Grid.o

High_score.o: High_score.c High_score.h Score.h
	      $(CC) High_score.c $(FLAGS) -c -o High_score.o

GUI.o: GUI.c GUI.h  Game.h
	$(CC) GUI.c $(FLAGS) -c -o GUI.o

main.o: main.c main.h Game.h
	$(CC) main.c $(FLAGS) -c -o main.o

Score.o: Score.c Score.h
	$(CC) Score.c $(FLAGS) -c -o Score.o

all: 
	$(CC) $(OBJ) $(LIBS) $(FLAGS) -o tetris
 

clean:
	rm *.o
	rm tetris
