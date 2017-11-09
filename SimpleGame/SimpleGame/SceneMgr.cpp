#include "stdafx.h"
#include "SceneMgr.h"




SceneMgr::SceneMgr() {}
SceneMgr::~SceneMgr() {}
void SceneMgr::Checking() {
	for (int i = 0; i < MAX; ++i)
	{
		if(obj[i].GetLife()>0)
		for (int j = 0; j < MAX; ++j)
		{
			if (i == j)
				continue;

			if ((obj[i].GetLife()>0&& obj[j].GetLife()>0) && (obj[i].GetTime()>0 && obj[j].GetTime()>0))
				if (
					(obj[i].GetY() + BREAK > obj[j].GetY()) && (obj[i].GetY() - BREAK < obj[j].GetY())
					)
				{
					if (
						(obj[i].GetX() + BREAK > obj[j].GetX()) && (obj[i].GetX() - BREAK < obj[j].GetX())
						)
					{
						if (obj[i].GetMod() == 1 && obj[j].GetMod() == 4)
						{
							obj[j].SetLife(obj[j].GetLife() - obj[i].GetLife());
							obj[i].SetLife(0);
							cout << "ºôµù HP" << obj[j].GetLife() << endl;
						}
						if (obj[i].GetMod() == 0 && obj[j].GetMod() == 1)
						{
							obj[j].SetLife(obj[j].GetLife() - obj[i].GetLife());
							obj[i].SetLife(0);
						}
						if (obj[i].GetMod() == 6 && obj[j].GetMod() == 1)
						{
							if (obj[i].GetArrow() != j)
							{
								obj[j].SetLife(obj[j].GetLife() - obj[i].GetLife());
								obj[i].SetLife(0);
								cout << "arrow" << endl;
							}
						}
						if (obj[i].GetMod() == 6 && obj[j].GetMod() == 4)
						{
							obj[j].SetLife(obj[j].GetLife() - obj[i].GetLife());
							obj[i].SetLife(0);
							cout << "ºôµù HP" << obj[j].GetLife() << endl;
						}
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
						if (obj[i].GetMod() == 1 && obj[j].GetMod() == 4)
						{
							obj[j].SetLife(obj[j].GetLife() - obj[i].GetLife());
							obj[i].SetLife(0);
							cout << "ºôµù HP"<<obj[j].GetLife() << endl;
						}
						if (obj[i].GetMod() == 0 && obj[j].GetMod() == 1)
						{
							obj[j].SetLife(obj[j].GetLife() - obj[i].GetLife());
							obj[i].SetLife(0);
						}
						if (obj[i].GetMod() == 6 && obj[j].GetMod() == 1)
						{
							if (obj[i].GetArrow()!=j)
							{ 
								obj[j].SetLife(obj[j].GetLife() - obj[i].GetLife());
								obj[i].SetLife(0);

								cout << "arrow" << endl;
							}
						}
						if (obj[i].GetMod() == 6 && obj[j].GetMod() == 4)
						{
							obj[j].SetLife(obj[j].GetLife() - obj[i].GetLife());
							obj[i].SetLife(0);
						}
					}
				}
		}
	}
}
int SceneMgr::Moding(int n)
{
	for (int i = 0; i < MAX; ++i)
		if (obj[i].GetMod() == 1&& obj[i].GetLife() >0 && obj[i].GetTime() >0)
		{
			n++;
			SceneSet(n, obj[i].GetX(), obj[i].GetY(),0, OBJECT_ARROW);
			obj[n].SetArrow(i);
		}
	n++;
	return n;
}

void SceneMgr::Rendering(int n)
{
	if (n >= MAX)
		n = MAX;
	for (int i = 0;i<n;++i)
	{
		obj[i].Update(10.0);
		obj[i].Draw(g_Renderer, m_texCharacter);
	}
}
void SceneMgr::SceneSet(int n, float x, float y, float z, float size, float r, float g, float b, float a, float vx, float vy, int l, int lt, int  mod) 
{
	if (n >= MAX)
		n = n%MAX;
	obj[n].Set(x,y,z,size,r,g,b,a,vx,vy,l,lt,mod); 
}
void SceneMgr::Rising()
{
	g_Renderer = new Renderer(500, 500);
}
void SceneMgr::Ending()
{
	delete(g_Renderer);
}