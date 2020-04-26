/*
Title: P_SpriteAnimation.c
Version: 1.0
Author: Luc Reveyron
Description: Function to inialise and refresh the differents sprite.
*/

#include "P_SpriteAnimation.h"
#include "P_GamePlay.h"
#include "testC.h"
#include "testC2.h"
#include "capuche1.h"
#include "capuche2.h"
#include "capuche3.h"
#include "capuche4.h"
#include "capuche_jump1.h"
#include "capuche_jump2.h"
#include "capuche_jump3.h"
#include "capuche_jump4.h"
#include "capuche_idle1.h"
#include "capuche_idle2.h"
#include "capuche_idle3.h"
#include "capuche_idle4.h"
#include "capuche_idle5.h"
#include "capuche_idle6.h"
#include "capuche_idle7.h"
#include "capuche_idle8.h"
#include "capuche_idle9.h"
#include "capuche_idle10.h"
#include "capuche_idle11.h"
#include "capuche_idle12.h"
#include "capuche_idle13.h"
#include "capuche_walk1.h"
#include "capuche_walk2.h"
#include "capuche_walk3.h"
#include "capuche_walk4.h"
#include "capuche_walk5.h"
#include "capuche_walk6.h"
#include "capuche_walk7.h"
#include "capuche_walk8.h"
#include "capuche_walk9.h"
#include "capuche_walk10.h"
#include "capuche_walk11.h"
#include "capuche_walk12.h"
#include "capuche_walk13.h"
#include "capuche_walk14.h"
#include "capuche_walk15.h"
#include "capuche_walk16.h"
#include "fire_ball.h"

#include "P_definitions.h"

u16* gfx_character;
u16* gfx_ennemy;

void init_sprite_graphic()
{

	//Set up memory bank to work in sprite mode (offset since we are using VRAM A for background)
	VRAM_B_CR = VRAM_ENABLE | VRAM_B_MAIN_SPRITE_0x06400000;

	//Initialize sprite manager and the engine
	oamInit(&oamMain, SpriteMapping_1D_64, false);

	//Allocate space for the graphic to show in the sprite
	gfx_character = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_256Color);
	gfx_ennemy = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_256Color);

	//Copy data for the graphic (palette and bitmap)
	swiCopy(capuche_idle1Pal,SPRITE_PALETTE, capuche_idle1PalLen/2);
	swiCopy(capuche_idle1Tiles, gfx_character, capuche_idle1TilesLen/2);

}

void refresh_character_sprite(int platformState, int step)
{
	int frame_period = 2; //default value for walking
	switch(platformState)
	{
		case IDLE:
			frame_period = 6;
			switch((step/frame_period) % 13)
			{
				case 0:
					swiCopy(capuche_idle1Pal,SPRITE_PALETTE, capuche_idle1PalLen/2);
					swiCopy(capuche_idle1Tiles, gfx_character, capuche_idle1TilesLen/2);
					break;
				case 1:
					swiCopy(capuche_idle2Pal,SPRITE_PALETTE, capuche_idle2PalLen/2);
					swiCopy(capuche_idle2Tiles, gfx_character, capuche_idle2TilesLen/2);
					break;
				case 2:
					swiCopy(capuche_idle3Pal,SPRITE_PALETTE, capuche_idle3PalLen/2);
					swiCopy(capuche_idle3Tiles, gfx_character, capuche_idle3TilesLen/2);
					break;
				case 3:
					swiCopy(capuche_idle4Pal,SPRITE_PALETTE, capuche_idle4PalLen/2);
					swiCopy(capuche_idle4Tiles, gfx_character, capuche_idle4TilesLen/2);
					break;
				case 4:
					swiCopy(capuche_idle5Pal,SPRITE_PALETTE, capuche_idle5PalLen/2);
					swiCopy(capuche_idle5Tiles, gfx_character, capuche_idle5TilesLen/2);
					break;
				case 5:
					swiCopy(capuche_idle6Pal,SPRITE_PALETTE, capuche_idle6PalLen/2);
					swiCopy(capuche_idle6Tiles, gfx_character, capuche_idle6TilesLen/2);
					break;
				case 6:
					swiCopy(capuche_idle7Pal,SPRITE_PALETTE, capuche_idle7PalLen/2);
					swiCopy(capuche_idle7Tiles, gfx_character, capuche_idle7TilesLen/2);
					break;
				case 7:
					swiCopy(capuche_idle8Pal,SPRITE_PALETTE, capuche_idle8PalLen/2);
					swiCopy(capuche_idle8Tiles, gfx_character, capuche_idle8TilesLen/2);
					break;
				case 8:
					swiCopy(capuche_idle9Pal,SPRITE_PALETTE, capuche_idle9PalLen/2);
					swiCopy(capuche_idle9Tiles, gfx_character, capuche_idle9TilesLen/2);
					break;
				case 9:
					swiCopy(capuche_idle10Pal,SPRITE_PALETTE, capuche_idle10PalLen/2);
					swiCopy(capuche_idle10Tiles, gfx_character, capuche_idle10TilesLen/2);
					break;
				case 10:
					swiCopy(capuche_idle11Pal,SPRITE_PALETTE, capuche_idle11PalLen/2);
					swiCopy(capuche_idle11Tiles, gfx_character, capuche_idle11TilesLen/2);
					break;
				case 11:
					swiCopy(capuche_idle12Pal,SPRITE_PALETTE, capuche_idle12PalLen/2);
					swiCopy(capuche_idle12Tiles, gfx_character, capuche_idle12TilesLen/2);
					break;
				case 12:
					swiCopy(capuche_idle13Pal,SPRITE_PALETTE, capuche_idle13PalLen/2);
					swiCopy(capuche_idle13Tiles, gfx_character, capuche_idle13TilesLen/2);
					break;
			}
			break;

		case RUNNING:
			frame_period = 1;
		case WALKING:
			switch((step/frame_period) % 16)
			{
				case 0:
					swiCopy(capuche_walk1Pal,SPRITE_PALETTE, capuche_walk1PalLen/2);
					swiCopy(capuche_walk1Tiles, gfx_character, capuche_walk1TilesLen/2);
					break;
				case 1:
					swiCopy(capuche_walk2Pal,SPRITE_PALETTE, capuche_walk2PalLen/2);
					swiCopy(capuche_walk2Tiles, gfx_character, capuche_walk2TilesLen/2);
					break;
				case 2:
					swiCopy(capuche_walk3Pal,SPRITE_PALETTE, capuche_walk3PalLen/2);
					swiCopy(capuche_walk3Tiles, gfx_character, capuche_walk3TilesLen/2);
					break;
				case 3:
					swiCopy(capuche_walk4Pal,SPRITE_PALETTE, capuche_walk4PalLen/2);
					swiCopy(capuche_walk4Tiles, gfx_character, capuche_walk4TilesLen/2);
					break;
				case 4:
					swiCopy(capuche_walk5Pal,SPRITE_PALETTE, capuche_walk5PalLen/2);
					swiCopy(capuche_walk5Tiles, gfx_character, capuche_walk5TilesLen/2);
					break;
				case 5:
					swiCopy(capuche_walk6Pal,SPRITE_PALETTE, capuche_walk6PalLen/2);
					swiCopy(capuche_walk6Tiles, gfx_character, capuche_walk6TilesLen/2);
					break;
				case 6:
					swiCopy(capuche_walk7Pal,SPRITE_PALETTE, capuche_walk7PalLen/2);
					swiCopy(capuche_walk7Tiles, gfx_character, capuche_walk7TilesLen/2);
					break;
				case 7:
					swiCopy(capuche_walk8Pal,SPRITE_PALETTE, capuche_walk8PalLen/2);
					swiCopy(capuche_walk8Tiles, gfx_character, capuche_walk8TilesLen/2);
					break;
				case 8:
					swiCopy(capuche_walk9Pal,SPRITE_PALETTE, capuche_walk9PalLen/2);
					swiCopy(capuche_walk9Tiles, gfx_character, capuche_walk9TilesLen/2);
					break;
				case 9:
					swiCopy(capuche_walk10Pal,SPRITE_PALETTE, capuche_walk10PalLen/2);
					swiCopy(capuche_walk10Tiles, gfx_character, capuche_walk10TilesLen/2);
					break;
				case 10:
					swiCopy(capuche_walk11Pal,SPRITE_PALETTE, capuche_walk11PalLen/2);
					swiCopy(capuche_walk11Tiles, gfx_character, capuche_walk11TilesLen/2);
					break;
				case 11:
					swiCopy(capuche_walk12Pal,SPRITE_PALETTE, capuche_walk12PalLen/2);
					swiCopy(capuche_walk12Tiles, gfx_character, capuche_walk12TilesLen/2);
					break;
				case 12:
					swiCopy(capuche_walk13Pal,SPRITE_PALETTE, capuche_walk13PalLen/2);
					swiCopy(capuche_walk13Tiles, gfx_character, capuche_walk13TilesLen/2);
				case 13:
					swiCopy(capuche_walk14Pal,SPRITE_PALETTE, capuche_walk14PalLen/2);
					swiCopy(capuche_walk14Tiles, gfx_character, capuche_walk14TilesLen/2);
					break;
				case 14:
					swiCopy(capuche_walk15Pal,SPRITE_PALETTE, capuche_walk15PalLen/2);
					swiCopy(capuche_walk15Tiles, gfx_character, capuche_walk15TilesLen/2);
					break;
				case 15:
					swiCopy(capuche_walk16Pal,SPRITE_PALETTE, capuche_walk16PalLen/2);
					swiCopy(capuche_walk16Tiles, gfx_character, capuche_walk16TilesLen/2);
			}
			break;

		case JUMPING_MV:
		case JUMPING:
			//Copy data for the graphic (palette and bitmap)
			swiCopy(capuche_jump1Pal,SPRITE_PALETTE, capuche_jump1PalLen/2);
			swiCopy(capuche_jump1Tiles, gfx_character, capuche_jump1TilesLen/2);
			break;
		case FALLING_MV:
		case FALLING:
			if (step == 0 || step == 1)
			{
				swiCopy(capuche_jump2Pal,SPRITE_PALETTE, capuche_jump2PalLen/2);
				swiCopy(capuche_jump2Tiles, gfx_character, capuche_jump2TilesLen/2);
			}
			else if (step == 2 || step == 3)
			{
				swiCopy(capuche_jump3Pal,SPRITE_PALETTE, capuche_jump3PalLen/2);
				swiCopy(capuche_jump3Tiles, gfx_character, capuche_jump3TilesLen/2);
			}
			else if (step > 3)
			{
				swiCopy(capuche_jump4Pal,SPRITE_PALETTE, capuche_jump4PalLen/2);
				swiCopy(capuche_jump4Tiles, gfx_character, capuche_jump4TilesLen/2);
			}
			break;
	}
}

void refresh_ennemy_sprite()
{
	swiCopy(fire_ballTiles, gfx_ennemy, fire_ballTilesLen/2);
}

void refresh_sprite_position(int type, int x, int y, bool flip, bool hide)
{
	u16** gfx = NULL;
	int id;

	if(type == CHARACTER)
	{
		*gfx = gfx_character;
		id = 0;
	}

	if(type == ENNEMY)
	{
		*gfx = gfx_ennemy;
		id = 1;
	}

	oamSet(&oamMain, 		// oam handler
	    	id,				// Number of sprite
	    	x, y,			// Coordinates
	    	0,				// Priority
	    	0,				// Palette to use
	    	SpriteSize_64x64,			// Sprite size
	    	SpriteColorFormat_256Color,	// Color format
	    	*gfx,			// Loaded graphic to display
	    	-1,				// Affine rotation to use (-1 none)
	    	false,			// Double size if rotating
	    	hide,			// Hide this sprite
	    	flip, false,	// Horizontal or vertical flip
	    	false			// Mosaic
	    	);

    swiWaitForVBlank();

}

void sprite_update()
{
	//Update the sprites
	oamUpdate(&oamMain);
}
