/*
 ============================================================================
 Name        : tetris.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "main.h"



int main(void) {


	struct Cell ***grid = new_grid();
	//print_grid(grid);
	struct Cell *c = get_grid_cell(grid, 0, 10);
	//print_cell(c);
	struct Block block = init_block(1,0,1,1);
	print_block(&block);

	//gameloop();

	puts("!!!Hello World!!!"); // prints !!!Hello World!!!
/*	int i, j, k;
	for(i = 0; i < 10; i++){
		for(j = 0; j < 5; j++){
			for(k = 0; k < 5; k++){
				printf("%d", blocks[i][j][k]);
			}
			printf("\n");
		}
		printf("\n-----\n");
	}

	printf("Z\n");

	int z = blocks[4];
	for(j = 0; j < 5; j++){
				for(k = 0; k < 5; k++){
					printf("%d", z[j][k]);
				}
				printf("\n");
			}*/

	return EXIT_SUCCESS;
};





