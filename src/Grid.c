/*
 * Field.c
 *
 *  Created on: Jul 15, 2016
 *      Author: asma
 */

#include <stdio.h>
#include <stdlib.h>
#include "Grid.h"




struct Cell ***new_grid() {

	struct Cell ***width_arr = malloc(GRID_WIDTH * (sizeof(struct Cell*)));
	int i;

	for (i = 0; i < GRID_WIDTH; i++) {
		struct Cell **height_arr = malloc(GRID_HEIGHT * (sizeof(struct Cell*)));

		int j;
		for (j = 0; j < GRID_HEIGHT; j++) {

			struct Cell *cell = malloc(sizeof(struct Cell));
			*cell = init_cell(black, empty, i, j);
			height_arr[j] = cell;
		}

		width_arr[i] = height_arr;
	}

	return width_arr;
}
;

/*

 struct Cell ***open_save_grid(const char file_path) {

 struct Cell ***grid;
 FILE *fp;
 fp = fopen(file_path, "r");

 if(fp == NULL){
 printf("save file does not exist \n");
 }else{
 struct Cell ***width_arr = malloc(GRID_WIDTH * (sizeof (struct Cell*)));
 grid = width_arr;
 int x;
 int y;

 for (x = 0; x < GRID_WIDTH; x++){
 struct Cell **hight_arr = malloc(GRID_HIGHT * (sizeof (struct Cell*)));

 for(y = 0; y < GRID_HIGHT; y++){
 struct Cell *cell = malloc(sizeof(struct Cell*));

 }


 }

 char buff[GRID_WIDTH];
 int i;
 int j;
 int b = 0; index voor de buffer


 je gaat eerst over de breette dan de hoogtte (dezelfde mannier waarop de file wordt gelezen

 for(i = 0; i < GRID_HIGHT; i++){
 for(j = 0; j < GRID_WIDTH; j++){
 while(fgets(buff, GRID_WIDTH, fp) && b < GRID_WIDTH ){
 int c = atoi(buff);
 b++;
 if(c == 0){
 struct Cell empty_cell = init_cell(c,c,j,i);
 width_arr[j][i] = &empty_cell;
 }else{
 struct Cell filled_cell = init_cell(c,filled,j,i);
 width_arr[j][i] = &filled_cell;
 }

 }
 }
 }
 }

 return grid;
 };
 */

void free_grid(struct Cell ***grid) {

	int i;
	int j;

	for (i = GRID_HEIGHT; i >= 0; i--) {

		for (j = GRID_WIDTH; j >= 0; j--) {
			free(grid[i][j]);
		}
		free(grid[i]);
	}
	free(grid);
}
;

/*
 * Author: Asma Oaulmakran
 * Function: get_grid_cell
 * Parameters:
 * 		grid
 * 				type:	 Cell***
 * 				use:	the grid where from the cell is taken
 * 				constraint: N/a
 * 		width
 * 				type: 	Integer
 * 				use:  	The width at which the cell resides in the grid.
 * 				constraint: must be a positive integer smaller then GRID_WIDTH
 * 		height:
 * 				type: 	Integer
 * 				use:	The height at whihch the cell resides in the grid
 * 				constraint: must be a positive integer smaller then GRID_Height
 * 	Returns: Cell* (pointer to a cell)
 * 	use: Returns a pointer to a cell struct locate within the given grid
 * */
struct Cell *get_grid_cell(struct Cell ***grid, int width, int height) {
	struct Cell *cell = grid[width][height]; // duidelijke naamgeving brengt u ook al ver
	return cell;
}
;


void fill_cell(struct Cell ***grid, int width, int height, enum Colour c){
	struct Cell *cell = get_grid_cell(grid,width,height);
	cell->state = filled;
	cell->colour = c;
};

int get_state_cell(struct Cell *cell){
	enum State s = cell->state;
	return s;
};

void clear_cell(struct Cell ***grid, int width, int height){
	struct Cell *cell = get_grid_cell(grid,width,height);
	cell->state = empty;
	cell->colour = black;
};



void print_grid(struct Cell*** grid) {
	int width, height = 0;
	for (height = 0; height < GRID_HEIGHT; height++) {
		printf("%d|\t", height);
		for (width = 0; width < GRID_WIDTH; width++) {
			struct Cell *cell = get_grid_cell(grid, width, height);
			//print_cell(cell);
			printf("%d|",cell->state);
		}
		printf("\n ---- \n");
	}
}
;

void clear_line(struct Cell*** grid, int i) {
	int j;

	for (j = 0; j < GRID_WIDTH; j++) {
		struct Cell* cell = get_grid_cell(grid, i, j);
		cell->state = empty;
		cell->colour = black;
	}
}


void move_line(struct Cell*** grid) {

}
;



void change_state_cell(struct Cell ***grid, struct Block *x,enum State s){

	//int **matrix = x->rotation_matrix;
	int *piv_coord = locate_piv_matrix(x);
	int piv_coord_x = piv_coord[0];
	int piv_coord_y = piv_coord[1];

	int piv_x = x->x_piv;
	int piv_y = x->y_piv;
	int i;
	int j;
	for(i = 0; i < MATRIX_HEIGHT; i++){ // i is height
		for(j = 0; j < MATRIX_WIDTH; j++){ // j is width
			if(x->rotation_matrix[j][i] != 0){

			int diff_y = piv_coord_y - i ;
			int diff_x = piv_coord_x - j;

			int grid_loc_y = piv_y - diff_y; // height
			int grid_loc_x = piv_x - diff_x; // width
			printf("grid_coord: %d, %d\n",grid_loc_x, grid_loc_y);
			if(s == filled){
				//fill_cell(grid,grid_loc_x,grid_loc_y,x->colour);
				struct Cell *cell = get_grid_cell(grid,grid_loc_x,grid_loc_y);
				cell->state = filled;
				cell->colour = x->colour;
			}
			else{
				//clear_cell(grid,grid_loc_x,grid_loc_y);
				struct Cell *cell = get_grid_cell(grid,grid_loc_x,grid_loc_y);
				cell->state = empty;
			}

			//struct Cell *cell = get_grid_cell(grid,grid_loc_x,grid_loc_y);
			//cell->state = filled;
			//struct Cell *cell = grid[grid_loc_i][grid_loc_j];
			//cell->state = filled;
			//cell->colour = x->colour;
			//print_cell(cell);

			}
		}
	}
};

