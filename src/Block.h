/*
 * Block.h
 *
 *  Created on: Jul 14, 2016
 *      Author: asma
 */

#ifndef BLOCK_H_
#define BLOCK_H_


#include "Block_data.h"
#include "Grid.h"
#define START_X GRID_WIDTH/2
#define START_Y 10 // hoogte afhankeljk van de hoogtte van de pivot in de rotatei matrix




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
	int x_piv;
	int y_piv;
	enum Colour colour;
	enum Shape shape;
	int rotation_matrix[MATRIX_WIDTH][MATRIX_HEIGHT];
};


int get_block_x_piv(struct Block x);
int get_block_y_piv(struct Block x);
enum Shape get_block_shape(struct Block x);
enum Colour get_block_colour(struct Block x); //je kent de kleur van de cell
int get_block_matrix(struct Block *x);
int pick_random_block();
void set_block_x_piv(struct Block *x, int c);
void set_block_y_piv(struct Block *x, int c);
void set_block_matrix(struct Block *x);
void determine_start_pos(struct Block *x);
struct Block init_block(enum Shape s);
void rotate_block(struct Block *x);
void set_correct_vals(struct Block *x);
int* locate_piv_matrix(struct Block *x);
int* set_direction(enum Direction d);
int collision(struct Block *x, struct Cell ***grid, enum Direction d);
int move_block(struct Block *, struct Cell ***grid, enum Direction d);
void print_block(struct Block *x);


#endif /* BLOCK_H_ */
