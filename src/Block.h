/*
 * Block.h
 *
 *  Created on: Jul 14, 2016
 *      Author: asma
 */

#ifndef BLOCK_H_
#define BLOCK_H_


#include "Block_data.h"
#include "Cell.h"
#include "Grid.h"
#define START_X 10
#define START_Y 10


enum Shape{
	O,
	I,
	S,
	Z,
	L,
	J,
	T,
	V,
	W,
	P

};

enum Direction{
	left,
	right,
	down,
	rotate
};

struct Block{
	struct Cell cell;  // Block is afhankelijk van Cell, cell maakt deel uit van een block
	int x_piv;
	int y_piv;
	enum Colour colour;
	enum Shape shape;
	int rotation_matrix[5][5];
};


int get_block_x_piv(struct Block x);
int get_block_y_piv(struct Block x);
enum Shape get_block_shape(struct Block x);
enum Colour get_block_colour(struct Block x); //je kent de kleur van de cell
int **get_block_matrix(struct Block *x);
void set_block_x_piv(struct Block *x, int c);
void set_block_y_piv(struct Block *x, int c);
void set_block_matrix(struct Block *x);
struct Block init_block(enum Colour c, enum Shape s, int x, int y);
void move_block (struct Block *x, enum Direction dir);
int divide(int i);
void rotate_block(struct Block *x);
void set_correct_vals(struct Block *x);
int test_boundaries(struct Block *x, struct Cell ***grid,enum Direction dir);

void print_block(struct Block *x);


#endif /* BLOCK_H_ */
