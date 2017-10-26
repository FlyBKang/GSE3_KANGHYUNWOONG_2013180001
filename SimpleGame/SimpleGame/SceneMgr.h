#pragma once
#include "stdafx.h"
#include "Object.h"
#include "Renderer.h"
#define MAX 10
#define BREAK 10
#define TIME 10.0

class SceneMgr
{
	Renderer *g_Renderer;
	bool check[MAX];
	Object obj[MAX];
public:
	SceneMgr();
	~SceneMgr();
	void SceneSet(int n, float x, float y, float z, float size, float r, float g, float b, float a, float vx, float vy, int  mod);
	void Checking();
	void Moding();
	void Rendering(int n);
	void Rising();
};