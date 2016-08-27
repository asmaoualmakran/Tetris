/*
 * Input.c
 *
 *  Created on: Jul 24, 2016
 *      Author: asma
 */

#include"Input.h"


read_input(SDL_Event *event, struct Game *game){
	SDL_PollEvent(event);
	SDLKey key_pressed = event->key.keysym.sym;
	switch(event->type){
	case SDL_KEYDOWN:
		switch(key_pressed){
		case SDLK_UP:
			change_state_cell(game->grid,&game->current_block,empty);
			rotate_block(&game->current_block);
			change_state_cell(game->grid,&game->current_block,filled);
			printf("key up is pressed \n");
			break;

		case SDLK_LEFT:
			change_state_cell(game->grid,&game->current_block,empty);
			move_block(&game->current_block, game->grid, left);
			change_state_cell(game->grid,&game->current_block,filled);
			printf("key left is pressed \n");
			break;

		case SDLK_RIGHT:
			change_state_cell(game->grid,&game->current_block,empty);
			move_block(&game->current_block, game->grid, right);
			change_state_cell(game->grid,&game->current_block,filled);
			printf("key right is pressed \n");
			break;

		case SDLK_DOWN:
			change_state_cell(game->grid,&game->current_block,empty);
			move_block(&game->current_block, game->grid, down);
			change_state_cell(game->grid,&game->current_block,filled);
			printf("key down is pressed \n");
			break;

		case SDLK_p:
			game->paused = !(game->paused);
			printf("key p is pressed \n");
			break;

		case SDLK_q:
			close_window();
			printf("key q is pressed \n");
			break;
		default:
			printf("none of the defined keys was pressed \n");
		}

		break;
		default:
			printf("no user input \n");
	}


};
