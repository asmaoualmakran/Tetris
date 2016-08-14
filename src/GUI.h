/*
 * GUI.h
 *
 *  Created on: Jul 24, 2016
 *      Author: asma
 */

#ifndef GUI_H_
#define GUI_H_
#include "SDL/SDL.h"
#include "Grid.h"
#include "Cell.h"
#include "Hold.h"
#include "Block.h"
#include"Game.h"

#define EXTRA_WIDTH 150
#define EXTRA_HEIGHT 150

static SDL_Surface* window;

//static const int WINDOW_WIDTH = EXTRA_WIDTH + GRID_WIDTH;
//static const int WINDOW_HEIGHT = EXTRA_HEIGHT + GRID_HEIGHT;
//static const char* WINDOW_TITLE = "Tetris";
void init_window();
void run_window();
void close_window();
void draw_grid(struct Cell ***grid);
int *get_SDL_colour(struct Cell *cell);
void clear_grid();


#endif /* GUI_H_ */
