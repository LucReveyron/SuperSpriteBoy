/*
Title: P_LevelManager.c
Version: 1.0
Author: Luc Reveyron
Description: All the functions to define level functionnality
*/

#include "P_TopScreen.h"
#include "P_SubScreen.h"
#include "P_SpriteAnimation.h"
#include "P_GamePlay.h"
#include "P_SpriteAnimation.h"
#include "P_timer.h"
#include "P_LevelManager.h"
#include "P_definitions.h"
#include "P_Audio.h"
#include "P_controls.h"
#include "P_matrix.h"

void menu()
{
	Audio_PlayMusic(MOD_DS2);
	// Load current background
	load_background(MENU);
    load_sub_background(NO_BUTTON);

	gameplay_init();

	//Hide sprites on the screen
	refresh_sprite_position(CHARACTER, ORIGIN_X, ORIGIN_Y, false, HIDE);
	refresh_sprite_position(BOSS, ORIGIN_X, ORIGIN_Y, false, HIDE);
	sprite_update();
}

void wait_music()
{
	while (mmActive()) ;
}

void wait_forest()
{
	// Load current background
	load_background(WAIT_FOREST);
	//Hide sprites
	refresh_sprite_position(CHARACTER, ORIGIN_X, ORIGIN_Y, false, HIDE);
	create_forest_mask(OCCUPANCY_GRID);
}

void forest_level()
{
	Audio_PlayMusic(MOD_DS1);
	// Load current backgrounds
	load_background(FOREST);

	//Initialise sprite character
	refresh_sprite_position(CHARACTER, ORIGIN_X, ORIGIN_Y, false, VISIBLE);
}

void wait_castle()
{
	// Load current background
	load_background(WAIT_CASTLE);
	//Hide sprites
	refresh_sprite_position(CHARACTER, ORIGIN_X, ORIGIN_Y, false, HIDE);
	create_castle_mask(OCCUPANCY_GRID);
}

void castle_level()
{
	Audio_PlayMusic(MOD_DS4);
	// Load current backgrounds
	load_background(CASTLE);

	//Initialise sprite character
	refresh_sprite_position(CHARACTER, ORIGIN_X, ORIGIN_Y, false, VISIBLE);
}

void wait_boss()
{
	// Load current background
	load_background(WAIT_BOSS);
	//Hide sprites
	refresh_sprite_position(CHARACTER, ORIGIN_X, ORIGIN_Y, false, HIDE);
	Audio_PlayMusic(MOD_QUIT);
	create_boss_mask(OCCUPANCY_GRID);
	wait_music();
}

void boss_level()
{
	Audio_PlayMusic(MOD_DS6);
	// Load current backgrounds
	load_background(BOSS);

	//Initialise sprite character
	refresh_sprite_position(CHARACTER, ORIGIN_X, ORIGIN_Y, false, VISIBLE);
	//Initialise sprite ennemy
	refresh_sprite_position(ENNEMY, ORIGIN_X, ORIGIN_Y, false, VISIBLE);

}

void gameover()
{
	load_background(GAMEOVER);
	refresh_sprite_position(CHARACTER, ORIGIN_X, ORIGIN_Y, false, HIDE);
	Audio_PlayMusic(MOD_GAMEOVER);
	wait_music();
	menu();
}

void victory()
{
	load_background(VICTORY);
	refresh_sprite_position(CHARACTER, ORIGIN_X, ORIGIN_Y, false, HIDE);
	Audio_PlayMusic(MOD_VICTORY);
	wait_music();
	menu();
}

void level_activity(int level)
{
	switch(level)
	{
		case FOREST:
			control_check_held_keys();
    	    cloud_scroll();
    	    break; // CAREFUL

		case CASTLE:
			control_check_held_keys();
			break;

		case BOSS:
			control_check_held_keys();
			break;
	}
}

void debug()
{
	test_map_scroll(); // Overview of the map
}
