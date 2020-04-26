/*
Title: P_SubScreen.c
Version: 1.0
Author: Luc Reveyron
Description: Initialisation and refresh functions for bottom screen
*/
#include "P_SubScreen.h"
#include "BgOn.h"
#include "buttonStart.h"
#include "buttonQuit.h"
#include "P_definitions.h"

void sub_screen_setup()
{
	//Enable a proper RAM memory bank for sub engine
	VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG;

	//Configure the sub engine in mode 5 (2D) and activate Background 2
	REG_DISPCNT_SUB = MODE_5_2D | DISPLAY_BG2_ACTIVE;

}

void load_sub_background(int Statue)
{

	BGCTRL_SUB[2] = BG_BMP_BASE(0) | BG_BMP8_256x256;

    if(Statue == NO_BUTTON)
    {
        dmaCopy(BgOnBitmap,BG_GFX_SUB,BgOnBitmapLen);
        dmaCopy(BgOnPal, BG_PALETTE_SUB, BgOnPalLen);
    }
    else if(Statue == QUIT)
    {
	    dmaCopy(buttonQuitBitmap,BG_GFX_SUB,buttonQuitBitmapLen);
	    dmaCopy(buttonQuitPal, BG_PALETTE_SUB, buttonQuitPalLen);
    }
    else if(Statue == START)
    {
	    dmaCopy(buttonStartBitmap,BG_GFX_SUB,buttonStartBitmapLen);
	    dmaCopy(buttonStartPal, BG_PALETTE_SUB, buttonStartPalLen);
    }

    //Affine Marix Transformation
    REG_BG2PA_SUB = 256;
    REG_BG2PC_SUB = 0;
    REG_BG2PB_SUB = 0;
    REG_BG2PD_SUB = 256;

}

