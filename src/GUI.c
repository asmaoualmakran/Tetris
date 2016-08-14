/*
 * GUI.c
 *
 *  Created on: Jul 24, 2016
 *      Author: asma
 */
#include"GUI.h"



/*
 * de constanten nog aanpassen
 * zien dat je via key input het venster kunt sluiten
 * gui tekenen
 * zien dat je het venster gewoon al kunt sluiten
 */


const int WINDOW_WIDTH = (CELL_WIDTH * GRID_WIDTH) + EXTRA_WIDTH;
const int WINDOW_HEIGHT = (CELL_HEIGHT * GRID_HEIGHT) + EXTRA_HEIGHT;
const char* WINDOW_TITLE = "TETRIS";



static SDL_Surface* window = NULL;

//SDL_Event event;
/*
 * ok doe maar anders zou niks werken had het effe kapot gemaakt
 * ok, kan je dit gewoon eens runnen?
 * ja
 */

void init_window(){
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			printf("Could not initialize SDL: %s\n", SDL_GetError());
			exit(1);
		}

	   window = SDL_SetVideoMode( WINDOW_WIDTH, WINDOW_HEIGHT, 0,
	      SDL_HWSURFACE | SDL_DOUBLEBUF );
	   SDL_WM_SetCaption( WINDOW_TITLE, 0 );

}

/*
 * run_window buiten de window runnen laat het window ook openstaan
 * anders doen zoals in conway, window open laten in de gameloop
 * als je nog steeds niet weet hoe een fucking event werkt
 */
void run_window(struct Game *game){ // pointer to game
	game->window_open = true; // we open the window in function of the given game
	SDL_Event event;
	//bool game_running = game->window_open; why would you copy this? the guy works in function of the game and influences the game, no need to copy any values, read and write to the game
	int previous = -1;
	while(game->window_open){ // as long the window is open, the game is running.
		SDL_PollEvent(&event); // ;) WTF YOU USED BLACK MAGIC :o (thankx ;)) ok nu key input, het tekenen heb ik wel een idee hoe en dan zien dat ik het geupdate krijg

		if (event.type == SDL_QUIT){
			game->window_open = false;
		}

		if (previous != SDL_GetTicks() && (SDL_GetTicks() % 30) == 0){
			printf("%d\n", SDL_GetTicks());
			previous = SDL_GetTicks();
			game_func(game);

			// &game => dereference of a pointer to the game, it expects a pointer to the game mag ik? ja ;) niet juist? jawel, het was gewoon het probleem nog niet :p
			//er loopt dus iets mis met de initiaties?
			// ja waar wordt die lijn geprint?
			// in de files zelf waar hun init staat
			// hier uw loop
			//gameloop?
			// nee niet de loop functie, 1 keer een loop stap
			// als je de while uit de gameloop weglaat en dan hier de gameloop functie oproept.
			// moet hier gewoon mijn gameloop oproepen, zonder de while in die functie.
			// ok, ik ga effe naar 2c en dan maak ik de gameloop
			// nee je maakt hem niet, je hebt hem toch al? je moet daar gewoon de while uithalen. Hij mag zelf niet lopen, uw SDL loopt al
			// ok ik begrijp het
			/// /b drank voor mij ;)  tot zo en graag gedaan :*
			// tot zo mijn held :*
			read_input(&event);

		}
	}
	close_window();

};

int *get_SDL_colour(struct Cell *cell){
	int colour = cell->colour;
	int color_code[3];
	int color_code_r = color_code[0];
	int color_code_g = color_code[1];
	int color_code_b = color_code[2];
	switch(colour){
	case(red):
		color_code_r = 225;
		color_code_g = 0;
		color_code_b = 0;
			break;

	case(l_blue):
		color_code_r = 0;
		color_code_g = 247;
		color_code_b = 255;

			break;

	case(yellow):
			color_code_r = 225;
				color_code_g = 247;
				color_code_b = 0;
			break;

	case(green):
		color_code_r = 0;
		color_code_g = 225;
		color_code_b = 0;

			break;

	case(orange):
			color_code_r = 225;
			color_code_g = 188;
			color_code_b = 0;

			break;

	case(pink):
			color_code_r = 225;
				color_code_g = 0;
				color_code_b = 162;
			break;

	case(purple):
			color_code_r = 196;
				color_code_g = 0;
				color_code_b = 255;
			break;

	case(d_green):
			color_code_r = 4;
				color_code_g = 121;
				color_code_b = 35;
			break;

	case(d_red):
			color_code_r = 121;
				color_code_g = 4;
				color_code_b = 35;
			break;

	case(d_blue):
			color_code_r = 3;
				color_code_g = 3;
				color_code_b = 250;
			break;
	default:
		color_code_r = 0;
			color_code_g = 0;
			color_code_b = 0;
	}
	return color_code;
}


void draw_grid(struct Cell ***grid){
	int i;
	int j;

	for(i = 0; i < GRID_HEIGHT; i++){
		for(j = 0; j < GRID_WIDTH; j++){
		//	printf("(%d; %d)\n", i, j);
			struct Cell *cell = get_grid_cell(grid, j,i );
			int *colour = get_SDL_colour(cell);
			int colour_r = colour[0];
			int colour_g = colour[1];
			int colour_b = colour[2];
			SDL_Rect rect;
			rect.x = (j * CELL_WIDTH) ;
			rect.y = i * CELL_HEIGHT;
			rect.h = CELL_HEIGHT;
			rect.w = CELL_WIDTH;
			SDL_FillRect(window, &rect,SDL_MapRGB(window->format,colour_r,colour_g,colour_b));

		}
	}
	SDL_Flip(window);
};

void clear_grid(){
	SDL_FillRect(window, NULL, 0x00000000);
		//SDL_Flip(window);
};

void close_window(){
	SDL_FreeSurface(window);  //pointer naar de surfa{ce opruimen
	SDL_Quit();				  // SDL afsluiten
};

