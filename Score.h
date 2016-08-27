/*
 * Score.h
 *
 *  Created on: Jul 9, 2016
 *      Author: asma
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef SCORE_H_
#define SCORE_H_

#define INC 10
#define ARRAY_LENGTH 10

struct Score{
	int current_score;
};

struct Score init_score_board();
void inc_score(struct Score *x);
void reset_score(struct Score *x);
void save_score (void (*f)(), int s);
void load_high_score(const char *file_path);
void sort_scores (int arr[]);
void print_score(struct Score *x);


#endif /* SCORE_H_ */
