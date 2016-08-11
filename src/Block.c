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

int get_block_matrix(struct Block *x){
	int matrix= x->rotation_matrix;
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
	block.rotation_matrix[0][0]=1;
	set_block_matrix(&block);

	return block;
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

/*
 * de locatie van de pivot bepale in de rotatie matrix
 */
int * locate_piv_matrix(struct Block *x){
	static int coordinate[2];
	int i;
	int j;
	for(i = 0; i < MATRIX_HEIGHT; i++){
		for(j = 0; j < MATRIX_WIDTH; j++){
			if(x->rotation_matrix[i][j] == 2){
				coordinate[0] = i;
		//		printf("val_i: %d \n", i);
				coordinate[1] = j;
			}
		}
	}
	return coordinate;
};

int* set_direction(enum Direction d){

	static int *dir[2];
	/*
	 * deze getallen gebruiken om de nieuwe locatie te bepalen
	 */
	if(d == left){
		dir[0] = 0;
		dir[1]= -1;
	}
	else if(d == right){
		dir[0] = 0;
		dir[1] = 1;
	}
	else if (d == down){
		dir[0] = 1;
		dir[1] = 0;
	}
	else{
		dir[0] = 0;
		dir[1] = 0;
	}
//	printf("dir: %d, %d\n", dir[0], dir[1]);
	return *dir;
};

int collision(struct Block *x, struct Cell ***grid, enum Direction d){

	printf("start_function");
	int* direction = set_direction(d);
	int dir_i = direction[0];
	int dir_j = direction[1];
	printf("dir: %d, %d \n", dir_i, dir_j);

	int piv_i = get_block_y_piv(*x);
	int piv_j = get_block_x_piv(*x);
	printf("piv: %d, %d \n", piv_i, piv_j);

	int matrix = x->rotation_matrix;
	int* loc_piv = locate_piv_matrix(x);
	int loc_i = loc_piv[0];
	int loc_j = loc_piv[1];
	printf("loc: %d, %d \n", loc_i, loc_j);

	int ci;
	int cj;

	for(ci = 0; ci < MATRIX_HEIGHT; ci++){
		for(cj = 0; cj < MATRIX_WIDTH; cj++){
			/*
			 * diff_i en diff_j worden gebruikt om de afstand tussen de pivot het element te berekenen
			 */
			int diff_i = loc_i - ci;
			int diff_j = loc_j - cj;

			/*
			 * de locatie van een element uit de matrix bepalen in de grid, relatief tot de pivot
			 */
     		int grid_loc_i = piv_i - diff_i;
			int grid_loc_j = piv_j - diff_i;
			/*
			 * testen of de locatie binnen de grid ligt
			 */
			if(grid_loc_i < GRID_HEIGHT && grid_loc_i >= 0 && grid_loc_j < GRID_WIDTH && grid_loc_j >= 0){
				/*
				 * de nieuwe locatie berekenen
				 */
				printf("grid_check: %d, %d \n",grid_loc_i,grid_loc_j);
				int new_i = grid_loc_i + dir_i;
				int new_j = grid_loc_j + dir_j;
				/*
				 * testen of de nieuwe locatie binnen de grid ligt
				 */
				if(new_i < GRID_HEIGHT && new_i >= 0 && new_j < GRID_WIDTH && new_j >= 0){
					/*
					 * testen wat er in de matrix zit op de locatie en wat er in de grid
					 * zit op dezelfde locatie
					 */
					int cell_state = grid[new_i][new_j]->state ;
					if(cell_state != empty && x->rotation_matrix[ci][cj] != 0){

						return 1;
					}

				}
				/*
				 * new_i, new_j vallen buiten de grenzen van de grid
				 */
				return 1;

			}
			/*
			 * grid_loc_i en grid_loc_j vallen buiten de grid
			 */
			return 1;
		}

	}
	/*
	 * testen slagen geen colision
	 */
  return 0;
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



