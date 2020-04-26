/*
 * P_GamePlay.h
 *
 *  Created on: Nov 23, 2019
 *  Author: Simón Prêcheur Llarena
 *
 * This is the module where all the theoretical planning of the game
 * takes place.
 *
 */

#ifndef P_GAMEPLAY_H_
#define P_GAMEPLAY_H_

#include <stdio.h>
#include <nds.h>
#include "P_Physics.h"
#include "P_definitions.h"
#include "P_SpriteAnimation.h"


enum platformStates {IDLE, WALKING, RUNNING, JUMPING, JUMPING_MV, FALLING, FALLING_MV};


// Global variable which describes the state of the main character in the game.
// Defines the coordinates in the map, the state of current action, step in animation,
// and direction (left or right) of the character.
typedef struct Position
{
	int x;
	int y;
	int direction;
	enum platformStates platformState;
	int step;  // step in current action
} Position;

#define HEIGHT_GRID 192
#define WIDTH_GRID 1024
int OCCUPANCY_GRID[HEIGHT_GRID*WIDTH_GRID];

// Initialization
void gameplay_init();

// A set of functions to be called when each button pressed:
void gameplay_right();

void gameplay_left();

void gameplay_B();

void gameplay_up();

void gameplay_NULL();

void gameplay_no_jump();

void gameplay_boss_updatePosition();

// main coordinate updating function, is called every iteration
void gameplay_updatePosition(int allowScroll);

#endif /* P_GAMEPLAY_H_ */
