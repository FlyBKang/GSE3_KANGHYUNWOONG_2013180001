#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#define COLOR 0.0039215
#define SPEED 0.0075
#define RANDOM (rand()%6 - 2.5)
#define OBJECT_BUILDING  100, 0, 0, 0, 1,0, 0, 500, 1000000, 4
#define OBJECT_CHARACTER  5, 0, 0, 0, 0,RANDOM * SPEED * 300,RANDOM * SPEED * 300 ,10,100000 , 1
#define OBJECT_BULLET  5, 1, 0, 0, 1, RANDOM * SPEED * 600,RANDOM * SPEED * 600, 20, 100000, 0
#define OBJECT_ARROW  5, 0, 0, 0, 1, RANDOM * SPEED * 100, RANDOM * SPEED * 100, 10, 100000, 6

#define MAX 1000
#define TIME 10

