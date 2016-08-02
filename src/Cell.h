/*
 * Bloks.h
 *
 *  Created on: Jul 9, 2016
 *      Author: asma
 */

#ifndef BLOKS_H_
#define BLOKS_H_



enum State{
	empty,
	filled,
	pivot
};

enum Colour{
	black, 		// 0
	yellow, 	// 1
	l_blue, 	// 2
	red,		// 3
	green, 		// 4
	orange,		// 5
	pink, 		// 6
	purple,		// 7
	d_green,	// 8
	d_red,		// 9
	d_blue 		// 10

};

struct Cell{
	enum State state;
	enum Colour colour;
	int x_pos;
	int y_pos;
};


struct Cell init_cell(enum Colour c, enum State s, int x, int y);
enum State get_cell_state(struct Cell c);
enum Colour get_cell_colour(struct Cell c);
int get_cell_x(struct Cell c);
int get_cell_y(struct Cell c);
void set_cell_state(struct Cell *x, enum State s);
void set_cell_colour(struct Cell *x, enum Colour s);
void set_cell_x(struct Cell *pos, int x);
void set_cell_y(struct Cell *pos, int y);
void print_cell(struct Cell *cell);

#endif /* BLOKS_H_ */
