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
	int matrix[5][5];
};


struct Hold init_hold(int i, int ***arr, int **matrix);
void load_new_block(struct Hold *hold, int ***arr);
void copy_block(struct Hold *hold,int i, int ***arr);
int **get_hold(struct Hold *hold);


#endif /* HOLD_H_ */
