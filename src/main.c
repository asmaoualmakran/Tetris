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


