/*
 * Game.c
 *
 *  Created on: Jul 29, 2016
 *      Author: asma
 */

#include"Game.h"


void pause_game(struct Game *game){
	game->paused = true;

};

void stop_game(struct Game *game){
	game->game_over = true;
	printf("GAME OVER \n");
};

void resume_game(struct Game *game){
	game->paused = false;

}

struct Game new_game(){
	struct Game game;

	game.score = init_score_board();
	printf("init_score_board works\n");
	game.high_score = init_high_score();
	printf("init_high_score works\n");
	game.grid = new_grid();
	printf("new_grid works\n");
	game.game_over = false;
	game.paused = false;
	game.window_open = true;
	game.current_block = init_block(6,6,5, 2);
	printf("game x: %d game y: %d",game.current_block.x_piv, game.current_block.y_piv);
	return game;
};

/*
static void sleep(int nr_of_seconds, int nr_of_milliseconds) {
	struct timespec *sleep_time = malloc(sizeof(struct timespec));
	sleep_time->tv_sec = nr_of_seconds;
	sleep_time->tv_nsec = nr_of_milliseconds * 1000 * 1000;
	struct timespec *remainder_sleep_time = malloc(sizeof(struct timespec));
	nanosleep(sleep_time, remainder_sleep_time);
}

*/

/*
struct Game load_game(const char file_path){

};

struct game init_game(){

};

void save_game(struct Game game){

};

*/

void game_over(struct Game *game, enum Direction d){
	struct Block current = game->current_block;
	struct Cell ***grid = game->grid;

	if(collision(&current,grid,d) == 1 && current.y_piv == 2){ //2 moet veranderd worden naar start_y
		game->game_over = true;
	}
};

struct Block get_current_block(struct Game *game){
	struct Block current = game->current_block;
	return current;
};

void set_current_block(struct Game *game, struct Hold *hold){
	game->current_block = hold->hold_block; // get_hold(*hold) Return block from hold, generate new block and put in hold
};

int test_full_line(struct Game *game){
	printf("start test \n");
	struct Cell ***grid = game->grid;
	struct Block block = game->current_block;
	//int **matrix[MATRIX_WIDTH][MATRIX_HEIGHT] = block.rotation_matrix;

	int piv_x = block.x_piv; //get_block_x_piv(block);
	int piv_y = block.y_piv;//get_block_y_piv(block);
	printf("piv_x: %d piv_y: %d\n", piv_x, piv_y); // das de eerste en die van loc staat er onder net waar ze worden gemaakt
	//int piv_x = game->current_block.x_piv;
	//	int piv_y = game->current_block.y_piv;


	int *piv_coord = locate_piv_matrix(&block);
		//int *piv_coord = locate_piv_matrix(game->current_block);
	int piv_coord_x = piv_coord[0];
	int piv_coord_y = piv_coord[1];


	int i;
	int j;
	for(i = 0; i < MATRIX_HEIGHT; i++){ // i is height
			for(j = 0; j < MATRIX_WIDTH; j++){ // j is width
				if(game->current_block.rotation_matrix[j][i] != 0){

				int diff_y = piv_coord_y - i ;
				int diff_x = piv_coord_x - j;
				printf("diff_y: %d  diff_x %d \n", diff_y, diff_x);
				int grid_loc_y = piv_y - diff_y;
				int grid_loc_x = piv_x - diff_x;
				printf("grid_loc_y: %d  grid_loc_x: %d \n", grid_loc_y, grid_loc_x);
				int current_row = grid_loc_y;
				int current_x = 0;
				printf("current_row: %d current_x: %d \n", current_row, current_x);
				struct Cell *current_cell = get_grid_cell(grid,current_x,current_row);
			//	struct Cell *current_cell = get_grid_cell(game->grid,current_x,current_row);
				enum State current_state = get_state_cell(current_cell);

				while(current_x < GRID_WIDTH){
					if(current_state == empty){
						current_x = 0;
						printf("no line to clear current_x:%d, current_row:%d \n",current_x, current_row);
						break;
						/*
						 * kom je een lege cell tegen dan stop je de while
						 */
					}
					else if(current_x == (GRID_WIDTH - 1)){  // grid_width - 1 is de laatste locatie op de breette van de gird
						int full_line = current_row;
						current_x = 0;
						printf("line to clear current_x:%d, current_row:%d \n",current_x, current_row);
						return current_row;

					}
					else if(i == MATRIX_HEIGHT){
						return 0;
						printf("at the end current_x:%d, current_row:%d \n",current_x, current_row);
					}
					else{
						current_x++;
						printf("still searching current_x:%d, current_row:%d \n",current_x, current_row);
					}

					}
				}
			}
	}
	return 0;
};



				/*
				 * enkel de hoogtte nodig om te weten welke rij je moet verwijderen
				 */
				/*
				 * dus het idee
				 * zoek de pivot bepaal de afstand bla bla zoals gewoon lijk
				 * nu check je of de plaats in de rotatie matrix = 0
				 * zo ja, moet je die regel niet checken
				 * zo nee, loop de lijn af tot je ofwel
				 * 1. een lege cel tegen komt
				 * 2. op het einde zit van de grid
				 * kom je een lege cel tegen? -> ga naar boven begin opniew
				 * zit je op het einde van de grid -> roep clear line op en verwijder ze
				 * verwijder lijn is: laat bovenliggende blokken 1 zakken
				 * check dezelfde lijn opnieuw
					counter bijhouden voor elke clear line, dan door middel van die counter direct alles die hoeveelheid laten zakken
				 */




void game_func(struct Game* game){ ;


	change_state_cell(game->grid,&game->current_block,empty);

	int moved = move_block(&game->current_block, game->grid, down);
	test_full_line(game);

	clear_grid();
	change_state_cell(game->grid,&game->current_block,filled);
	print_grid(game->grid);
	draw_grid(game->grid);

	//game->window_open = moved; // stop de loop als het blok niet beweegd (output lezen)



		/*
		 * if (current_bottom)
		 *
		 * 	if (clear line)
		 * 		clear line, inc score
		 *
		 * 	dan laad je een nieuwe current in
		 * 	update de hold (nieuwe hold inladen)
		 * 	veld en hold opnieuw tekenen
		 *
		 *	else
		 *		nieuwe current laden
		 *		hold updaten
		 *		veld en hold opnieuw tekenen
		 */

		//get_input();              -- input van gebruiker ontvangen, wordt geprocessed in input adt
		//block = get_current_block(&game); -- blok uit de hold halen en ze bovenaan zetten
		//move_block(bock, down)    -- block naar benenden doen bewegen, block uit block adt, wordt geinitieerd en de rotatie bijgehouden in
										//rotation matrix
		//display field				-- nieuwe toestand uittekenen, speelveld wordt geiniteerd bij het initeren van het spel
		//display_score();          -- nieuwe score tonen, score board wordt geinitieerd bij het maken van het spel
		//sleep();					-- zorgen dat het blokje niet te snel valt, loop te snel wordt uitgevoerd
	// ----------------------------------------------------------------------------------------------------------------------
		/*
		 * if(game.game_over == true)  game over waneer de blokjes de bovenkant van het scherm raken
		 * game over displayen
		 * speler keuze geven, om opnieuw te starten
		 * huidige score en highscore displayen
		 * testen of huidige scoren bij de highscores kan
		 * else
		 * is het spel gepauseerd
		 * speler keuze geven, verder doen, opnieuw starten, spel opslaan
		 * if verder doen
		 *    uit pause toestand gaan
		 *
		 * else if opnieuw opstarten
		 * 		check huidige score in highscores
		 *    	nieuw spel opstarten
		 *
		 * else if stoppen zonder opslaan
		 * 		check huidige score in highscores
		 * 		naar start menu gaan
		 *
		 * else (stoppen met op te slaan)
		 * 		checken of score in highscore
		 * 		spel (struct, toestand) in file schrijven
		 * 		save_game(game)
		 *
		 */

	//sleep(0,500);
};

