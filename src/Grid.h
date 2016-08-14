/*
 * Field.h
 *
 *  Created on: Jul 15, 2016
 *      Author: asma
 */

#ifndef GRID_H_
#define GRID_H_


#include "Cell.h"
#include "Block.h"


#define GRID_HEIGHT 22
#define GRID_WIDTH 10


struct Cell*** new_grid();
//struct Cell*** open_save_grid(const char file_path);
void free_grid(struct Cell ***grid);
struct Cell *get_grid_cell(struct Cell ***grid, int i, int j);
void print_grid(struct Cell*** grid);
void clear_line(struct Cell*** grid, int i);
void move_line (struct Cell*** grid);
void test_full_line(struct Cell*** grid);
void put_block(struct Cell ***grid, struct Block *x);

#endif /* GRID_H_ */



