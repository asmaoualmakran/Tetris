/*
 * Input.h
 *
 *  Created on: Jul 24, 2016
 *      Author: asma
 */

#ifndef INPUT_H_
#define INPUT_H_
#include "SDL/SDL.h"
#include "Game.h"


void read_input(SDL_Event *event, struct Game *game);

#endif /* INPUT_H_ */
