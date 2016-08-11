/*
 * Hold.c
 *
 *  Created on: Aug 1, 2016
 *      Author: asma
 */

#include"Hold.h"


struct Hold init_hold(){
	struct Hold hold;
	int i = rand()% NUMB_SHAPES;
	printf("rand %d \n", i);
	init_block(i, i, START_X, START_Y);
	printf("%d\n", i);
	set_hold_matrix(&hold, i);
	return hold;
};

void set_hold_matrix(struct Hold *hold,int x){
	int i;
		int j;
		for(i = 0; i < MATRIX_HEIGHT; i++){
			for(j = 0; j < MATRIX_WIDTH; j++){
				hold->hold_matrix[i][j] = blocks[x][i][j];
				hold->hold_block.rotation_matrix[i][j] = blocks[x][i][j];
				/* zowel de hold matrix als de matrix van de block initialiseren
				 * via de hold aan de block geraken.
				 */
			}
		}
};


struct Block *load_from_hold(struct Hold *hold, struct Block *block){
	block->colour = hold->hold_block.colour;
	block->shape = hold->hold_block.shape;
	block->x_piv = START_X;
	block->y_piv = START_Y;
	int i;
			int j;
			for(i = 0; i < MATRIX_HEIGHT; i++){
				for(j = 0; j < MATRIX_WIDTH; j++){
					block->rotation_matrix[i][j] = hold->hold_block.rotation_matrix[i][j];
				}
			}

	return block;
};

void print_hold(struct Hold *x){
	int i;
	int j;
	for(i = 0; i < MATRIX_HEIGHT; i++){
		for(j = 0; j < MATRIX_WIDTH; j++){
			int c = x->hold_matrix[i][j];
			printf("%d", c);
		}
		printf("\n");
	}
};
