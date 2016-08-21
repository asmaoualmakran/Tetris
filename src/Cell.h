/*
 * Bloks.h
 *
 *  Created on: Jul 9, 2016
 *      Author: asma
 */

#ifndef BLOKS_H_
#define BLOKS_H_

#define CELL_WIDTH 20
#define CELL_HEIGHT 20

enum State{
	empty,
	filled,
	pivot
};

enum Colour{
	red, 		// 0
	l_blue, 	// 1
	yellow,		// 2
	green, 		// 3
	orange,		// 4
	pink, 		// 5
	purple,		// 6
	d_green,	// 7
	d_red,		// 8
	d_blue,     // 9
	black		//10
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

#endif /* BLOKS_H_ */
