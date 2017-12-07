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
			if(obj[i].GetTeam() == obj[j].GetTeam())
				continue;
			if ((obj[i].GetLife()>0&& obj[j].GetLife()>0) && (obj[i].GetTime()>0 && obj[j].GetTime()>0))
				if (
					(obj[i].GetY() + (obj[i].GetSize()/2) > obj[j].GetY()) && (obj[i].GetY() - (obj[i].GetSize() / 2) < obj[j].GetY())
					)
				{
					if (
						(obj[i].GetX() + (obj[i].GetSize() / 2) > obj[j].GetX()) && (obj[i].GetX() - (obj[i].GetSize() / 2) < obj[j].GetX())
						)
					{
						if (obj[i].GetMod() == 4 && obj[j].GetMod() == 1)
						{
							obj[i].SetLife(obj[i].GetLife() - obj[j].GetLife());
							obj[j].SetLife(0);
							if (i<3)
								cout << "Team" << obj[i].GetTeam() << " "<<i + 1 << "網註 HP" << obj[i].GetLife() << endl;
							else
								cout << "Team" << obj[i].GetTeam() <<" "<< i - 2 << "網註 HP" << obj[i].GetLife() << endl;
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
							}
						}
						if (obj[i].GetMod() == 4 && obj[j].GetMod() == 6)
						{
							obj[i].SetLife(obj[i].GetLife() - obj[j].GetLife());
							obj[j].SetLife(0);
							if (i<3)
								cout << "Team" << obj[i].GetTeam() << " " << i + 1 << "網註 HP" << obj[i].GetLife() << endl;
							else
								cout << "Team" << obj[i].GetTeam() << " " << i - 2 << "網註 HP" << obj[i].GetLife() << endl;
						}
						if (obj[i].GetMod() == 4 && obj[j].GetMod() == 0)
						{
							obj[i].SetLife(obj[i].GetLife() - obj[j].GetLife());
							obj[j].SetLife(0);
							if (i<3)
								cout<< "Team" << obj[i].GetTeam() << " " << i + 1 << "網註 HP" << obj[i].GetLife() << endl;
							else
								cout<< "Team" << obj[i].GetTeam() << " " << i - 2 << "網註 HP" << obj[i].GetLife() << endl;
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
			SceneSet(n, obj[i].GetX(), obj[i].GetY(),0, OBJECT_ARROW,obj[i].GetTeam(),LEVEL_SKY);
			obj[n].SetArrow(i);
		}
	n++;
	return n;
}
void SceneMgr::Rendering(int n)
{
	g_Renderer->DrawTexturedRect(0, 0, 0, 800, 1, 1, 1, 1, Background_texCharacter, 0.99);
	if (n >= MAX)
		n = MAX;
	for (int i = 0;i<n;++i)
	{
		obj[i].Update(10.0);
		obj[i].Draw(g_Renderer);
	}
}
void SceneMgr::SceneSet(int n, float x, float y, float z, float size, float r, float g, float b, float a, float vx, float vy, int l, int lt, int  mod,int t,float le) 
{
	if (n >= MAX)
		n = n%MAX;
	obj[n].Set(x, y, z, size, r, g, b, a, vx, vy, l, lt, mod, t, le);
	if (mod == 4)
		if(obj[n].GetTeam() == 1)
			obj[n].SetTexture(Building_texCharacter1);
		else
			obj[n].SetTexture(Building_texCharacter2);
	if(mod == 1)
		obj[n].SetTexture(char_texCharacter); 
	if (mod == 0)
		obj[n].SetTexture(particle_texCharacter);

}
void SceneMgr::Rising()
{
	g_Renderer = new Renderer(Horizontal, Vertical);
}
void SceneMgr::Ending()
{
	delete(g_Renderer);
}

void  SceneMgr::TextureMaping()
{
	Background_texCharacter = g_Renderer->CreatePngTexture("Textures/background.png");
	char_texCharacter = g_Renderer->CreatePngTexture("Textures/animation.png");
	Building_texCharacter1 = g_Renderer->CreatePngTexture("Textures/texture2.png");
	Building_texCharacter2 = g_Renderer->CreatePngTexture("Textures/texture1.png");
	particle_texCharacter = g_Renderer->CreatePngTexture("Textures/particle.png");
}