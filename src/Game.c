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
	game->window_open = false;
	printf("GAME OVER \n");
};

void resume_game(struct Game *game){
	game->paused = false;

}

struct Game new_game(){
	struct Game game;

	game.score = init_score_board();
	game.high_score = init_high_score();
	game.game_over = false;
	game.paused = false;
	game.window_open = true;
	game.hold = init_hold();
	game.current_block = init_block();
	game.grid = new_grid();
	return game;
};



/*
struct Game load_game(const char file_path){

};


void save_game(struct Game game){

};

*/

void game_over(struct Game *game){
	struct Block current = game->current_block;
	struct Cell ***grid = game->grid;

	int i;
	for(i = 0; i < GRID_WIDTH; i++){
		if(grid[i][1]->state == filled && collision(&current, grid,down)){
			free_grid(grid);
			stop_game(game);
		}
	}
};

struct Block get_current_block(struct Game *game){
	struct Block current = game->current_block;
	return current;
};

void set_current_block(struct Game *game){
	load_from_hold(&game->hold,&game->current_block);
	int i = pick_random_block();
	set_hold_matrix(&game->hold,i);
	print_hold(&game->hold);
};


int set_hold_current_block(struct Game *game){
	if(collision(&game->current_block,game->grid,down) == 1){
		set_current_block(game);
		printf("current \n");
		print_block(&game->current_block);
		printf("colision detect \n");
		return 1;
	}
	return 0;
};



int test_full_line(struct Game *game){

	struct Cell ***grid = game->grid;
	struct Block block = game->current_block;

	int piv_x = block.x_piv;
	int piv_y = block.y_piv;


	int *piv_coord = locate_piv_matrix(&block);
	int piv_coord_x = piv_coord[0];
	int piv_coord_y = piv_coord[1];


	int i;
	int j;
	for(i = 0; i < MATRIX_HEIGHT; i++){
			for(j = 0; j < MATRIX_WIDTH; j++){
				if(game->current_block.rotation_matrix[j][i] != 0){

				int diff_y = piv_coord_y - i ;
				int diff_x = piv_coord_x - j;
				int grid_loc_y = piv_y - diff_y;
				int grid_loc_x = piv_x - diff_x;
				int current_row = grid_loc_y;
				int current_x = 0;
				struct Cell *current_cell = get_grid_cell(grid,current_x,current_row);
				enum State current_state = get_state_cell(current_cell);

				while(current_x < GRID_WIDTH){
					if(current_state == empty){
						current_x = 0;
						break;
						/*
						 * kom je een lege cell tegen dan stop je de while
						 */
					}
					else if(current_x == (GRID_WIDTH - 1)){  // grid_width - 1 is de laatste locatie op de breette van de gird
						int full_line = current_row;
						current_x = 0;
						return current_row;

					}
					else if(i == MATRIX_HEIGHT){
						return 0;
					}
					else{
						current_x++;
					}

					}
				}
			}
	}
	return 0;
};






void game_func(struct Game* game){ ;

	clear_grid();
//	game_over(game);  deze functie werkt niet correct
	change_state_cell(game->grid,&game->current_block,empty);

	int moved = move_block(&game->current_block, game->grid, down);

	if (moved == 0){
		change_state_cell(game->grid,&game->current_block,filled);
		test_full_line(game);
		set_hold_current_block(game);
	}
	change_state_cell(game->grid,&game->current_block,filled);

	test_full_line(game);
	print_grid(game->grid);
	draw_grid(game);

};

