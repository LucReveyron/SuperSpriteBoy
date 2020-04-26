/*
 * P_Audio.h
 *
 *  Created on: Dec 19, 2019
 *  Author: Simón Prêcheur Llarena
 *
 *  Module dedicated to sound.
 *  Original music composed by Simón Prêcheur Llarena
 *
 */

#ifndef P_AUDIO_H_
#define P_AUDIO_H_

#include <nds.h>
#include <maxmod9.h>
#include "soundbank.h"
#include "soundbank_bin.h"

void Audio_Init();
void Audio_PlaySoundEX(int i);
void Audio_PlayMusic(int i);

#endif /* P_AUDIO_H_ */
