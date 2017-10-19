#include "stdafx.h"
#include "SceneMgr.h"

SceneMgr::SceneMgr() {}
SceneMgr::~SceneMgr() {}
void SceneMgr::Checking() {
	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			if (i == j)
				continue;
			if (
				(obj[i].GetY() + BREAK > obj[j].GetY()) && (obj[i].GetY() - BREAK < obj[j].GetY())
				)
			{
				if (
					(obj[i].GetX() + BREAK > obj[j].GetX()) && (obj[i].GetX() - BREAK < obj[j].GetX())
					)
				{
					if (obj[i].GetMod() == 1)
						obj[i].SetMod(2);
					else
						obj[i].SetMod(1);
				}
			}
			else if(
				(obj[i].GetX() + BREAK > obj[j].GetX())&& (obj[i].GetX() - BREAK < obj[j].GetX())
				)
			{
				if (
					(obj[i].GetY() + BREAK > obj[j].GetY()) && (obj[i].GetY() - BREAK < obj[j].GetY())
					)
				{
					if (obj[i].GetMod() == 1)
						obj[i].SetMod(2);
					else
						obj[i].SetMod(1);
				}
			}
		}
	}
}

void SceneMgr::Rendering(Renderer *g_Renderer, int n) {
	if (n >= MAX)
		n = MAX;
	for (int i = 0;i<n;++i)
	{
		obj[i].Update();
		obj[i].Draw(g_Renderer);
	}
}
void SceneMgr::SceneSet(int n, float x, float y, float z, float size, float r, float g, float b, float a, float vx, float vy, int  mod) 
{
	if (n >= MAX)
		n = n%MAX;
	obj[n].Set(x,y,z,size,r,g,b,a,vx,vy,mod); }