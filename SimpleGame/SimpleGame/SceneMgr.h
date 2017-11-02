#pragma once
#include "stdafx.h"
#include "Object.h"
#include "Renderer.h"
#define SPEED 0.0075
#define RANDOM (rand()%4 - 1.5)
#define OBJECT_BUILDING  8, 0, 0, 0, 0,0, 0, 500, 1000000, 4
#define OBJECT_CHARACTER  5, 0, 0, 0, 0,RANDOM * SPEED * 300,RANDOM * SPEED * 300 ,10,100000 , 1
#define OBJECT_BULLET  5, 1, 0, 0, 0, RANDOM * SPEED * 600,RANDOM * SPEED * 600, 20, 100000, 0
#define OBJECT_ARROW  5, 0, 0, 0, 0, RANDOM * SPEED * 100, RANDOM * SPEED * 100, 10, 100000, 6

#define MAX 1000
#define BREAK 15
#define TIME 10.0

class SceneMgr
{
	Renderer *g_Renderer;
	bool check[MAX];
	Object obj[MAX];
public:
	SceneMgr();
	~SceneMgr();
	void SceneSet(int n, float x, float y, float z, float size, float r, float g, float b, float a, float vx, float vy, int l, int lt, int  mod);
	void Checking();
	void Moding();
	void Rendering(int n);
	void Rising();
	void Ending();
};