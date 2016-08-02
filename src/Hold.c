/*
 * Hold.c
 *
 *  Created on: Aug 1, 2016
 *      Author: asma
 */

#include"Hold.h"

/*------------------------------------------------------*/
/*-----------------Hold code ---------------------------*/
/*------------------------------------------------------*/
/*
struct Hold init_hold(int i, int ***arr){
	struct Hold hold;
	hold.hold_block = init_block(i, i, 0, 0);
	int matrix = hold.matrix;
	copy_block(i, arr, matrix);
   return hold;
};
*/
/*
void load_new_block(struct Hold *hold, int ***arr, int **matrix){
	int block_nr = rand()% 10;
	hold->hold_block = init_block(block_nr, block_nr, 0, 0);

	//hold->matrix = copy_block(block_nr, arr, matrix);

};

void copy_block(struct Hold *hold,int i, int ***arr){
	int j;
	int c;
	int matrix = hold->matrix;
	for(j = 0; j < BLOCK_Y; j++){
		for(c = 0; c < BLOCK_X; c++){
			matrix[j][c] = arr[i][j][c];
		}
	}

};

//int **get_hold(struct Hold *hold);    // get_hold(*hold) Return block from hold, generate new block and put in hold

*/
