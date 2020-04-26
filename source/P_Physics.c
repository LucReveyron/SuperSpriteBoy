/*
 * P_Physics.c
 *
 *  Created on: Dec 19, 2019
 *  Author: Simón Prêcheur Llarena
 *
 *  Physics engine of the game.
 *
 */

# include "P_Physics.h"
# include <stdio.h>
# include "math.h"

// Physic constants
# define JUMPING_ACCELERATION -50.0
# define RUNNING_ACCELERATION 6.0
# define ACC_ACCELERATION	  8
# define FALLING_ACCELERATION -50.0

# define WALKING_SPEED 6.0
# define INITIAL_JUMPING_SPEED 22.0
# define TERMINAL_RUNNING_SPEED 8.0  // terminal running speed in [m/s]
# define TERMINAL_FALLING_SPEED 22.0  // terminal falling speed in [m/s]

# define SAMPLING_RATE 40.0  // Sampling or movement refreshing rate in Hz

# define METER_TO_COORDINATES_RATIO 18.0


// General position update function
// Uses ballistic physics formulas
int position_update(double acceleration, double initial_speed, int* step)
{
	double t = ((double) ++(*step)) / SAMPLING_RATE;
	double t_prev = ((double) ((*step) - 1)) / SAMPLING_RATE;
	double inc = acceleration/2.0*(t*t - t_prev*t_prev) + initial_speed*(t - t_prev);  // increment in meters
	return round(inc*METER_TO_COORDINATES_RATIO);  // increment in coordinate units
}

// Linear movement along the x axis
void walking_xPosition_update(int* step, int direction, int* x)
{
	int inc = position_update(0, WALKING_SPEED, step);
	*x = (direction == 1 ? (*x + inc) : (*x - inc)) ;
	printf("walking inc: %d\n", inc);
}

// accelerating motion along the x axis
void running_xPosition_update(int* step, int direction, int *x)
{
	int inc;
	if (RUNNING_ACCELERATION*(*step)/SAMPLING_RATE > TERMINAL_RUNNING_SPEED)
		inc = position_update(0, TERMINAL_RUNNING_SPEED, step);
	else
		inc = position_update(RUNNING_ACCELERATION, WALKING_SPEED, step);
	*x = (direction == 1 ? (*x + inc) : (*x - inc)) ;
}

int acceleration_xPosition_update(int* step, int direction, int *x, int sign)
{
	// function can deal with the whole acceleration / deceleration curve
	// returns 1 when movement is stopped
	int inc;
	if (sign*ACC_ACCELERATION*(*step)/SAMPLING_RATE > TERMINAL_RUNNING_SPEED)
		inc = position_update(0, TERMINAL_RUNNING_SPEED/2, step);
	else if (sign*ACC_ACCELERATION*(*step)/SAMPLING_RATE < 0)
		return 1; // comes to a stop
	else
	{
		printf("CORRECT UPDATE physics\n");
		inc = position_update(sign*ACC_ACCELERATION, 0.0, step);
	}
	*x = (direction == 1 ? (*x + inc) : (*x - inc)) ;

	return 0;
}

// Parabolic curve ascension along the y axis
int jumping_yPosition_update(int* step, int* y)
{
	int inc = position_update(JUMPING_ACCELERATION, INITIAL_JUMPING_SPEED, step);
	*y += inc;
	printf("jumping inc: %d\n", inc);

	if (FALLING_ACCELERATION*(*step)/SAMPLING_RATE + INITIAL_JUMPING_SPEED <= 0)  // OR TEST when inc == 0
		return 1; // jump is finished
	return 0;
}

// Parabolic curve descent along the y axis
void falling_yPosition_update(int* step, int* y, float init_speed)
{
	int inc = position_update(FALLING_ACCELERATION, init_speed, step);

	if (FALLING_ACCELERATION*(*step-1)/SAMPLING_RATE < -TERMINAL_FALLING_SPEED)
		inc = position_update(0, -TERMINAL_FALLING_SPEED, step);
	*y += inc;
	printf("falling inc: %d\n", inc);
}
