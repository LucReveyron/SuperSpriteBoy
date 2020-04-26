/*
Title: P_controls.c
Version: 1.0
Author: Simón Prêcheur Llarena and Luc Reveyron
Description: All the controls
*/

#include "P_controls.h"
#include "P_SubScreen.h"
#include "P_GamePlay.h"

void control_check_held_keys()
{
	int keys;

	//Read held keys
	scanKeys();
	keys = keysHeld();

	// if just direction arrows, walk. If direction arrows + B, run.
	// Running, is only available in conjunction with other keys.
	if (((keys & KEY_RIGHT) || (keys & KEY_LEFT)) && (keys & KEY_B))
		gameplay_B();

	if (((keys & KEY_RIGHT) || (keys & KEY_LEFT)) && !(keys & KEY_A))
		gameplay_no_jump();

	if (keys & KEY_A)
		gameplay_up();

	if (keys & KEY_RIGHT)
		gameplay_right();

	if (keys & KEY_LEFT)
		gameplay_left();

	if (!(keys & KEY_RIGHT) && !(keys & KEY_LEFT) && !(keys & KEY_A))
		gameplay_NULL();



}


int control_check_sub_button()
{
	touchPosition touch;
	scanKeys();

	touchRead(&touch);

	if(touch.px||touch.py)
	{
		if((touch.px > 22)&&(touch.py > 144)&&(touch.px < 115)&&(touch.py < 177))
		{
			//Start Button
			load_sub_background(START);

		    return START;


		}
		else if((touch.px > 141)&&(touch.py > 144)&&(touch.px < 234)&&(touch.py < 177))
		{

			//Quit Button
			load_sub_background(QUIT);


			return QUIT;
		}
		else return NO_BUTTON;

	}
	else return NO_BUTTON;
}

