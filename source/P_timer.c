/*
Title: P_timer.c
Version: 1.0
Author: Luc Reveyron
Description: Function to define the duration of the transition between two levels.
*/

#include "P_timer.h"
#include "P_TopScreen.h"
#include "P_LevelManager.h"
#include "P_definitions.h"

static int timer_ticks;

static int finishTransition;

void timerISR() {
	//Every 1.0 seconds this ISR
	timer_ticks++;
	if (level_global == BOSS)
	{
		if (timer_ticks == 200)
		{
			level_global = VICTORY;
			irqDisable(IRQ_TIMER0);
				timer_ticks = 0;
		}
	}
	if(timer_ticks == 7){
		if(level_global == FOREST)
			forest_level();
		if(level_global == CASTLE)
			castle_level();

		irqDisable(IRQ_TIMER0);
		timer_ticks = 0;
		finishTransition = 1;
	}



}

void init_timer()
{
	finishTransition = 0;

	// Initialize timer_ticks
	timer_ticks = 0;

	// Configure timer to trigger an interrupt every 125 ms
	TIMER_CR(0) = TIMER_ENABLE | TIMER_DIV_1024 | TIMER_IRQ_REQ;

	TIMER_DATA(0) = TIMER_FREQ_1024(8);
	// Associate the ISR (timerISR) to the interrupt line and enable it
	irqSet(IRQ_TIMER0, &timerISR);
	irqEnable(IRQ_TIMER0);
}

void freeze_frame();

void level_transition()
{
	init_timer();
	if(level_global == FOREST)
		wait_forest();
	else if(level_global == CASTLE)
		wait_castle();
	else if(level_global == BOSS)
		wait_boss();
	else if(level_global == GAMEOVER)
		gameover();
	else if(level_global == VICTORY)
		victory();
}

int transition_statue()
{
	return finishTransition;
}


