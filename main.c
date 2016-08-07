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
	printf("----------------1\n");
	struct Hold hold = init_hold();
	print_hold(&hold);
	printf("------------------2\n");
	load_from_hold(&hold, &block);
	print_block(&block);
	printf("%d, %d\n", hold.hold_block.shape, hold.hold_block.colour);
	printf("---------------------3\n");
	print_hold(&hold);
	//init_gui();
	//gameloop();
	initialize_gui();

	puts("!!!Hello World!!!"); // prints !!!Hello World!!!


	return EXIT_SUCCESS;
};







