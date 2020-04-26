/*
Title: P_SpriteAnimation.h
Version: 1.0
Author: Luc Reveyron
Description: Function for refresh the differents sprite.
*/
#include <nds.h>
#include <stdio.h>

#ifndef P_SPRITEANIMATION_H_
#define P_SPRITEANIMATION_H_

void init_sprite_graphic();

// loads the corresponding animation frame
void refresh_character_sprite(int platformState, int step);

void refresh_ennemy_sprite();

// displays it at given coordinates
void refresh_sprite_position(int type, int x, int y, bool flip, bool hide);

// basically just calls oamUpdate
void sprite_update();

#endif /* P_SPRITEANIMATION_H_ */
