/*
 * GUI.c
 *
 *  Created on: Jul 24, 2016
 *      Author: asma
 */
#include"GUI.h"

static SDL_Surface *window;


/*
 * Maakt het hele venster terug blanco.
 */
void clear_screen() {
	SDL_FillRect(window, NULL, 0xFFFFFFFF);
	SDL_Flip(window);
}


void initialize_window(char *title) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Could not initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	int window_width = 500;
	int window_height = 500;
	window = SDL_SetVideoMode(window_width, window_height, 0, SDL_HWPALETTE | SDL_DOUBLEBUF);
	if (window == NULL) {
		printf("Couldn't set screen mode to required dimensions: %s\n", SDL_GetError());
		exit(1);
	}
	/* Set the screen title */
	SDL_WM_SetCaption(title, NULL);
}

void cleanup() {
	/* Shut down SDL */
	SDL_Quit();
}

void initialize_gui() {
	initialize_window("Tetris");
	atexit(cleanup);
}
