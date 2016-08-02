/*
 * Block.c

 *
 *  Created on: Jul 14, 2016
 *      Author: asma
 */

#include"Block.h"

int get_block_x_piv(struct Block x){
	int s = x.x_piv;
	return s;
};

int get_block_y_piv(struct Block x){
	int s= x.y_piv;
	return s;
};

enum Shape get_block_shape(struct Block x){
	enum Shape s = x.shape;
	return s;
}

enum Colour get_block_colour(struct Block x){
	struct Cell c = x.cell;
	enum Colour s = c.colour;
	return s;
};

int **get_block_matrix(struct Block *x){
	int **matrix= x->rotation_matrix;
	return matrix;
};

void set_block_x_piv(struct Block *x, int c){
   x->x_piv = c;
};

void set_block_y_piv(struct Block *x, int c){
	x->y_piv = c;
};

void set_block_matrix(struct Block *x){
	int shape = x->shape;

	int i;
	int j;
	for(i = 0; i < MATRIX_HIGHT; i++){
		for(j = 0; j < MATRIX_WIDTH; j++){
			x->rotation_matrix[i][j] = blocks[shape][i][j];
		}
	}
};



struct Block init_block(enum Colour c, enum Shape s, int x, int y){
	struct Block block;
	block.colour = c;
	block.shape = s;
	block.x_piv = x;
	block.y_piv = y;
	block.rotation_matrix[0][0] = 1;
	set_block_matrix(&block);

	return block;
};

void print_block(struct Block *x){
	int i;
	int j;
	for(i = 0; i < MATRIX_HIGHT; i++){
		for(j = 0; j < MATRIX_WIDTH; j++){
			int c = x->rotation_matrix[i][j];
			printf("%d", c);
		}
		printf("\n");
	}
};

/*
int test_boundaries(struct Block *x){


};
*/

void move_block (struct Block *x, enum Direction dir){

	if(dir == left){
		x->x_piv = (x->x_piv - 1);

	}else if(dir == right){
		x->x_piv = (x->x_piv + 1);

	}else{
		x->y_piv = (x->y_piv - 1);
	}
};


void rotate_block(struct Block *x, int rotation_matrix){

};



