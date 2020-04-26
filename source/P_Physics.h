/*
 * P_Physics.c
 *
 *  Created on: Dec 19, 2019
 *  Author: Simón Prêcheur Llarena
 *
 *  Physics engine of the game.
 *
 */

#ifndef P_PHYSICS_H_
#define P_PHYSICS_H_

// Functions used to update the character's position under specific rules
// of Physics for each action and coordinate.

void walking_xPosition_update(int* step, int direction, int* x);

void running_xPosition_update(int* step, int direction, int* x);

int acceleration_xPosition_update(int* step, int direction, int *x, int sign);

int jumping_yPosition_update(int* step, int* y);

void falling_yPosition_update(int* step, int* y, float init_speed);

#endif /* P_PHYSICS_H_ */
