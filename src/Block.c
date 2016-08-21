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
	enum Colour s = x.colour;
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

void determine_start_pos(struct Block *x){
	int* loc_piv = locate_piv_matrix(x);
	x->x_piv = (GRID_WIDTH/2)-1;
	x->y_piv = loc_piv[1];
};

struct Block init_block(){
	struct Block block;
	int i = pick_random_block();
	block.colour = i;
	block.shape = i;
	block.cell.colour = i;
//	block.x_piv = x;
//	block.y_piv = y;
	block.rotation_matrix[0][0]=1;
	set_block_matrix(&block);
	determine_start_pos(&block);

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
 * de locatie van de pivot bepalen in de rotatie matrix
 */
int* locate_piv_matrix(struct Block *x){
	static int coordinate[2];
	int width;
	int height;
	for(height = 0; height < MATRIX_HEIGHT; height++){
		for(width = 0; width < MATRIX_WIDTH; width++){
			if(x->rotation_matrix[width][height] == 2){
				coordinate[0] = width;
				coordinate[1] = height;
			}
		}
	}
	return coordinate;
};

int* set_direction(enum Direction d){

	static int dir[2];
	/*
	 * deze getallen gebruiken om de nieuwe locatie te bepalen
	 */
	if(d == left){
		dir[0] = -1;
		dir[1] = 0;
	}
	else if(d == right){
		dir[0] = 1;
		dir[1] = 0;
	}
	else if (d == down){
		dir[0] = 0;
		dir[1] = 1;
	}
	else{
		dir[0] = 0;
		dir[1] = 0;
	}
	return &dir;
};

int collision(struct Block *x, struct Cell ***grid, enum Direction d){



	int* direction = set_direction(d);
	int dir_x = direction[0];
	int dir_y = direction[1];

	int piv_x = get_block_x_piv(*x);
	int piv_y = get_block_y_piv(*x);

	int* loc_piv = locate_piv_matrix(x);
	int loc_x = loc_piv[0];
	int loc_y = loc_piv[1];

	int ci;
	int cj;

	for(ci = 0; ci < MATRIX_HEIGHT; ci++){
		for(cj = 0; cj < MATRIX_WIDTH; cj++){
			if(x->rotation_matrix[cj][ci] != 0){

			/*
			 * diff_i en diff_j worden gebruikt om de afstand tussen de pivot het element te berekenen
			 * loc_i en loc_j coordinaten van pivot in rotatie matrix
			 * ci en cj ander element in de rotatie matrix
			 * diff_i en diff_j afstand tussen element en pivot in rotatie matrix
			 */
			int diff_x = loc_x - cj;
			int diff_y = loc_y - ci;

			/*
			 * de locatie van een element uit de matrix bepalen in de grid, relatief tot de pivot
			 */

     		int grid_loc_x = piv_x - diff_x;
			int grid_loc_y = piv_y - diff_y;

			if(grid_loc_y < GRID_HEIGHT && grid_loc_y >= 0 && grid_loc_x < GRID_WIDTH && grid_loc_x >= 0){
				/*
				 * de nieuwe locatie berekenen
				 */

				int new_x = grid_loc_x + dir_x;
				int new_y = grid_loc_y + dir_y;

				/*
				 * testen of de nieuwe locatie binnen de grid ligt
				 */

				if(new_y < GRID_HEIGHT && new_y >= 0 && new_x < GRID_WIDTH && new_x >= 0){
					/*
					 * testen wat er in de matrix zit op de locatie en wat er in de grid
					 * zit op dezelfde locatie
					 */
					printf("get cell:\t(%d, %d)\n", new_x, new_y);
					struct Cell* cell = get_grid_cell(grid, new_x, new_y);
					printf("cell state\n");
					int cell_state = cell->state;
					printf("done\n");
					if(cell_state != empty && x->rotation_matrix[cj][ci] != 0){
						return 1;
					}

				}

				/*
				 * new_i, new_j vallen buiten de grenzen van de grid
				 */
				else {
				return 1;}

			}
			/*
			 * grid_loc_i en grid_loc_j vallen buiten de grid
			 */
			else {
				return 1;
			}
			}
		}

	}

  return 0;
};

int move_block(struct Block *x, struct Cell ***grid, enum Direction d){
		if(collision(x,grid,d) != 1){
		int* dir = set_direction(d);
		int dir_x = dir[0];
		int dir_y = dir[1];
		int x_piv = x->x_piv;
		int y_piv = x->y_piv;

		x->x_piv = x_piv + dir_x;
		x->y_piv = y_piv + dir_y;

		return 1;
		}

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



