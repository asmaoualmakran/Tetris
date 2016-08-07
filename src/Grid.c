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
			*cell = init_cell(black, empty, i ,j);
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

	for (i = GRID_WIDTH; i >= 0; i--) {

		for (j = GRID_HEIGHT; j >= 0; i--) {
			free(grid[i][j]);
		}
		free(grid[i]);
	}
	free(grid);
}
;

struct Cell *get_grid_cell(struct Cell ***grid, int x, int y) {
	struct Cell *cell = grid[x][y];
	return cell;
}
;

void print_grid(struct Cell*** grid) {
	int i, j = 0;
	for (i = 0; i < GRID_WIDTH; i++) {
		for (j = 0; j < GRID_HEIGHT; j++) {
			struct Cell *cell = grid[i][j];
			print_cell(cell);
		}
		printf("\n ---- \n");
	}
}
