/*
 * P_GamePlay.c
 *
 *  Created on: Nov 23, 2019
 *  Author: Simón Prêcheur Llarena and Luc Reveyron
 *
 * This is the module where all the theoretical planning of the game
 * takes place.
 *
 */

#include <stdlib.h>
#include "math.h"
#include "P_GamePlay.h"
#include "P_SpriteAnimation.h"
#include "P_TopScreen.h"
#include "P_LevelManager.h"
#include "P_timer.h"
#include "P_definitions.h"
#include "P_Audio.h"

static int bgScrollx;
static int nextSection;

static int scrollStatue;

Position position;
Position ennemy;

static int x_local; // Position in the screen referential

// Initialization
void gameplay_init()
{
	//character starting position
	position.x = START_X;
	position.y = START_Y;
	position.step = 0;
	position.platformState = IDLE;
	position.direction = RIGHT;

	ennemy.x = ENNEMY_START_X;
	ennemy.y = ENNEMY_START_Y;
	ennemy.step = 0;
	ennemy.platformState = IDLE;
	ennemy.direction = LEFT;

	scrollStatue = SCROLL_OFF;
	bgScrollx = 0;
	nextSection = 0;

	x_local = position.x;
}


// These button dealing functions update the theoretical state of the game.
void gameplay_right()
{
	position.direction = RIGHT;
	if (position.platformState == IDLE)
	{
		position.platformState = WALKING;

		position.step = 0;  // also serves as indication for frame
	}
	if (position.platformState == JUMPING)
		position.platformState = JUMPING_MV;
	if (position.platformState == FALLING)
		position.platformState = FALLING_MV;
	gameplay_updatePosition(SCROLL);
}

void gameplay_left()
{
	position.direction = LEFT;
	if (position.platformState == IDLE)
	{
		position.platformState = WALKING;

		position.step = 0;
	}
	if (position.platformState == JUMPING)
		position.platformState = JUMPING_MV;
	if (position.platformState == FALLING)
		position.platformState = FALLING_MV;

	gameplay_updatePosition(SCROLL);
}

// B - Running, is only available in conjunction with other keys.
void gameplay_B()
{
	if (position.platformState == WALKING)
		position.platformState = RUNNING;
}

void gameplay_up()
{
	if (position.platformState == WALKING || position.platformState == RUNNING)
	{
		Audio_PlaySoundEX(SFX_JUMPFX);
		position.platformState = JUMPING_MV;
		position.step = 0;
	}
	if (position.platformState == IDLE)
	{
		Audio_PlaySoundEX(SFX_JUMPFX);
		position.platformState = JUMPING;
		position.step = 0;
	}
	gameplay_updatePosition(NO_SCROLL);
}

void gameplay_no_jump()
{
	if (position.platformState == JUMPING_MV)
	{
		position.platformState = FALLING;
		position.step = 0;
	}
}

// Function which is executed when no key is pressed.
void gameplay_NULL()
{
	if (position.platformState == WALKING || position.platformState == RUNNING)
	{
		position.platformState = IDLE;
		position.step = 0;
	}
	if (position.platformState == JUMPING_MV)
		position.platformState = JUMPING;
	if (position.platformState == FALLING_MV)
		position.platformState = FALLING;

	if (position.platformState == JUMPING)
	{
		position.platformState = FALLING;
		position.step = 0;
	}

	gameplay_updatePosition(NO_SCROLL);
}


// Checks occupancy grid at coordinates spanning THE WHOLE CHARACTER BOTTOM AND TOP
// Returns 1 if there is something (used to check beneath)
int check_beneath(int x, int y)
{
	// condition to limit to the map. There's a slight offset on top for playability
	if (y < HEIGHT_GRID && y >= 0 && x >= -LEFT_MARGIN && x < (WIDTH_GRID - RIGHT_MARGIN))
	{
		int i;
		y += (position.platformState == JUMPING || position.platformState == JUMPING_MV)*CHARACTER_HEIGHT;
		for (i = (x + 32 - 4); i < (x + 32 + 4); i++) // spacing between legs
		{
			if (OCCUPANCY_GRID[WIDTH_GRID*(HEIGHT_GRID - y - 1) + i])
				return 1;
		}
		return 0; // no obstacle found
	}
	else
		return 1; // out of the map
}

// Checks occupancy grid at coordinates spanning THE WHOLE CHARACTER SIDE
// Returns 1 if there is something (used to check side collisions)
int check_side(int x, int y)
{
	// condition to limit to the map. There's a slight offset on top for playability
	if (y < HEIGHT_GRID && y >= 0 && x >= -LEFT_MARGIN && x < (WIDTH_GRID - RIGHT_MARGIN))
	{
		int i;
		x += position.direction? RIGHT_MARGIN : LEFT_MARGIN;
		for (i = y; i < y + CHARACTER_HEIGHT; i++)
		{
			if (OCCUPANCY_GRID[WIDTH_GRID*(HEIGHT_GRID - i - 1) + x])
				return 1;
		}
		return 0;
	}
	else
		return 1; // off the map
}


// linear interpolation to find coordinates of collision point
// parses the occupancy grid to find the first platform in-between two positions.
// stores the new position in pointers new_x and new_y
int parse_occupancy_grid(int x_int, int y_int, int* new_x, int* new_y)
{
	float x_inc, y_inc;
	float x = x_int, y = y_int;

	if (x == *new_x) // straight jump
	{
		y_inc = (*new_y - y)/abs(*new_y - y);  // gives sign of increment
		while (y != *new_y)
		{
			y += y_inc;
			if ( check_beneath((int) round(x), (int) round(y)) )
			{
				Audio_PlaySoundEX(SFX_OBSTACLEFX);
				printf("OBSTACLE FOUND! (jump)\n");
				*new_y = round(y - y_inc);
				return 1;  // return 1 for obstacle
			}
		}
		return 0;
	}
	else if (y == *new_y) // straight walking
	{
		x_inc = (*new_x - x)/abs(*new_x - x);
		while (x != *new_x)
		{
			x += x_inc;
			if ( check_side((int) round(x), (int) round(y)) )
			{
				printf("OBSTACLE FOUND! (walk)\n");
				//Audio_PlaySoundEX(SFX_OBSTACLEFX);
				*new_x = round(x - x_inc);
				return 1;  // return 1 for obstacle
			}
		}
		return 0;
	}
	else  // moving jump
	{
		float a = fabs((*new_y - y) / (*new_x - x));
		if (a>=1)
		{
			x_inc = (*new_x - x)/fabs(*new_x - x)/a;
			y_inc = (*new_y - y)/fabs(*new_y - y);
		}
		if (a<1)
		{
			x_inc = (*new_x - x)/fabs(*new_x - x);
			y_inc = (*new_y - y)/fabs(*new_y - y)*a;
		}

		printf("\nxinc: %f, yinc: %f\n Points: ", x_inc, y_inc);
		while (x != *new_x && y != *new_y)
		{
			x += x_inc; y += y_inc;

			printf("%d %d ",(int) round(x), (int) round(y));
			if ( check_beneath((int) round(x), (int) round(y)) )
			{
				printf("OBSTACLE bnth/above FOUND! (moving jump)\n");
				// updates of coordinates right before obstacle.
				// x is updated and y remains the same
				*new_y = round(y - y_inc);
				return 1;  // return 1 for obstacle from beneath or above
			}
			if ( check_side((int) round(x), (int) round(y)) )
			{
				printf("OBSTACLE side FOUND! (moving jump)\n");
				// updates of coordinates right before obstacle.
				// y is updated and x remains the same
				*new_x = round(x - x_inc);
				return 2;  // return 2 for obstacle on the sides
			}
		}
		return 0; // no obstacle found
	}
}

void gameplay_boss_updatePosition()
{
	// defines boss movement

	if (ennemy.x + (ennemy.direction == RIGHT ? RIGHT_MARGIN : LEFT_MARGIN) > 0 &&
		ennemy.x + (ennemy.direction == RIGHT ? RIGHT_MARGIN : LEFT_MARGIN) < SCREEN_WIDTH)
	{
		if (ennemy.direction == RIGHT && ennemy.x < x_local) // rushes towards character
		{
			acceleration_xPosition_update(&ennemy.step, ennemy.direction, &ennemy.x, 1);
		}

		if (ennemy.direction == RIGHT && ennemy.x > x_local) // slow down and turns around
		{
			if (acceleration_xPosition_update(&ennemy.step, ennemy.direction, &ennemy.x, -1))
			{
				// turns around (this code will be executed once, then it will "rush"
				ennemy.direction = LEFT;
				ennemy.step = 0;
			}
		}

		if (ennemy.direction == LEFT && ennemy.x > x_local) // rushes towards character
		{
			acceleration_xPosition_update(&ennemy.step, ennemy.direction, &ennemy.x, 1);
		}

		if (ennemy.direction == LEFT && ennemy.x < x_local) // turns around
		{
			if (acceleration_xPosition_update(&ennemy.step, ennemy.direction, &ennemy.x, -1))
			{
				// turns around (this code will be executed once, then it will "rush"
				ennemy.direction = RIGHT;
				ennemy.step = 0;
			}
		}
	}
	else
		ennemy.direction = (ennemy.direction ? LEFT : RIGHT);
}

// Updating the character position, this function is called every iteration.
void gameplay_updatePosition(int allowScroll)
{
	int inc = 0;


	if (position.platformState != IDLE)
		printf("State: %d, x: %d, y: %d, ex: %d\n", position.platformState, position.x, position.y, ennemy.x);
	int new_x = position.x, new_y = position.y;

	// put the check_ground condition here for the switch
	switch(position.platformState)
	{
		case IDLE:
			if (!check_beneath(new_x, new_y - 1))  // vacuum beneath
				position.platformState = FALLING;
			else
				position.step ++;
			break;

		// UNITE CASES BY PUTING THE PHYSICS FUNCTION CALL IN THE GAMEPLAY CONTROL FUNCTIONS BEFORE?

		case WALKING:
			walking_xPosition_update(&position.step, position.direction, &new_x);
			if (check_beneath(new_x, new_y - 1))  // floor beneath
			{
				if ((!parse_occupancy_grid(position.x, position.y, &new_x, &new_y))) // no obstacle
				{
					inc = new_x - position.x;

					position.x = new_x;

					position.y = new_y;
				}
				else
					position.platformState = IDLE;
			}
			else  // vacuum beneath
				position.platformState = FALLING;
			break;

		case RUNNING:
			running_xPosition_update(&position.step, position.direction, &new_x);
			if (check_beneath(new_x, new_y - 1))  // floor beneath
			{
				if ((!parse_occupancy_grid(position.x, position.y, &new_x, &new_y))) // no obstacle
				{
					inc = new_x - position.x;

					position.x = new_x;

					position.y = new_y;
				}
				else
					position.platformState = IDLE;
			}
			else  // vacuum beneath
				position.platformState = FALLING;
			break;

		case JUMPING_MV:
			walking_xPosition_update(&position.step, position.direction, &new_x);
			position.step--; // we only want one increase of the step per iteration

		case JUMPING:
			// when jump is finished, fall
			if (jumping_yPosition_update(&position.step, &new_y))
			{
				position.platformState = FALLING;
				position.step = 0;
			}
			// if there is an obstacle in the path from above, abort jump
			// corrects coordinates if obstacle on the way
			if (parse_occupancy_grid(position.x, position.y, &new_x, &new_y) == 1)
			{
				position.platformState = FALLING;
				position.step = 0; // CHANGE FOR A HARSH/TRANQUIL FALL
			}

			// iteration increment, for scrolling
			inc = new_x - position.x;

			position.x = new_x;
			position.y = new_y;

			break;

		case FALLING_MV:
			walking_xPosition_update(&position.step, position.direction, &new_x);
			position.step--; // we only want one increase of the step per iteration

		case FALLING:
			falling_yPosition_update(&position.step, &new_y, 0.0);

			// if there is an obstacle in the path from bellow
			// corrects coordinates if obstacle on the way
			if (parse_occupancy_grid(position.x, position.y, &new_x, &new_y) == 1)
			{
				position.platformState = IDLE;
				position.step = 0;
			}
			if (parse_occupancy_grid(position.x, position.y, &new_x, &new_y) == 1)
			{
				position.platformState = FALLING;
				//position.step = 0;
			}

			inc = new_x - position.x;

			position.x = new_x;
			position.y = new_y;

			break;

	}

	//  Manage movement on the next map section (First section 0 < x < 512 and next section 512 < x < 1024)

	if(position.x >= 500 && level_global == FOREST && nextSection == 0)
	{
		REG_BG0VOFS = 255;
		bgScrollx = 0;
		nextSection = 1;
		x_local = 4;
	}

	if(position.x >= END_FOREST && level_global == FOREST)
	{
		level_global = CASTLE;
		bgScrollx = 0;
		gameplay_init();
		x_local = 0;
		level_transition();
		nextSection = 0;
	}

	if(position.x >= (464) && level_global == CASTLE && nextSection == 0)
	{
		REG_BG0VOFS = 29;
		REG_BG0HOFS = 0;
		bgScrollx = 0;
		position.x = START_X + MAPSIZE - LEFT_MARGIN;
		position.y = START_Y;
		position.step = 0;
		position.platformState = IDLE;
		position.direction = RIGHT;
		x_local = 0; // useless
		nextSection = 1;
	}


	// Scrolling Conditions

	if((position.x > SCREEN_WIDTH/2)&&(position.x < END_FOREST_SCROLL)&&
			(position.platformState != IDLE)&&level_global == FOREST)
	{
		x_local = SCREEN_WIDTH/2;
		scrollStatue = horizontal_scroll_background(&bgScrollx,inc);
	}
	else if((position.x > SCREEN_WIDTH/2)&&(level_global == CASTLE)&&
			(nextSection == 0)&&(position.x < 2*SCREEN_WIDTH - SCREEN_WIDTH/2))
	{
		x_local = SCREEN_WIDTH/2;
		scrollStatue = horizontal_scroll_background(&bgScrollx,inc);
	}
	else if((position.x > 2*SCREEN_WIDTH + SCREEN_WIDTH/2)&&
			(level_global == CASTLE)&&(nextSection == 1)&&
			(position.x < 4*SCREEN_WIDTH - SCREEN_WIDTH/2))
	{
		x_local = SCREEN_WIDTH/2;
		scrollStatue = horizontal_scroll_background(&bgScrollx,inc);
	}


	else if( ((level_global == FOREST)&&(((position.x <= SCREEN_WIDTH/2) ||
			(position.x >= END_FOREST_SCROLL)))) ||
			((level_global == CASTLE)&&(nextSection == 0)&&
			((position.x <= SCREEN_WIDTH/2) ||
			(position.x >= 2*SCREEN_WIDTH - SCREEN_WIDTH/2))) ||
			((level_global == CASTLE)&&(nextSection == 1)&&
			((position.x <= 2*SCREEN_WIDTH + SCREEN_WIDTH/2) ||
			(position.x >= 4*SCREEN_WIDTH - SCREEN_WIDTH/2))) ||
			(level_global) == BOSS)
	{
		if (x_local > SCREEN_WIDTH/2)
			x_local = position.x % 256; // Compute local position on the screen
		else
			x_local = position.x; // necessary because start of local coordinates is actually negative
	}

	refresh_character_sprite(position.platformState, position.step);

	if(position.direction == RIGHT)
		refresh_sprite_position(CHARACTER, x_local, SCREEN_HEIGHT -
							position.y - SPRITE_HEIGHT,false,VISIBLE);
	else if(position.direction == LEFT)
		refresh_sprite_position(CHARACTER, x_local, SCREEN_HEIGHT -
							position.y - SPRITE_HEIGHT,true,VISIBLE);

	// Boss animation
	if(level_global == BOSS)
	{
		load_background(BOSS); // animated background must be displayed each iteration
		gameplay_boss_updatePosition();
		refresh_ennemy_sprite();
		if(ennemy.direction == RIGHT)
			refresh_sprite_position(ENNEMY, ennemy.x, SCREEN_HEIGHT - SPRITE_HEIGHT - ennemy.y,false,VISIBLE);
		if(ennemy.direction == LEFT)
			refresh_sprite_position(ENNEMY, ennemy.x, SCREEN_HEIGHT - SPRITE_HEIGHT - ennemy.y,true,VISIBLE);
	}

	sprite_update();

	// GameOver Condition
	if ((level_global == CASTLE && position.x > (203 - LEFT_MARGIN) && position.y == 15 &&
			position.x < (450 - RIGHT_MARGIN) && nextSection == 0) ||
		(level_global == CASTLE && nextSection == 1 && position.x > (607 - LEFT_MARGIN) &&
			position.y < 15 && position.x < (903 - RIGHT_MARGIN)) ||
		(level_global == FOREST && position.x > (363-LEFT_MARGIN) &&
			position.x <= (398 - RIGHT_MARGIN) && position.y <= 3 ))
	{
		level_global = GAMEOVER;
		level_transition();
	}

	// BOSS Condition
	if(position.x >= 960 && level_global == CASTLE)
	{
		level_global = BOSS;
		bgScrollx = 0;
		scrollStatue = SCROLL_OFF;
		x_local = 0;
		level_transition();

		//character starting position
		position.x = START_X;
		position.y = 130;
		position.step = 0;
		position.platformState = IDLE;
		position.direction = RIGHT;
		boss_level();

	}

	// Boss Game Over Condition
	if(x_local >= ennemy.x - 5 && x_local <= ennemy.x + 5 && position.y <= (ennemy.y + 30) && level_global == BOSS)
	{
		level_global = GAMEOVER;
		level_transition();
	}

}
