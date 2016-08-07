/*
 * Field.h
 *
 *  Created on: Jul 15, 2016
 *      Author: asma
 */

#ifndef GRID_H_
#define GRID_H_


#include "Cell.h"

#define GRID_HEIGHT 22
#define GRID_WIDTH 10

struct Cell*** new_grid();
//struct Cell*** open_save_grid(const char file_path);
void free_grid(struct Cell ***grid);
struct Cell *get_grid_cell(struct Cell ***grid, int x, int y);
void print_grid(struct Cell*** grid);


#endif /* GRID_H_ */



