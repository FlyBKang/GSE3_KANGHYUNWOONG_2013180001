#include "stdafx.h"
#include "Object.h"
#include "LoadPng.h"
Object::Object(float x, float y, float z, float size, float r, float g, float b, float a, float vx, float vy, int l,int lt, int  mod,int t)
{
	Object_x = x;
	Object_y = y;
	Object_z = z;
	Object_size = size;
	Object_r = r;
	Object_g = g;
	Object_b = b;
	Object_a = a;
	Object_vx = vx;
	Object_vy = vy;
	Object_mod = mod;
	Object_Life = l;
	Object_LifeTime = lt;
	Object_team = t;
}
void Object::Draw(Renderer * g_Renderer)
{
	if (Object_Life > 0 && Object_LifeTime > 0)
	{
		if (Object_mod == 0) //Box
		{
			if(Object_team == 1)
				g_Renderer->DrawSolidRect(Object_x, Object_y, Object_z, Object_size, 0,0,1, Object_a);
			else
				g_Renderer->DrawSolidRect(Object_x, Object_y, Object_z, Object_size, 1,0,0, Object_a);
		}
		if (Object_mod == 1) //Fire m_texCharacter
		{
			if (Object_team == 1)
				g_Renderer->DrawSolidRect(Object_x, Object_y, Object_z, Object_size, 0, 0, 1, Object_a);
			else
				g_Renderer->DrawSolidRect(Object_x, Object_y, Object_z, Object_size, 1, 0, 0, Object_a);
			//g_Renderer->DrawSolidRect(Object_x - Object_size, Object_y - Object_size, Object_z, Object_size, 1, 0, 0, 1);
			//g_Renderer->DrawSolidRect(Object_x, Object_y - Object_size, Object_z, Object_size, 1, 1, 0, 1);
			//g_Renderer->DrawSolidRect(Object_x + Object_size, Object_y - Object_size, Object_z, Object_size, 1, 0, 0,1);
			//g_Renderer->DrawSolidRect(Object_x - Object_size, Object_y, Object_z, Object_size, 1, 0, 0, 1);
			//g_Renderer->DrawSolidRect(Object_x, Object_y, Object_z, Object_size, 1, 0, 0, 1);
			//g_Renderer->DrawSolidRect(Object_x + Object_size, Object_y, Object_z, Object_size, 1, 0, 0, 1);
			//g_Renderer->DrawSolidRect(Object_x, Object_y + Object_size, Object_z, Object_size, 1, 0, 0, 1);
		}
		if (Object_mod == 2) //Skull
		{
			g_Renderer->DrawSolidRect(Object_x - Object_size, Object_y + Object_size, Object_z, Object_size, 1, 1, 1, 1);
			g_Renderer->DrawSolidRect(Object_x - Object_size * 2, Object_y + Object_size, Object_z, Object_size, 1, 1, 1, 1);
			g_Renderer->DrawSolidRect(Object_x, Object_y + Object_size, Object_z, Object_size, 1, 1, 1, 1);
			g_Renderer->DrawSolidRect(Object_x + Object_size, Object_y + Object_size, Object_z, Object_size, 1, 1, 1, 1);
			g_Renderer->DrawSolidRect(Object_x + Object_size * 2, Object_y + Object_size, Object_z, Object_size, 1, 1, 1, 1);

			g_Renderer->DrawSolidRect(Object_x - Object_size * 2, Object_y, Object_z, Object_size, 1, 1, 1, 1);
			g_Renderer->DrawSolidRect(Object_x - Object_size, Object_y, Object_z, Object_size, 0, 0, 0, 1);
			g_Renderer->DrawSolidRect(Object_x, Object_y, Object_z, Object_size, 1, 1, 1, 1);
			g_Renderer->DrawSolidRect(Object_x + Object_size, Object_y, Object_z, Object_size, 0, 0, 0, 1);
			g_Renderer->DrawSolidRect(Object_x + Object_size * 2, Object_y, Object_z, Object_size, 1, 1, 1, 1);

			g_Renderer->DrawSolidRect(Object_x - Object_size, Object_y - Object_size, Object_z, Object_size, 1, 1, 1, 1);
			g_Renderer->DrawSolidRect(Object_x - Object_size * 2, Object_y - Object_size, Object_z, Object_size, 1, 1, 1, 1);
			g_Renderer->DrawSolidRect(Object_x, Object_y - Object_size, Object_z, Object_size, 1, 1, 1, 1);
			g_Renderer->DrawSolidRect(Object_x + Object_size, Object_y - Object_size, Object_z, Object_size, 1, 1, 1, 1);
			g_Renderer->DrawSolidRect(Object_x + Object_size * 2, Object_y - Object_size, Object_z, Object_size, 1, 1, 1, 1);

			g_Renderer->DrawSolidRect(Object_x - Object_size, Object_y - Object_size * 2, Object_z, Object_size, 1, 1, 1, 1);
			g_Renderer->DrawSolidRect(Object_x + Object_size, Object_y - Object_size * 2, Object_z, Object_size, 1, 1, 1, 1);
		}
		if (Object_mod == 3)//checked pattern
		{
			g_Renderer->DrawSolidRect(Object_x, Object_y, Object_z, Object_size * 3, COLOR * 103, COLOR * 73, COLOR * 41, 1);
			g_Renderer->DrawSolidRect(Object_x + Object_size, Object_y, Object_z, Object_size, COLOR * 202, COLOR * 172, COLOR * 126, 1);
			g_Renderer->DrawSolidRect(Object_x - Object_size, Object_y, Object_z, Object_size, COLOR * 202, COLOR * 172, COLOR * 126, 1);
			g_Renderer->DrawSolidRect(Object_x, Object_y + Object_size, Object_z, Object_size, COLOR * 202, COLOR * 172, COLOR * 126, 1);
			g_Renderer->DrawSolidRect(Object_x, Object_y - Object_size, Object_z, Object_size, COLOR * 202, COLOR * 172, COLOR * 126, 1);
		}
		if (Object_mod == 4)//castle wall
		{
				g_Renderer->DrawTexturedRect(Object_x, Object_y, Object_z, Object_size, Object_r, Object_g, Object_b, Object_a, Object_Texture);
		}
		if (Object_mod == 5)//castle 
		{
			g_Renderer->DrawSolidRect(Object_x, Object_y, Object_z, Object_size * 5, COLOR * 76, COLOR * 74, COLOR * 71, 1);

			g_Renderer->DrawSolidRect(Object_x, Object_y, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 1);
			g_Renderer->DrawSolidRect(Object_x + Object_size * 2, Object_y, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 1);
			g_Renderer->DrawSolidRect(Object_x - Object_size * 2, Object_y, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 1);

			g_Renderer->DrawSolidRect(Object_x, Object_y + Object_size * 5, Object_z, Object_size * 3, COLOR * 43, COLOR * 41, COLOR * 41, 1);
			g_Renderer->DrawSolidRect(Object_x, Object_y + Object_size * 4, Object_z, Object_size * 3, COLOR * 76, COLOR * 74, COLOR * 71, 1);
			g_Renderer->DrawSolidRect(Object_x, Object_y + Object_size * 7, Object_z, Object_size, COLOR * 76, COLOR * 74, COLOR * 71, 1);

			g_Renderer->DrawSolidRect(Object_x, Object_y + Object_size * 2, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 1);
			g_Renderer->DrawSolidRect(Object_x + Object_size * 2, Object_y + Object_size * 2, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 1);
			g_Renderer->DrawSolidRect(Object_x - Object_size * 2, Object_y + Object_size * 2, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 1);
			g_Renderer->DrawSolidRect(Object_x + Object_size, Object_y + Object_size * 2, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 1);
			g_Renderer->DrawSolidRect(Object_x - Object_size, Object_y + Object_size * 2, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 1);

			g_Renderer->DrawSolidRect(Object_x, Object_y - Object_size * 2, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 1);
			g_Renderer->DrawSolidRect(Object_x + Object_size * 2, Object_y - Object_size * 2, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 1);
			g_Renderer->DrawSolidRect(Object_x - Object_size * 2, Object_y - Object_size * 2, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 1);

			g_Renderer->DrawSolidRect(Object_x, Object_y + Object_size * 3, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 1);
			g_Renderer->DrawSolidRect(Object_x + Object_size * 2, Object_y + Object_size * 3, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 1);
			g_Renderer->DrawSolidRect(Object_x - Object_size * 2, Object_y + Object_size * 3, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 1);

			g_Renderer->DrawSolidRect(Object_x + Object_size, Object_y + Object_size, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 1);
			g_Renderer->DrawSolidRect(Object_x - Object_size, Object_y + Object_size, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 1);

			g_Renderer->DrawSolidRect(Object_x + Object_size, Object_y - Object_size, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 1);
			g_Renderer->DrawSolidRect(Object_x - Object_size, Object_y - Object_size, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 1);

			g_Renderer->DrawSolidRect(Object_x, Object_y - Object_size, Object_z, Object_size * 3, COLOR * 177, COLOR * 120, COLOR * 78, 1);

		}
		if (Object_mod == 6)//arrow
		{
			if (Object_team == 1)
				g_Renderer->DrawSolidRect(Object_x, Object_y, Object_z, Object_size, 1, 1, 0, Object_a);
			else
				g_Renderer->DrawSolidRect(Object_x, Object_y, Object_z, Object_size, 0.5, 0.2, 0.7, Object_a);
		}
	}
}
void Object::Set(float x, float y, float z, float size, float r, float g, float b, float a, float vx, float vy, int l, int lt, int  mod,int t)
{
	Object_x = x;
	Object_y = y;
	Object_z = z;
	Object_size = size;
	Object_r = r;
	Object_g = g;
	Object_b = b;
	Object_a = a;
	Object_vx = vx;
	Object_vy = vy;
	if(mod==1)
		if (t == 1)
		{
			Object_vx = 0;
			Object_vy = SPEED*300;
		}
		else 
		{
			Object_vx = 0;
			Object_vy = -SPEED * 300;
		}
	Object_mod = mod;
	Object_Life = l;
	Object_LifeTime = lt;
	Object_team = t;
}

float Object::GetX(){ return Object_x; }
float Object::GetY(){ return Object_y; }
float Object::GetZ(){ return Object_z; }
float Object::GetSize(){ return Object_size; }
float Object::GetR(){ return Object_r; }
float Object::GetG(){ return Object_g; }
float Object::GetB(){ return Object_b; }
float Object::GetA(){ return Object_a; }
float Object::GetVx() { return Object_vx; }
float Object::GetVy() { return Object_vy; }
float Object::GetTime() { return Object_LifeTime; }
float Object::GetLife() { return Object_Life; }
float Object::GetMod(){ return Object_mod;}
int Object::GetArrow(){ return Object_arrow; }
int Object::GetTeam() { return Object_team; }
void Object::SetTexture(GLint texture) { Object_Texture = texture; }
void Object::SetX(float f) { Object_x = f; }
void Object::SetY(float f) { Object_y = f; }
void Object::SetZ(float f) { Object_z = f; }
void Object::SetSize(float f) { Object_size = f; }
void Object::SetR(float f) { Object_r = f; }
void Object::SetG(float f) { Object_g = f; }
void Object::SetB(float f) { Object_b = f; }
void Object::SetA(float f) { Object_a = f; }
void Object::SetVx(float f) { Object_vx = f; }
void Object::SetVy(float f) { Object_vy = f; }
void Object::SetLife(float f) { Object_Life = f; }
void Object::SetTime(float f) { Object_LifeTime = f; }
void Object::SetMod(int n) { Object_mod = n; }
void Object::SetArrow(int n) {Object_arrow = n; }
void Object::SetTeam(int n) { Object_team = n; }
void Object::Update(float Time)
{
	if (GetX() > Horizontal/2)
		SetVx(-GetVx()); 
	if (GetY() > Vertical / 2)
		SetVy(-GetVy()); 
	if (GetX() < -Horizontal / 2)
		SetVx(-GetVx());
	if (GetY() < -Vertical/2)
		SetVy(-GetVy());
	SetX(GetX() + GetVx());
	SetY(GetY() + GetVy());
	Object_LifeTime -= Time;
}

Object::Object() {}
Object::~Object() {}
