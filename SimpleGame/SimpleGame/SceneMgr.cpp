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
					check[i] = 1;
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
					check[i] = 1;
				}
			}
		}
	}
}
void SceneMgr::Moding()
{
	for (int i = 0; i < MAX; ++i)
		if (check[i]) 
		{
			if (obj[i].GetMod() == 1)
				obj[i].SetMod(2);
			//else if (obj[i].GetMod() == 2)
			//	obj[i].SetMod(3);
			//else if (obj[i].GetMod() == 3)
			//	obj[i].SetMod(4);
			//else if (obj[i].GetMod() == 4)
			//	obj[i].SetMod(5);
			else
				obj[i].SetMod(1);
			check[i] = 0;
			obj[i].SetLife(obj[i].GetLife() - 1);
		}
}

void SceneMgr::Rendering(int n)
{
	if (n >= MAX)
		n = MAX;
	for (int i = 0;i<n;++i)
	{
		obj[i].Update(10.0);
		obj[i].Draw(g_Renderer);
	}
}
void SceneMgr::SceneSet(int n, float x, float y, float z, float size, float r, float g, float b, float a, float vx, float vy, int  mod) 
{
	if (n >= MAX)
		n = n%MAX;
	obj[n].Set(x,y,z,size,r,g,b,a,vx,vy,mod); 
}
void SceneMgr::Rising()
{
	g_Renderer = new Renderer(500, 500);
}