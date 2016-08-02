/*
 * High_score.h
 *
 *  Created on: Jul 12, 2016
 *      Author: asma
 */


#include"Score.h"

#ifndef HIGH_SCORE_H_
#define HIGH_SCORE_H_
#define SAVE_FILE "../tetris/save"
#define ARRAY_LENGTH 10
#define BUFF_SIZE 11

struct High_score{
	int array[ARRAY_LENGTH];
};

struct High_score init_high_score();

void load_high_scores(struct High_score *x, const char *file_path);
void add(struct High_score *high_score, struct Score score);
void save(struct High_score *x, const char *file_path);
void print_high_scores(struct High_score *x);

#endif /* HIGH_SCORE_H_ */
