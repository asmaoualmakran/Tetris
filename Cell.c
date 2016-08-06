/*
 * Cell.c
 *
 *  Created on: Jul 14, 2016
 *      Author: asma
 */

#include"Cell.h"

enum State get_cell_state(struct Cell c){
	enum State S = c.state;
	return S;
};

enum Colour get_cell_colour(struct Cell c){
	enum Colour S = c.colour;
	return S;
};

int get_cell_x(struct Cell c){
	int S = c.x_pos;
	return S;
};

int get_cell_y(struct Cell c){
	int S = c.y_pos;
	return S;
};

void set_cell_state(struct Cell *c, enum State s){
	enum State x = c->state;
	x = s;
};

void set_cell_colour(struct Cell *c, enum Colour s){
	c->colour = s;
};

void set_cell_x(struct Cell *pos, int x){
	pos->x_pos = x;
};

void set_cell_y(struct Cell *pos, int y){
	pos->y_pos = y;
};

struct Cell init_cell(enum Colour c, enum State s, int x, int y){
	struct Cell cell;
	cell.colour = c;
	cell.state = s;
	cell.x_pos = x;
	cell.y_pos = y;
	return cell;
};

// testing purposes, write to console
void print_cell(struct Cell *cell){
	printf("State: %d\nColour: %d\nCoordinates(x; y): (%d; %d)\n\n", cell->state, cell->colour, cell->x_pos, cell->y_pos);
}
