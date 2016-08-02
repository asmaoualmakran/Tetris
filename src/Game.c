/*
 * Game.c
 *
 *  Created on: Jul 29, 2016
 *      Author: asma
 */

#include"Game.h"


void pause_game(struct Game *game){
	game->paused = true;

};

void stop_game(struct Game *game){
	game->game_over = true;
	printf("GAME OVER \n");
};

void resume_game(struct Game *game){
	game->paused = false;

}

struct Game new_game(){
	struct Game game;

	game.score = init_score_board();
	game.high_score = init_high_score();
	game.grid = new_grid();
	game.game_over = false;
	game.paused = false;

	return game;
};


static void sleep(int nr_of_seconds, int nr_of_milliseconds) {
	struct timespec *sleep_time = malloc(sizeof(struct timespec));
	sleep_time->tv_sec = nr_of_seconds;
	sleep_time->tv_nsec = nr_of_milliseconds * 1000 * 1000;
	struct timespec *remainder_sleep_time = malloc(sizeof(struct timespec));
	nanosleep(sleep_time, remainder_sleep_time);
}

/*
struct Game load_game(const char file_path){

};

struct game init_game(){

};

void save_game(struct Game game){

};

*/

struct Block get_current_block(struct Game *game){
	struct Block current = game->current_block;
	return current;
};

void set_current_block(struct Game *game, struct Hold *hold){
	game->current_block = hold->hold_block; // get_hold(*hold) Return block from hold, generate new block and put in hold
};

void game_loop(struct Game game){
//set_current_block


	while(game.game_over == false && game.paused == false){

		/*
		 * if (current_bottom)
		 *
		 * 	if (clear line)
		 * 		clear line, inc score
		 *
		 * 	dan laad je een nieuwe current in
		 * 	update de hold (nieuwe hold inladen)
		 * 	veld en hold opnieuw tekenen
		 *
		 *	else
		 *		nieuwe current laden
		 *		hold updaten
		 *		veld en hold opnieuw tekenen
		 */

		//get_input();              -- input van gebruiker ontvangen, wordt geprocessed in input adt
		//block = get_current_block(&game); -- blok uit de hold halen en ze bovenaan zetten
		//move_block(bock, down)    -- block naar benenden doen bewegen, block uit block adt, wordt geinitieerd en de rotatie bijgehouden in
										//rotation matrix
		//display field				-- nieuwe toestand uittekenen, speelveld wordt geiniteerd bij het initeren van het spel
		//display_score();          -- nieuwe score tonen, score board wordt geinitieerd bij het maken van het spel
		//sleep();					-- zorgen dat het blokje niet te snel valt, loop te snel wordt uitgevoerd
	}
		/*
		 * if(game.game_over == true)  game over waneer de blokjes de bovenkant van het scherm raken
		 * game over displayen
		 * speler keuze geven, om opnieuw te starten
		 * huidige score en highscore displayen
		 * testen of huidige scoren bij de highscores kan
		 * else
		 * is het spel gepauseerd
		 * speler keuze geven, verder doen, opnieuw starten, spel opslaan
		 * if verder doen
		 *    uit pause toestand gaan
		 *
		 * else if opnieuw opstarten
		 * 		check huidige score in highscores
		 *    	nieuw spel opstarten
		 *
		 * else if stoppen zonder opslaan
		 * 		check huidige score in highscores
		 * 		naar start menu gaan
		 *
		 * else (stoppen met op te slaan)
		 * 		checken of score in highscore
		 * 		spel (struct, toestand) in file schrijven
		 * 		save_game(game)
		 *
		 */
	sleep(0,500);
};

