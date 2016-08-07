/*
 * GUI.h
 *
 *  Created on: Jul 24, 2016
 *      Author: asma
 */

#ifndef GUI_H_
#define GUI_H_
#include "SDL/SDL.h"
#include "Grid.h"
#include "Cell.h"
#include"Game.h"


void initialize_gui();

/*
 * Tekent het huidige veld in het venster. Deze functie moeten jullie dus zelf implementeren.
 */
void draw_field(void);

void free_screen();

#endif /* GUI_H_ */
