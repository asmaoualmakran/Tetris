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
#include "High_score.h"
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
	bool window_open;
	struct Block current_block;
	struct Hold hold;
};


void game_func(struct Game *game);

struct Block get_current_block(struct Game *game);
void set_current_block(struct Game *game);
struct Game new_game();
//struct Game load_game(const char file_path);
struct Game init_game();
//void save_game(struct Game game);
//void pause_game(struct Game *game);
//void resume_game(struct Game *game);
void stop_game(struct Game *game);
void game_over(struct Game *game);
int test_full_line(struct Game *game);
int set_hold_current_block(struct Game *game);

#endif /* GAME_H_ */
