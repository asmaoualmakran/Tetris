/*
 * High_score.c
 *
 *  Created on: Jul 12, 2016
 *      Author: asma
 */

#include <stdio.h>
#include <stdlib.h>
#include "High_score.h"

/*
 * Apparte file, highscore heeft eigen functionaliteiten
 */

struct High_score init_high_score() {           // als de file bestaat van de file lezen anders ga je de array met 0'en invullen
	struct High_score H;
	int i;
	printf("High_score initiated, \n");
	FILE *fp;
	fp = fopen ("../Main/aux_files/saved_scores", "r");
	int len = ftell(fp);   									// gebruiken om te kijken of de file leeg is (anders raar gedrag)

	if (fp == NULL || len == 0) {
		printf("test for null \n");
		for (i = 0; i < ARRAY_LENGTH; i++) {
			H.array[i] = 0;
		}

		printf("out of loop, \n");
	} else {
	load_high_scores(&H, "../Main/aux_files/saved_scores");
	printf("high_scores loaded, \n");
};

return H;
}
;

void load_high_scores(struct High_score *x, const char *file_path) {
FILE * fp;
fp = fopen(file_path, "r");
if (fp == NULL ) {
printf("fp == Null, \n");
} else {
	char buffer[BUFF_SIZE];
	int i = 0;
	while (fgets(buffer, BUFF_SIZE, fp) && i < ARRAY_LENGTH)
	{
		int score = atoi(buffer);
		x->array[i] = score;
		i++;
	};
}
fclose(fp);
}
;

void save(struct High_score *x, const char *file_path){
	FILE * fp;
	fp = fopen(file_path, "w");
	if(fp == NULL){
		printf("no such file found");

	} else{
		int i;
		for(i = 0; i < ARRAY_LENGTH; i++){
			fprintf(fp, "%d \n", x->array[i]);
		}
	}
	fclose(fp);
};

void add(struct High_score *high_score, struct Score score) {
// begin array is gesorteerd.
// we hebben een waarde
// we zoeken de locatie in de array waar de waarde moet zitten
if (score.current_score > high_score->array[ARRAY_LENGTH - 1]) { // randgeval, als het getal kleiner is dan de kleinste waarde in de highscore: gewoon niet beginnen
	int i = (ARRAY_LENGTH - 2);
	while (i >= 0 && score.current_score > high_score->array[i]) {
		high_score->array[i + 1] = high_score->array[i];
		i--;
		printf("%d\n", i);
	}
	high_score->array[i + 1] = score.current_score;
}

}
;

void print_high_scores(struct High_score *x) {
int i;
for (i = 0; i < ARRAY_LENGTH; i++) {
	printf("%d. %d, \n", i, x->array[i]);

}
}
;


