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
	struct Block block = init_block(5,5,5,5);
/*	print_block(&block);
	printf("----------------1\n");
	/*struct Hold hold = init_hold();
	print_hold(&hold);
	printf("------------------2\n");
	load_from_hold(&hold, &block);
	print_block(&block);
	printf("%d, %d\n", hold.hold_block.shape, hold.hold_block.colour);
	printf("---------------------3\n");
	print_hold(&hold);
	//init_gui();
	//gameloop();*/
/*	rotate_block(&block);
	print_block(&block);
	printf("--------------------------2\n");
	rotate_block(&block);
	print_block(&block);
	printf("--------------------------3\n");
	rotate_block(&block);
	print_block(&block);
//	puts("!!!Hello World!!!"); // prints !!!Hello World!!!
//	get_block_matrix(&block);
*/
	//int *piv = locate_piv_matrix(&block);
	//printf("piv: %d, %d \n", piv[0], piv[1]);
	//printf("x");
	//set_direction(left);

	//set_direction(right);
	//set_direction(down);
	// klopt dat?
	//
//	printf("%d", collision(&block, grid, left));
	/*
	 * reageert compleet niet
	 */
	struct Game game = new_game();
	init_window();
	run_window(&game);
	  // close_window();
	//read_input();
	printf("done");

	//close_window(&game);
	return 0;
};
/*
 * TODO: zorgen dat het venster openblijft van gui IN PROGRESS
 * TODO: gameloop al maken wat er kan
 * TODO: bewegingen van de blokjes IN PROGRESS
 * TODO: key input lezen
 * TODO: tekst schrijven
 * TODO: algemene gui
 * TODO: opslaan van een spel
 * TODO: pauzeren van een spel
 * TODO: clearline -> in Grid.c IN PROGRESS
 * TODO: rotatie DONE
 * TODO: start locaties van de blokjes bepalen -> bepaal de hoogtte van de pivot, dat is dan ook de hoogtte van de blokje breette -> 1/2 breette speelveld
 * TODO: Collision test IN PROGRESS
 * TODO: key poll in de main game loop
 */
// nee nee, wou hier bij iets openen het klopt niet die reslutaten piv en loc wel maar de grid check niet die moet 2,1 checken das links nu kijkt die rechts beneden


