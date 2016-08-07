FILES = Block.c Cell.c Game.c Grid.c GUI.c High_score.c Hold.c main.c Score.c
LIBS = -lSDL -lSDLmain -lSDL_image
CFLAGS= "-D_SDL_main_h"
CC= gcc
all: $(FILES)
	$(CC) $(FILES) $(LIBS) $(CFLAGS) -L./ -o tetris 
