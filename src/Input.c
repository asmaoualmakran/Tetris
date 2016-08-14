/*
 * Input.c
 *
 *  Created on: Jul 24, 2016
 *      Author: asma
 */

#include"Input.h"


read_input(SDL_Event *event){
 // uw event is een POINTER
	SDL_PollEvent(event);
	SDLKey key_pressed = event->key.keysym.sym;
	switch(event->type){
	case SDL_KEYDOWN:
		switch(key_pressed){
		case SDLK_UP:
			printf("key up is pressed \n");
			break;

		case SDLK_LEFT:
			printf("key left is pressed \n");
			break;

		case SDLK_RIGHT:
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
