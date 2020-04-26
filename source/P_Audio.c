/*
 * P_Audio.c
 *
 *  Created on: Dec 19, 2019
 *  Author: Simón Prêcheur Llarena
 *
 *  Module dedicated to sound.
 *  Original music composed by Simón Prêcheur Llarena
 *
 */

#include "P_Audio.h"

void Audio_Init()
{
	//Init the sound library
	mmInitDefaultMem((mm_addr)soundbank_bin);
	//Load module
	mmLoad(MOD_DS1);
	mmLoad(MOD_DS2);
	mmLoad(MOD_DS4);
	mmLoad(MOD_DS5);
	mmLoad(MOD_DS6);
	mmLoad(MOD_START);
	mmLoad(MOD_QUIT);
	mmLoad(MOD_GAMEOVER);
	mmLoad(MOD_VICTORY);
	//Load effect
	mmLoadEffect(SFX_STARTFX);
	mmLoadEffect(SFX_QUITFX);
	mmLoadEffect(SFX_JUMPFX);
	mmLoadEffect(SFX_FALLFX);
	mmLoadEffect(SFX_OBSTACLEFX);
}

void Audio_PlaySoundEX(int i)
{
	//Declare a sound effect
	mm_sound_effect sound;
	//Set the id of the sound effect with the input parameter
	sound.id = i;
	//Set the rate to the default one (1024)
	sound.rate = 1024;
	//Set the volume to the maximum (range 0...255)
	sound.volume = 255;
	//Set the panning depending on the effect (0-left....255-right)
	sound.panning = 128;

	//Play the effect using the sound structure
	mmEffectEx(&sound);
}


void Audio_PlayMusic(int i)
{
	//Start playing back xm file
	if (i == MOD_DS1)
		mmStart(MOD_DS1, MM_PLAY_LOOP);
	if (i == MOD_DS2)
		mmStart(MOD_DS2, MM_PLAY_LOOP);
	if (i == MOD_DS4)
		mmStart(MOD_DS4, MM_PLAY_LOOP);
	if (i == MOD_DS5)
		mmStart(MOD_DS5, MM_PLAY_LOOP);
	if (i == MOD_DS6)
		mmStart(MOD_DS6, MM_PLAY_LOOP);
	if (i == MOD_QUIT)
		mmStart(MOD_QUIT, MM_PLAY_ONCE);
	if (i == MOD_START)
		mmStart(MOD_START, MM_PLAY_ONCE);
	if (i == MOD_GAMEOVER)
		mmStart(MOD_GAMEOVER, MM_PLAY_ONCE);
	if (i == MOD_VICTORY)
		mmStart(MOD_VICTORY, MM_PLAY_ONCE);

	//Set module volume to 512 (range 0...1024) using the function mmSetVolume(...)
	mmSetModuleVolume(512);
}

