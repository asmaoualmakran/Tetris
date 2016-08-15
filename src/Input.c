/*
 * Input.c
 *
 *  Created on: Jul 24, 2016
 *      Author: asma
 */

#include"Input.h"


read_input(SDL_Event *event, struct Game *game){
 // uw event is een POINTER
	SDL_PollEvent(event);
	SDLKey key_pressed = event->key.keysym.sym;
	switch(event->type){
	case SDL_KEYDOWN:
		switch(key_pressed){
		case SDLK_UP:
			rotate_block(&game->current_block);
			printf("key up is pressed \n");
			break;

		case SDLK_LEFT:
			move_block(&game->current_block, game->grid, left);
			printf("key left is pressed \n");
			break;

		case SDLK_RIGHT:
			move_block(&game->current_block, game->grid, right);
			printf("key right is pressed \n");
			break;

		case SDLK_p:
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
