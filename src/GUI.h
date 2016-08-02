/*
 * GUI.h
 *
 *  Created on: Jul 24, 2016
 *      Author: asma
 */

#ifndef GUI_H_
#define GUI_H_

#define WINDOW_WIDTH 20
#define WINDOW_HIGHT 20

void display_menu();
void draw_field();
void make_window();
void update_window();
void clear_window();
void free_window(); //pointer van venster dealloceren, (memoryleak in dit deel)

#endif /* GUI_H_ */
