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


	struct Game game = new_game();
	init_window();
	run_window(&game);
	return 0;
};

