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
	for(i = 0; i < MATRIX_HEIGHT; i++){
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
	for(i = 0; i < MATRIX_HEIGHT; i++){
		for(j = 0; j < MATRIX_WIDTH; j++){
			int c = x->rotation_matrix[i][j];
			printf("%d", c);
		}
		printf("\n");
	}
};


/*
int test_boundaries(struct Block *x, struct Cell ***grid,enum Direction dir){


};
*/

void move_block (struct Block *x, enum Direction dir){

	if(dir == left || test_boundaries(x)){
		x->x_piv = x->x_piv - 1;
	}
	else if(dir == right || test_boundaries(x)){
		x->x_piv = x->x_piv + 1;
	}
	else if(dir == down || test_boundaries(x)){
		x->y_piv = x->y_piv + 1;

	}
	else if(dir == rotate || test_boundaries(x)){
		rotate_block(x);
	}
};



void rotate_block(struct Block *x) {

	if(x->shape != O ){             /* O heeft geen rotatie */

		int N = MATRIX_WIDTH - 1;
		int i;
		int j;

		for(i = 0; i < MATRIX_HEIGHT; i++){
		  for (j = 0; j < MATRIX_WIDTH; j++) {

			  int current;
			  current = x->rotation_matrix[i][j];
			  if (current == 1 || current == -3 || current == -4){
				  current = 1;
			  }
			  else if (current == 0 || current == -1 || current == -2){
				  current = 0;
			  }
			  else if(current == 2 || current == -5 || current == -6){
				  current = 2;
			  }
			  if(current == 0 && x->rotation_matrix[N-j][i] == 0){
				  x->rotation_matrix[N-j][i] = 0;
				  /*veld was 0 en blijft 0*/
			  }
			  else if(current == 1 && x->rotation_matrix[N-j][i] == 0){
				  x->rotation_matrix[N-j][i] = -1;
				  /*veld was 0 en wordt 1*/
			  }
			  else if(current == 2 && x->rotation_matrix[N-j][i] == 0){
				  x->rotation_matrix[N-j][i] = -2;
				  /*veld was 0 en wordt 2*/
				  printf("(Pivot)");
			  }
			  else if(current == 1 && x->rotation_matrix[N-j][i] == 1){
				  x->rotation_matrix[N-j][i] = -3;
				  /*veld was 1 en blijft 1*/
			  }
			  else if(current == 2 && x->rotation_matrix[N-j][i] == 1){
				  x->rotation_matrix[N-j][i] = -4;
				 /*veld was 1 en wordt 2*/
			  }
			  else if(current == 2 && x->rotation_matrix[N-j][i] == 1){
				  x->rotation_matrix[N-j][i] = -5;
				  /*veld was 2 en wordt 1*/
			  }
			  else if(current == 2 && x->rotation_matrix[N-j][i] == 2){
				  x->rotation_matrix[N-j][i] = -6;
			  	  /*veld was 2 en blijft 2*/
			  			  }

		  }
		}
		set_correct_vals(x);
	}

};

void set_correct_vals(struct Block *x){
	int N = MATRIX_WIDTH;
	int M = MATRIX_HEIGHT;
	int i;
	int j;
	for(i = 0; i < M; i++){
			  for (j = 0; j < N; j++) {
				  if(x->rotation_matrix[i][j] == -1 || x->rotation_matrix[i][j] == -3 || x->rotation_matrix[i][j] == -5){
					  x->rotation_matrix[i][j] = 1;
					  /* bij lezen van -1, -3, -5 schrijf een 1*/
				  }
				  else if(x->rotation_matrix[i][j] == -2 || x->rotation_matrix[i][j] == -4 || x->rotation_matrix[i][j] == -6){
					  x->rotation_matrix[i][j] = 2;
					  /* bij lezen van -2, -4 schrijf een 2*/
				  }
				  else{
					  x->rotation_matrix[i][j] = 0;
					  /* anders schrijg je een 0*/
				  }
			  }
	}
};
