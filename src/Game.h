/*
 * Game.h
 *
 *  Created on: Jul 29, 2016
 *      Author: asma
 */

#ifndef GAME_H_
#define GAME_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Score.h"
#include "High_score.h"
#include "Grid.h"
#include "Block.h"
#include "Hold.h"
#include "GUI.h"

typedef int bool;
enum { false, true };

struct Game{
	struct Score score;
	struct High_score high_score;
	struct Cell ***grid;
	bool game_over;
	bool paused;
	struct Block current_block;
	//hold
};


void gameloop(struct Game game);

struct Block get_current_block(struct Game *game);
void set_current_block(struct Game *game, struct Hold *hold);
struct Game new_game();
struct Game load_game(const char file_path);
struct Game init_game(); //als load file niet bestaat een volledig nieuwe game starten
void save_game(struct Game game);
void pause_game(struct Game *game);
void resume_game(struct Game *game);
void stop_game(struct Game *game);
// geen restart game, hetzelfde als new_game


#endif /* GAME_H_ */
