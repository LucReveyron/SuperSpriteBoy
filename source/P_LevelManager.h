/*
Title: P_LevelManager.h
Version: 1.0
Author: Luc Reveyron
Description: All the functions to define level functionnality
*/

#ifndef P_LEVELMANAGER_H_
#define P_LEVELMANAGER_H_

void menu();
void wait_music();
void wait_forest();
void forest_level();
void wait_castle();
void castle_level();
void wait_boss();
void boss_level();
void victory();
void gameover();
void debug();

void level_activity(int level);



#endif /* P_LEVELMANAGER_H_ */
