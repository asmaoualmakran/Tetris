/*
 * score.c
 *
 *  Created on: Jul 9, 2016
 *      Author: asma
 */

#include "Score.h"



struct Score init_score_board(){
	struct Score S;
	S.current_score = 0;
	printf("score initiated \n");
	return S;
};

void inc_score(struct Score *x){
	x->current_score = (x->current_score + INC); // increment with default increment value
};

void reset_score(struct Score *x){
	x->current_score = 0; // reset the score to 0
};

void print_score(struct Score *x){
	int score = x->current_score;
	printf("%d \n", score);
};
