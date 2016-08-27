/*
 * GUI.c
 *
 *  Created on: Jul 24, 2016
 *      Author: asma
 */
#include"GUI.h"





const int WINDOW_WIDTH = (CELL_WIDTH * GRID_WIDTH) + EXTRA_WIDTH;
const int WINDOW_HEIGHT = (CELL_HEIGHT * GRID_HEIGHT) + EXTRA_HEIGHT;
const char* WINDOW_TITLE = "TETRIS";


static SDL_Surface* window = NULL;


void init_window(){
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			printf("Could not initialize SDL: %s\n", SDL_GetError());
			exit(1);
		}

	   window = SDL_SetVideoMode( WINDOW_WIDTH, WINDOW_HEIGHT, 0,
	      SDL_HWSURFACE | SDL_DOUBLEBUF );
	   SDL_WM_SetCaption( WINDOW_TITLE, 0 );

}


void run_window(struct Game *game){
	game->window_open = true;
	SDL_Event event;
	int previous = -1;
	while(game->window_open){ // as long the window is open, the game is running.
		SDL_PollEvent(&event);

		if (event.type == SDL_QUIT){
			game->window_open = false;
		}

		if (previous != SDL_GetTicks() && (SDL_GetTicks() % 1000) == 0){
			printf("%d\n", SDL_GetTicks());
			previous = SDL_GetTicks();
			game_func(game);
			read_input(&event,game);

		}
	}
	close_window();

};

int *get_SDL_colour(struct Cell *cell){
	int colour = cell->colour;
	int color_code[3];
	switch(colour){
	case(red):
		color_code[0] = 225;
		color_code[1] = 0;
		color_code[2] = 0;
			break;

	case(l_blue):
		color_code[0] = 0;
		color_code[1] = 247;
		color_code[2] = 255;

			break;

	case(yellow):
			color_code[0] = 225;
				color_code[1] = 247;
				color_code[2] = 0;
			break;

	case(green):
		color_code[0] = 0;
		color_code[2] = 225;
		color_code[3] = 0;
			break;

	case(orange):
			color_code[0] = 225;
			color_code[2] = 188;
			color_code[3] = 0;

			break;

	case(pink):
			color_code[0] = 225;
				color_code[1] = 0;
				color_code[2] = 162;
			break;

	case(purple):
			color_code[0] = 196;
				color_code[1] = 0;
				color_code[2] = 255;
			break;

	case(d_green):
			color_code[0] = 4;
				color_code[1] = 121;
				color_code[2] = 35;
			break;

	case(d_red):
			color_code[0] = 121;
				color_code[1] = 4;
				color_code[2] = 35;
			break;

	case(d_blue):
			color_code[0] = 3;
				color_code[1] = 3;
				color_code[2] = 250;
			break;
	default:
			color_code[0] = 7;
			color_code[1] = 12;
			color_code[2] = 250;
	}
	return color_code;
}



void draw_grid(struct Game *game){

	int i;
	int j;
	struct Cell ***grid = game->grid;
	for(i = 0; i < GRID_HEIGHT; i++){
		for(j = 0; j < GRID_WIDTH; j++){
			struct Cell *cell = get_grid_cell(grid,j,i);
			if (cell->state != empty){
			int *colour = get_SDL_colour(cell);
			int colour_r = colour[0];
			int colour_g = colour[1];
			int colour_b = colour[2];
			SDL_Rect rect;
			rect.x = j * CELL_WIDTH;
			rect.y = i * CELL_HEIGHT;
			rect.h = CELL_HEIGHT;
			rect.w = CELL_WIDTH;
			SDL_FillRect(window, &rect,SDL_MapRGB(window->format,colour_r,colour_g,colour_b));
			}
		}
	}

	int hi;
	int hj;
	struct Hold hold = game->hold;
	struct Cell hold_cell = hold.hold_block.cell;
	for(hi = 0; hi < MATRIX_HEIGHT; hi++){
		for(hj = 0; hj < MATRIX_WIDTH; hj++){
			int *colour_h = get_SDL_colour(&hold_cell);
			int colour_r_h = colour_h[0];
			int colour_g_h = colour_h[1];
			int colour_b_h = colour_h[2];
			SDL_Rect rect;
			if(hold.hold_matrix[hj][hi] == 0){
				int black[3] = {0};
				int black_r = black[0];
				int black_g = black[1];
				int black_b = black[2];

				rect.x = (hj * CELL_WIDTH)+(CELL_WIDTH * GRID_WIDTH) + CELL_WIDTH;
				rect.y = (hi * CELL_HEIGHT);
				rect.h = CELL_HEIGHT;
				rect.w = CELL_WIDTH;
				SDL_FillRect(window, &rect,SDL_MapRGB(window->format,black_r,black_g,black_b));
			}

			rect.x = (hj * CELL_WIDTH)+(CELL_WIDTH * GRID_WIDTH) + CELL_WIDTH;
			rect.y = (hi * CELL_HEIGHT);
			rect.h = CELL_HEIGHT;
			rect.w = CELL_WIDTH;
			SDL_FillRect(window, &rect,SDL_MapRGB(window->format,colour_r_h,colour_g_h,colour_b_h));
		}

	}

	SDL_Flip(window);
};

void clear_grid(){
	SDL_FillRect(window, NULL, 0x0000);

};

void close_window(){
	SDL_FreeSurface(window);  //pointer naar de surface opruimen
	SDL_Quit();				  // SDL afsluiten
};


