
/*
Title: P_TopScreen.h
Version: 1.0
Author: Luc Reveyron
Description: Initialisation and refresh functions for top screen
*/
#pragma once

#include <nds.h>

#ifndef P_TOPSCREEN_H_
#define P_TOPSCREEN_H_

void main_screen_setup();

void load_background(int level);

int horizontal_scroll_background(int* bgScrollx,int inc);

void cloud_scroll();

void test_map_scroll();

#endif /* P_TOPSCREEN_H_ */
