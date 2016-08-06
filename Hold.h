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
	int hold_matrix[5][5];
};


struct Hold init_hold();
void set_hold_matrix(struct Hold *hold, int x);
void load_new_block(struct Hold *hold);
#endif /* HOLD_H_ */
