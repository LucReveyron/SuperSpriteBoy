/*
 * P_matrix.c
 *
 *  Created on: Dec 22, 2019
 *  Author: Simón Prêcheur Llarena
 *
 *  This module deals with the creation of the occupancy grids/masks,
 *  For each level.
 *
 */

#include "P_matrix.h"

#define HEIGHT_GRID 192
#define WIDTH_GRID 1024

void matrix_add_borders(int* OCCUPANCY_GRID)
{
	int i, j;
	for(i =0;i<192;i++)
	{
		for(j=0;j<1024;j++)
		{
			if (j == 0 || j == WIDTH_GRID-1 || i == 0 || i == HEIGHT_GRID)
				OCCUPANCY_GRID[j+1024*i] = 1;
		}
	}
}

void create_boss_mask(int *OCCUPANCY_GRID)
{
	int i;
	int j;
	for(i=0;i<192;i++)
	{
		for(j=0;j<256;j++)
		{
			if(i == 192-8 || i == 192-7)
				OCCUPANCY_GRID[j+1024*i] = 1;
			else
				OCCUPANCY_GRID[j+1024*i] = 0;

			// borders:
			if (j == 0 || j == 255 || i == 0 || i == HEIGHT_GRID)
				OCCUPANCY_GRID[j+1024*i] = 1;
		}
	}

}

void create_forest_mask(int* OCCUPANCY_GRID)
{
	int i;
	int j;
	for(i =0;i<192;i++)
	{
		for(j=0;j<1024;j++)
		{
			if(i == 192-15 || i == 192-14) // ground with security layer
				OCCUPANCY_GRID[j+1024*i] = 1;
			else
				OCCUPANCY_GRID[j+1024*i] = 0;

			// borders:
			if (j == 0 || j == WIDTH_GRID-1 || i == 0 || i == HEIGHT_GRID-1)
				OCCUPANCY_GRID[j+1024*i] = 1;

			// rock:
			if ((j >= 170)&&(j <= 226)&&(i >= 192-40))
			{
				OCCUPANCY_GRID[j+1024*i] = 1;
			}

			// well:
			if ((j >= 337)&&(j <= 366)&&(i >= 192-31))
			{
				OCCUPANCY_GRID[j+1024*i] = 1;
			}

			if ((j >= 394)&&(j <= 427)&&(i >= 192-31)) //422
			{
				OCCUPANCY_GRID[j+1024*i] = 1;
			}

			if (j >= 337 && j <= 427 && (i == (192 - 15) || i == (192-14) || i == 0)) //422
			{
				OCCUPANCY_GRID[j+1024*i] = 0;
			}
		}
	}
}

void create_castle_mask(int* OCCUPANCY_GRID)
{
	int i;
	int j;
	for(i =0;i<192;i++)
	{
		for(j=0;j<1024;j++)
		{
			if(i == 192-15 || i == 192-14) // ground with security layer
				OCCUPANCY_GRID[j+1024*i] = 1;
			else
				OCCUPANCY_GRID[j+1024*i] = 0;

			// borders:
			if (j == 0 || j == WIDTH_GRID-1 || i == 0 || i == HEIGHT_GRID-1)
				OCCUPANCY_GRID[j+1024*i] = 1;

			// level intersection:
			if (j == 512)
				OCCUPANCY_GRID[j+1024*i] = 1;

			// Platform 1
			if((j >= 151)&&(j <= 198)&&(i >= 192-42)&&(i < 192-29))
			{
				OCCUPANCY_GRID[j+1024*i] = 1;
			}
			// Platform 2
			if((j >= 128)&&(j <= 175)&&(i >= 192-118)&&(i < 192-105))
			{
				OCCUPANCY_GRID[j+1024*i] = 1;
			}
			// Platform 3 (big)
			if((j >= 0)&&(j <= 117)&&(i >= 192-128)&&(i < 192-109))
			{
				OCCUPANCY_GRID[j+1024*i] = 1;
			}
			// Platform 4
			if((j >= 248)&&(j <= 295)&&(i >= 192-110)&&(i < 192-97))
			{
				OCCUPANCY_GRID[j+1024*i] = 1;
			}
			// Platform 5 (big)
			if((j >= 333)&&(j <= 450)&&(i >= 192-152)&&(i < 192-133))
			{
				OCCUPANCY_GRID[j+1024*i] = 1;
			}
			// Platform 6 (Largest)
			if((j >= 330)&&(j <= 512)&&(i >= 192-56)&&(i < 192-40))
			{
				OCCUPANCY_GRID[j+1024*i] = 1;
			}

			// Stairs
			if((j >= 455)&&(j <= 512)&&(i >= 192-62)&&(i < 192-40))
			{
				OCCUPANCY_GRID[j+1024*i] = 1;
			}
			if((j >= 463)&&(j <= 512)&&(i >= 192-68)&&(i < 192-40))
			{
				OCCUPANCY_GRID[j+1024*i] = 1;
			}
			if((j >= 471)&&(j <= 512)&&(i >= 192-74)&&(i < 192-40))
			{
				OCCUPANCY_GRID[j+1024*i] = 1;
			}
			if((j >= 479)&&(j <= 512)&&(i >= 192-80)&&(i < 192-40))
			{
				OCCUPANCY_GRID[j+1024*i] = 1;
			}
			if((j >= 486)&&(j <= 512)&&(i >= 192-86)&&(i < 192-40))
			{
				OCCUPANCY_GRID[j+1024*i] = 1;
			}

			// Second room
			if((j >= 655)&&(j <= 705)&&(i >= 192-40)&&(i < 192-30))
			{

				OCCUPANCY_GRID[j+1024*i] = 1;
			}
			if((j >= 725)&&(j <= 775)&&(i >= 192-70)&&(i < 192-60))
			{
				OCCUPANCY_GRID[j+1024*i] = 1;
			}

			if((j >= 799)&&(j <= 849)&&(i >= 192-40)&&(i < 192-30))
			{
				OCCUPANCY_GRID[j+1024*i] = 1;
			}
			// lava pit
			if((j > 607)&&(j < 903)&&(i == 192-15))
			{
				OCCUPANCY_GRID[j+1024*i] = 0;
			}

		}
	}
}
