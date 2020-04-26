/*
Title: P_timer.h
Version: 1.0
Author: Luc Reveyron
Description: Function to define the duration of the transition between two levels.
*/

#ifndef TIMER_H_
#define TIMER_H_

void timerISR();

void init_timer();

void level_transition();

int transition_statue();


#endif /* TIMER_H_ */
