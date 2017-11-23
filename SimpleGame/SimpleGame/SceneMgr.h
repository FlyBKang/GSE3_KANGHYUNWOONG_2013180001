#pragma once
#include "stdafx.h"
#include "Object.h"
#include "Renderer.h"

using namespace std;

class SceneMgr
{
	GLuint Building_texCharacter1;
	GLuint Building_texCharacter2;
	Renderer *g_Renderer;
	bool check[MAX];
	Object obj[MAX];
public:
	SceneMgr();
	~SceneMgr();
	void SceneSet(int n, float x, float y, float z, float size, float r, float g, float b, float a, float vx, float vy, int l, int lt, int  mod,int t,float le);
	void Checking();
	int Moding(int n);
	void Rendering(int n);
	void Rising();
	void Ending();
	void TextureMaping();
};