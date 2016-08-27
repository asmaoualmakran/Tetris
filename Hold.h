/*
 * Hold.h
 *
 *  Created on: Aug 1, 2016
 *      Author: asma
 */

#ifndef HOLD_H_
#define HOLD_H_


#include "Block.h"

struct Hold{
	struct Block hold_block;
	int hold_matrix[MATRIX_WIDTH][MATRIX_HEIGHT];
};


struct Hold init_hold();
void set_hold_matrix(struct Hold *hold, int x);
void load_new_block(struct Hold *hold);
void print_hold(struct Hold *x);
struct Block *load_from_hold(struct Hold *hold, struct Block *block);
#endif /* HOLD_H_ */
