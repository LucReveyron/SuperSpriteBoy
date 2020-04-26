/*
 * "Super Sprite Boy"
 *
 * A Nintendo DS project
 * December 2019 -January 2020
 * Authors: Luc Reveyron and Simón Prêcheur Llarena
 *
 */

#include <nds.h>
#include <stdio.h>
#include "P_TopScreen.h"
#include "P_SubScreen.h"
#include "P_SpriteAnimation.h"
#include "P_GamePlay.h"
#include "P_SpriteAnimation.h"
#include "P_controls.h"
#include "P_timer.h"
#include "P_LevelManager.h"
#include "P_definitions.h"
#include "P_Audio.h"

int level_global;

int main(void) {
	
    consoleDemoInit();

    // Initialisation
    main_screen_setup();
    sub_screen_setup();
    init_sprite_graphic();
    load_sub_background(NO_BUTTON);
    Audio_Init();

    // Start Menu
    menu();

    int subButton;

    // Main game loop
    while(1)
    {
    	subButton = control_check_sub_button();

    	if(subButton == START)
    	{
    		Audio_PlayMusic(MOD_START);
    		wait_music();
    		level_global = FOREST;
    		level_transition();
    	}
    	else if(subButton == QUIT)
    	{
    		Audio_PlayMusic(MOD_QUIT);
    		wait_music();
    		level_global = MENU;
    		menu();
    	}

    	if(transition_statue())
    	{
    		level_activity(level_global);
    	}
    }
}
