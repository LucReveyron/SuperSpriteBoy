/*
Title: P_definitions.h
Version: 1.0
Author: Luc Reveyron
Description: All defines, constants, and structures for the game.
*/

#ifndef DEFINITION_H_
#define DEFINITION_H_

#define SCREEN_WIDTH 	256
#define SCREEN_HEIGHT 	192

#define MAPSIZE 		512

#define GROUND 			SCREEN_HEIGHT - 16
#define LAST_FRONTIER 	4*SCREEN_HEIGHT

#define SPRITE_HEIGHT 	 64
#define SPRITE_WIDTH 	 64
#define CHARACTER_HEIGHT 48
#define LEFT_MARGIN		 20
#define RIGHT_MARGIN	 45

#define VISIBLE 		0
#define HIDE			1

// First position of the character
#define START_X 	4
#define START_Y		17

// First position of the boss
#define ENNEMY_START_X 	130
#define ENNEMY_START_Y	5

// First position of the character in the screen coordinates
#define ORIGIN_X	4
#define ORIGIN_Y	SCREEN_HEIGHT - 50

#define CHARACTER 0
#define PLATFORM  1
#define ENNEMY 	  2

#define LEFT 	0
#define RIGHT 	1

#define QUIT		0
#define START		1
#define NO_BUTTON	2

#define SCROLLING_SPEED		2
#define SCROLL_ON			1
#define SCROLL_OFF			0
#define NO_SCROLL			1
#define SCROLL				0
#define END_FOREST_SCROLL 	640
#define END_FOREST			750

enum levels {MENU,WAIT_FOREST,FOREST,WAIT_CASTLE,CASTLE, WAIT_BOSS, BOSS, GAMEOVER,VICTORY,DEBUG};

extern int level_global;

#endif /* DEFINITION_H_ */
