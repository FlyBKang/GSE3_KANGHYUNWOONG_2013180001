#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#define Horizontal 500
#define Vertical 800

#define BUILDING_LIFE 500
#define PLAYER_LIFE 100
#define COLOR 0.0039215
#define SPEED 0.0050
#define RANDOM (rand()%6 - 2.5)
#define OBJECT_BUILDING  100, 1,1,1, 1,0, 0, BUILDING_LIFE, 1000000, 4
#define OBJECT_CHARACTER  30, 1, 1, 0, 1,RANDOM * SPEED * 300,RANDOM * SPEED * 300 ,PLAYER_LIFE ,100000 , 1
#define OBJECT_BULLET  4, 1, 0, 0, 1, RANDOM * SPEED * 600,RANDOM * SPEED * 600, 15, 100000, 0
#define OBJECT_ARROW  4, 0, 1, 0, 1, RANDOM * SPEED * 100, RANDOM * SPEED * 100, 10, 100000, 6

#define T1B1 -150,-300,0
#define T1B2 0,-300,0
#define T1B3 150,-300,0

#define T2B1 -150,300,0 
#define T2B2  0,300,0
#define T2B3 150,300,0

#define MAX 5000
#define TIME 10

#define LEVEL_GOD 0
#define LEVEL_SKY 0.1
#define LEVEL_GROUND 0.2
#define LEVEL_UNDERGROUND 0.3

#define TIMER_BULLET 200
#define TIMER_ARROW 150
#define TIMER_PLAYERCOOL 700
#define TIMER_ENEMYPLAYER 500

#define GAGE_SPACE 5

