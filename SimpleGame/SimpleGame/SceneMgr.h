#pragma once
#include "stdafx.h"
#include "Object.h"
#include "Renderer.h"
#include "Sound.h"

using namespace std;

class SceneMgr
{
	Sound *m_sound = new Sound();
	Renderer *g_Renderer;
	GLuint Building_texCharacter1;
	GLuint Building_texCharacter2;
	GLuint Background_texCharacter;
	GLuint char_texCharacter;
	GLuint particle_texCharacter;
	bool check[MAX];
	Object obj[MAX];
	float time = 0.0f;
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
	int ShotBullet(int cnt)
	{
		for (int i = 0; i < MAX; ++i)
		{
			if (obj[i].GetMod() == 4 && obj[i].GetLife() > 0)
			{
				SceneSet(cnt, obj[i].GetX(), obj[i].GetY(),0, OBJECT_BULLET, obj[i].GetTeam(), LEVEL_SKY);
				++cnt;
			}
		}
		return cnt;
	}
};