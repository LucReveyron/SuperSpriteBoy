/*
Title: P_TopScreen.c
Version: 1.0
Author: Luc Reveyron
Description: Initialisation and refresh functions for top screen
*/

#include "P_TopScreen.h"
#include "maskbg1.h"
#include "bgforest.h"
#include "bgCastle.h"
#include "bgCastle1.h"
#include "bgCastle2.h"
#include "bgCastle3.h"
#include "bgMenu.h"
#include "bgSky.h"
#include "bgCloud.h"
#include "ForestScreen.h"
#include "CastleScreen.h"
#include "BossScreen.h"
#include "bgBoss1.h"
#include "bgBoss2.h"
#include "bgBoss3.h"
#include "BackCastle.h"
#include "bgGameOver.h"
#include "bgvictory.h"
#include "P_definitions.h"

static int compt;// for boss room and castle animations

void main_screen_setup()
{
	//Enable a proper RAM memory bank for the main engine
	VRAM_A_CR = VRAM_ENABLE //Enable
			| VRAM_A_MAIN_BG; //Bank for the main engine

	//Configure the main engine in mode 5 (2D) and activate Background 0
	REG_DISPCNT = MODE_0_2D | DISPLAY_BG0_ACTIVE| DISPLAY_BG1_ACTIVE | DISPLAY_BG2_ACTIVE;

}

void load_background(int level)
{
	if(level == FOREST){
		BGCTRL[0] = BG_COLOR_256 | BG_MAP_BASE(0) |BG_TILE_BASE(1) | BG_64x64;
		dmaCopy(bgforestTiles,BG_TILE_RAM(1),bgforestTilesLen); // Copy tiles
		dmaCopy(bgforestPal,BG_PALETTE,bgforestPalLen); // Copy palette
		//Copy MainMap
		int i;

		// TOP LEFT quadrant of the image in first map base
		for(i=0; i<32; i++)
			dmaCopy(&bgforestMap[i*64], &BG_MAP_RAM(0)[i*32], 64);

		// TOP RIGHT quadrant of the image in second map base
		for(i=0; i<32; i++)
			dmaCopy(&bgforestMap[i*64+32], &BG_MAP_RAM(1)[i*32], 64);

		// BOTTOM LEFT quadrant of the image in fourth map base
		for(i=0; i<32; i++)
				dmaCopy(&bgforestMap[(i+40)*64], &BG_MAP_RAM(2)[i*32], 64);

		// BOTTOM RIGHT quadrant of the image in fourth map base
		for(i=0; i<32; i++)
			dmaCopy(&bgforestMap[(i+40)*64+32], &BG_MAP_RAM(3)[i*32], 64);


		// Cloud Background
		BGCTRL[1] = BG_COLOR_256 | BG_MAP_BASE(5) | BG_TILE_BASE(4) | BG_32x32;
		dmaCopy(bgCloudTiles,BG_TILE_RAM(4),bgCloudTilesLen); // Copy tiles
		dmaCopy(bgCloudPal,&BG_PALETTE[131],bgCloudPalLen); // Copy palette
		dmaCopy(bgCloudMap, BG_MAP_RAM(5), bgCloudMapLen);

		// Sky Background

		BGCTRL[2] = BG_COLOR_256 | BG_MAP_BASE(26) | BG_TILE_BASE(7) | BG_32x32;
		dmaCopy(bgSkyTiles,BG_TILE_RAM(7),bgSkyTilesLen); // Copy tiles
		dmaCopy(bgSkyPal,&BG_PALETTE[65],bgSkyPalLen); // Copy palette
		dmaCopy(bgSkyMap, BG_MAP_RAM(26), bgSkyMapLen);

		REG_BG0HOFS = 0;
		videoBgEnable(1);

	}
	else if(level == CASTLE){

		int i;

		BGCTRL[0] = BG_COLOR_256 | BG_MAP_BASE(0) |BG_TILE_BASE(1) | BG_64x64;
		dmaCopy(bgCastleTiles,BG_TILE_RAM(1),bgCastleTilesLen); // Copy tiles
		dmaCopy(bgCastlePal,BG_PALETTE,bgCastlePalLen); // Copy palette
		//Copy Map

		// TOP LEFT quadrant of the image in first map base
		for(i=0; i<32; i++)
			dmaCopy(&bgCastleMap[i*64], &BG_MAP_RAM(0)[i*32], 64);

		// TOP RIGHT quadrant of the image in second map base
		for(i=0; i<32; i++)
			dmaCopy(&bgCastleMap[i*64+32], &BG_MAP_RAM(1)[i*32], 64);

		// BOTTOM LEFT quadrant of the image in fourth map base
		for(i=0; i<32; i++)
			dmaCopy(&bgCastleMap[(i+40)*64], &BG_MAP_RAM(2)[i*32], 64);

		// BOTTOM RIGHT quadrant of the image in fourth map base
		for(i=0; i<32; i++)
			dmaCopy(&bgCastleMap[(i+40)*64+32], &BG_MAP_RAM(3)[i*32], 64);

		//Wall Background
		BGCTRL[2] = BG_COLOR_256 | BG_MAP_BASE(26) | BG_TILE_BASE(7) | BG_32x32;
		dmaCopy(BackCastleTiles,BG_TILE_RAM(7),BackCastleTilesLen); // Copy tiles
		dmaCopy(BackCastlePal,&BG_PALETTE[65],BackCastlePalLen); // Copy palette
		dmaCopy(BackCastleMap, BG_MAP_RAM(26), BackCastleMapLen);

		videoBgDisable(1);

		REG_BG0HOFS = 0;
		REG_BG0VOFS = 255;
	}
	else if(level == BOSS)
	{
		compt++;
		switch ((compt/6)% 3)
		{
			case 0:
				BGCTRL[0] = BG_COLOR_256 | BG_MAP_BASE(0) |BG_TILE_BASE(1) | BG_64x64;
				dmaCopy(bgBoss1Tiles,BG_TILE_RAM(1),bgBoss1TilesLen); // Copy tiles
				dmaCopy(bgBoss1Pal,BG_PALETTE,bgBoss1PalLen); // Copy palette

				dmaCopy(bgBoss1Map,BG_MAP_RAM(0),bgBoss1MapLen);
				REG_BG0HOFS = 0;
				REG_BG0VOFS = 0;
				break;

			case 1:
				BGCTRL[0] = BG_COLOR_256 | BG_MAP_BASE(0) |BG_TILE_BASE(1) | BG_64x64;
				dmaCopy(bgBoss2Tiles,BG_TILE_RAM(1),bgBoss2TilesLen); // Copy tiles
				dmaCopy(bgBoss2Pal,BG_PALETTE,bgBoss2PalLen); // Copy palette

				dmaCopy(bgBoss2Map,BG_MAP_RAM(0),bgBoss2MapLen);
				REG_BG0HOFS = 0;
				REG_BG0VOFS = 0;
				break;

			case 2:
				BGCTRL[0] = BG_COLOR_256 | BG_MAP_BASE(0) |BG_TILE_BASE(1) | BG_64x64;
				dmaCopy(bgBoss3Tiles,BG_TILE_RAM(1),bgBoss3TilesLen); // Copy tiles
				dmaCopy(bgBoss3Pal,BG_PALETTE,bgBoss3PalLen); // Copy palette

				dmaCopy(bgBoss3Map,BG_MAP_RAM(0),bgBoss3MapLen);
				REG_BG0HOFS = 0;
				REG_BG0VOFS = 0;
				break;
		}
	}
	else if(level == WAIT_BOSS)
	{
		BGCTRL[0] = BG_COLOR_256 | BG_MAP_BASE(0) |BG_TILE_BASE(1) | BG_64x64;
		dmaCopy(BossScreenTiles,BG_TILE_RAM(1),BossScreenTilesLen); // Copy tiles
		dmaCopy(BossScreenPal,BG_PALETTE,BossScreenPalLen); // Copy palette

		dmaCopy(BossScreenMap,BG_MAP_RAM(0),BossScreenMapLen);
		REG_BG0HOFS = 0;
		REG_BG0VOFS = 0;

		compt = 0;
	}
	else if(level == MENU)
	{
		BGCTRL[0] = BG_COLOR_256 | BG_MAP_BASE(0) |BG_TILE_BASE(1) | BG_64x64;
		dmaCopy(bgMenuTiles,BG_TILE_RAM(1),bgMenuTilesLen); // Copy tiles
		dmaCopy(bgMenuPal,BG_PALETTE,bgMenuPalLen); // Copy palette

		dmaCopy(bgMenuMap,BG_MAP_RAM(0),bgMenuMapLen);
		REG_BG0HOFS = 0;
		REG_BG0VOFS = 0;
	}
	else if(level == GAMEOVER)
	{
		BGCTRL[0] = BG_COLOR_256 | BG_MAP_BASE(0) |BG_TILE_BASE(1) | BG_64x64;
		dmaCopy(bgGameOverTiles,BG_TILE_RAM(1),bgGameOverTilesLen); // Copy tiles
		dmaCopy(bgGameOverPal,BG_PALETTE,bgGameOverPalLen); // Copy palette

		dmaCopy(bgGameOverMap,BG_MAP_RAM(0),bgGameOverMapLen);
		REG_BG0HOFS = 0;
		REG_BG0VOFS = 0;
	}
	else if(level == WAIT_FOREST)
	{
		BGCTRL[0] = BG_COLOR_256 | BG_MAP_BASE(0) |BG_TILE_BASE(1) | BG_64x64;
		dmaCopy(ForestScreenTiles,BG_TILE_RAM(1),ForestScreenTilesLen); // Copy tiles
		dmaCopy(ForestScreenPal,BG_PALETTE,ForestScreenPalLen); // Copy palette

		dmaCopy(ForestScreenMap,BG_MAP_RAM(0),ForestScreenMapLen);
		REG_BG0HOFS = 0;
		REG_BG0VOFS = 0;

	}
	else if(level == WAIT_CASTLE)
	{
		compt = 0;
		BGCTRL[0] = BG_COLOR_256 | BG_MAP_BASE(0) |BG_TILE_BASE(1) | BG_64x64;
		dmaCopy(CastleScreenTiles,BG_TILE_RAM(1),CastleScreenTilesLen); // Copy tiles
		dmaCopy(CastleScreenPal,BG_PALETTE,CastleScreenPalLen); // Copy palette

		dmaCopy(CastleScreenMap,BG_MAP_RAM(0),CastleScreenMapLen);
		REG_BG0HOFS = 0;
		REG_BG0VOFS = 0;
	}

	else if(level == VICTORY)
	{
		BGCTRL[0] = BG_COLOR_256 | BG_MAP_BASE(0) |BG_TILE_BASE(1) | BG_64x64;
		dmaCopy(bgvictoryTiles,BG_TILE_RAM(1),bgvictoryTilesLen); // Copy tiles
		dmaCopy(bgvictoryPal,BG_PALETTE,bgvictoryPalLen); // Copy palette

		dmaCopy(bgvictoryMap,BG_MAP_RAM(0),bgvictoryMapLen);
		REG_BG0HOFS = 0;
		REG_BG0VOFS = 0;
	}

}

int horizontal_scroll_background(int* bgScrollx,int inc)
{
	*bgScrollx += inc;

	REG_BG0HOFS = *bgScrollx;
	swiWaitForVBlank();
	return SCROLL_ON;
}

void cloud_scroll()
{
	REG_BG1HOFS += 0.5*SCROLLING_SPEED;
}

//Use for debug

void test_map_scroll()
{
	int i;
	//shifting horizontally from left to right
	for(i=0; i<=512-256; i++){
		swiWaitForVBlank();
		REG_BG0HOFS = i;
	}
	//shifting vertically from up to down
	for(i=0; i<=512-192; i++){
		swiWaitForVBlank();
		REG_BG0VOFS = i;
	}
	//shifting horizontally from right to left
	for(i=512-256; i>=0; i--){
		swiWaitForVBlank();
		REG_BG0HOFS = i;
	}
	//shifting vertically from down to up
	for(i=512-192; i>=0; i--){
		swiWaitForVBlank();
		REG_BG0VOFS = i;
	}
}

