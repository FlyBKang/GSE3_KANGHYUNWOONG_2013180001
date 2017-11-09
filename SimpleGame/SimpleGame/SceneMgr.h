#pragma once
#include "stdafx.h"
#include "Object.h"
#include "Renderer.h"
#include "LoadPng.h"
#define SPEED 0.0075
#define RANDOM (rand()%6 - 2.5)
#define OBJECT_BUILDING  40, 0, 0, 0, 1,0, 0, 500, 1000000, 4
#define OBJECT_CHARACTER  5, 0, 0, 0, 0,RANDOM * SPEED * 300,RANDOM * SPEED * 300 ,10,100000 , 1
#define OBJECT_BULLET  5, 1, 0, 0, 1, RANDOM * SPEED * 600,RANDOM * SPEED * 600, 20, 100000, 0
#define OBJECT_ARROW  5, 0, 0, 0, 1, RANDOM * SPEED * 100, RANDOM * SPEED * 100, 10, 100000, 6

#define MAX 1000
#define BREAK 15
#define TIME 10
using namespace std;

class SceneMgr
{
	Renderer *g_Renderer;
	GLuint m_texCharacter = g_Renderer->CreatePngTexture("Textures/texture1.png");;
	bool check[MAX];
	Object obj[MAX];
public:
	SceneMgr();
	~SceneMgr();
	void SceneSet(int n, float x, float y, float z, float size, float r, float g, float b, float a, float vx, float vy, int l, int lt, int  mod);
	void Checking();
	int Moding(int n);
	void Rendering(int n);
	void Rising();
	void Ending();
};