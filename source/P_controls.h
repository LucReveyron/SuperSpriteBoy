/*
Title: P_controls.h
Version: 1.0
Author: Simón Prêcheur Llarena and Luc Reveyron
Description: All the controls
*/

#ifndef P_CONTROLS_H_
#define P_CONTROLS_H_

#include <nds.h>

void control_check_held_keys();

int control_check_sub_button(); // Polling touchScreen, refresh button statue and actions

#endif /* P_CONTROLS_H_ */
