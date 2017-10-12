#include "stdafx.h"
#include "Object.h"
#define COLOR 0.0039215

Object::Object(float x, float y, float z, float size, float r, float g, float b, float a, float vx, float vy, int  mod)
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
}
void Object::Draw(Renderer * g_Renderer)
{
	if (Object_mod == 1) //Fire
	{
		g_Renderer->DrawSolidRect(Object_x - Object_size, Object_y - Object_size, Object_z, Object_size, 1, 0, 0, 0);
		g_Renderer->DrawSolidRect(Object_x, Object_y - Object_size, Object_z, Object_size, 1, 1, 0, 0);
		g_Renderer->DrawSolidRect(Object_x + Object_size, Object_y - Object_size, Object_z, Object_size, 1, 0, 0, 0);
		g_Renderer->DrawSolidRect(Object_x - Object_size, Object_y, Object_z, Object_size, 1, 0, 0, 0);
		g_Renderer->DrawSolidRect(Object_x, Object_y, Object_z, Object_size, 1, 0, 0, 0);
		g_Renderer->DrawSolidRect(Object_x + Object_size, Object_y, Object_z, Object_size, 1, 0, 0, 0);
		g_Renderer->DrawSolidRect(Object_x, Object_y + Object_size, Object_z, Object_size, 1, 0, 0, 0);
	}
	if (Object_mod == 2) //Skull
	{
		g_Renderer->DrawSolidRect(Object_x - Object_size, Object_y + Object_size, Object_z, Object_size, 1, 1, 1, 0);
		g_Renderer->DrawSolidRect(Object_x - Object_size * 2, Object_y + Object_size, Object_z, Object_size, 1, 1, 1, 0);
		g_Renderer->DrawSolidRect(Object_x, Object_y + Object_size, Object_z, Object_size, 1, 1, 1, 0);
		g_Renderer->DrawSolidRect(Object_x + Object_size, Object_y + Object_size, Object_z, Object_size, 1, 1, 1, 0);
		g_Renderer->DrawSolidRect(Object_x + Object_size * 2, Object_y + Object_size, Object_z, Object_size, 1, 1, 1, 0);

		g_Renderer->DrawSolidRect(Object_x - Object_size * 2, Object_y, Object_z, Object_size, 1, 1, 1, 0);
		g_Renderer->DrawSolidRect(Object_x - Object_size, Object_y, Object_z, Object_size, 0, 0, 0, 0);
		g_Renderer->DrawSolidRect(Object_x, Object_y, Object_z, Object_size, 1, 1, 1, 0);
		g_Renderer->DrawSolidRect(Object_x + Object_size, Object_y, Object_z, Object_size, 0, 0, 0, 0);
		g_Renderer->DrawSolidRect(Object_x + Object_size * 2, Object_y, Object_z, Object_size, 1, 1, 1, 0);

		g_Renderer->DrawSolidRect(Object_x - Object_size, Object_y - Object_size, Object_z, Object_size, 1, 1, 1, 0);
		g_Renderer->DrawSolidRect(Object_x - Object_size * 2, Object_y - Object_size, Object_z, Object_size, 1, 1, 1, 0);
		g_Renderer->DrawSolidRect(Object_x, Object_y - Object_size, Object_z, Object_size, 1, 1, 1, 0);
		g_Renderer->DrawSolidRect(Object_x + Object_size, Object_y - Object_size, Object_z, Object_size, 1, 1, 1, 0);
		g_Renderer->DrawSolidRect(Object_x + Object_size * 2, Object_y - Object_size, Object_z, Object_size, 1, 1, 1, 0);

		g_Renderer->DrawSolidRect(Object_x - Object_size, Object_y - Object_size * 2, Object_z, Object_size, 1, 1, 1, 0);
		g_Renderer->DrawSolidRect(Object_x + Object_size, Object_y - Object_size * 2, Object_z, Object_size, 1, 1, 1, 0);
	}
	if (Object_mod == 3)//checked pattern
	{
		g_Renderer->DrawSolidRect(Object_x, Object_y, Object_z, Object_size * 3, COLOR * 103, COLOR * 73, COLOR * 41, 0);
		g_Renderer->DrawSolidRect(Object_x + Object_size, Object_y, Object_z, Object_size, COLOR * 202, COLOR * 172, COLOR * 126, 0);
		g_Renderer->DrawSolidRect(Object_x - Object_size, Object_y, Object_z, Object_size, COLOR * 202, COLOR * 172, COLOR * 126, 0);
		g_Renderer->DrawSolidRect(Object_x, Object_y + Object_size, Object_z, Object_size, COLOR * 202, COLOR * 172, COLOR * 126, 0);
		g_Renderer->DrawSolidRect(Object_x, Object_y - Object_size, Object_z, Object_size, COLOR * 202, COLOR * 172, COLOR * 126, 0);
	}
	if (Object_mod == 4)//castle wall
	{
		g_Renderer->DrawSolidRect(Object_x, Object_y, Object_z, Object_size * 5, COLOR * 76, COLOR * 74, COLOR * 71, 0);

		g_Renderer->DrawSolidRect(Object_x, Object_y, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);
		g_Renderer->DrawSolidRect(Object_x + Object_size * 2, Object_y, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);
		g_Renderer->DrawSolidRect(Object_x - Object_size * 2, Object_y, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);

		g_Renderer->DrawSolidRect(Object_x, Object_y + Object_size * 2, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);
		g_Renderer->DrawSolidRect(Object_x + Object_size * 2, Object_y + Object_size * 2, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);
		g_Renderer->DrawSolidRect(Object_x - Object_size * 2, Object_y + Object_size * 2, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);
		g_Renderer->DrawSolidRect(Object_x + Object_size, Object_y + Object_size * 2, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);
		g_Renderer->DrawSolidRect(Object_x - Object_size, Object_y + Object_size * 2, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);

		g_Renderer->DrawSolidRect(Object_x, Object_y - Object_size * 2, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);
		g_Renderer->DrawSolidRect(Object_x + Object_size * 2, Object_y - Object_size * 2, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);
		g_Renderer->DrawSolidRect(Object_x - Object_size * 2, Object_y - Object_size * 2, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);

		g_Renderer->DrawSolidRect(Object_x, Object_y + Object_size * 3, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);
		g_Renderer->DrawSolidRect(Object_x + Object_size * 2, Object_y + Object_size * 3, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);
		g_Renderer->DrawSolidRect(Object_x - Object_size * 2, Object_y + Object_size * 3, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);

		g_Renderer->DrawSolidRect(Object_x + Object_size, Object_y + Object_size, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);
		g_Renderer->DrawSolidRect(Object_x - Object_size, Object_y + Object_size, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);

		g_Renderer->DrawSolidRect(Object_x + Object_size, Object_y - Object_size, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);
		g_Renderer->DrawSolidRect(Object_x - Object_size, Object_y - Object_size, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);
	}
	if (Object_mod == 5)//castle 
	{
		g_Renderer->DrawSolidRect(Object_x, Object_y, Object_z, Object_size * 5, COLOR * 76, COLOR * 74, COLOR * 71, 0);

		g_Renderer->DrawSolidRect(Object_x, Object_y, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);
		g_Renderer->DrawSolidRect(Object_x + Object_size * 2, Object_y, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);
		g_Renderer->DrawSolidRect(Object_x - Object_size * 2, Object_y, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);

		g_Renderer->DrawSolidRect(Object_x, Object_y + Object_size * 5, Object_z, Object_size * 3, COLOR * 43, COLOR * 41, COLOR * 41, 0);
		g_Renderer->DrawSolidRect(Object_x, Object_y + Object_size * 4, Object_z, Object_size * 3, COLOR * 76, COLOR * 74, COLOR * 71, 0);
		g_Renderer->DrawSolidRect(Object_x, Object_y + Object_size * 7, Object_z, Object_size, COLOR * 76, COLOR * 74, COLOR * 71, 0);

		g_Renderer->DrawSolidRect(Object_x, Object_y + Object_size * 2, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);
		g_Renderer->DrawSolidRect(Object_x + Object_size * 2, Object_y + Object_size * 2, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);
		g_Renderer->DrawSolidRect(Object_x - Object_size * 2, Object_y + Object_size * 2, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);
		g_Renderer->DrawSolidRect(Object_x + Object_size, Object_y + Object_size * 2, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);
		g_Renderer->DrawSolidRect(Object_x - Object_size, Object_y + Object_size * 2, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);

		g_Renderer->DrawSolidRect(Object_x, Object_y - Object_size * 2, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);
		g_Renderer->DrawSolidRect(Object_x + Object_size * 2, Object_y - Object_size * 2, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);
		g_Renderer->DrawSolidRect(Object_x - Object_size * 2, Object_y - Object_size * 2, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);

		g_Renderer->DrawSolidRect(Object_x, Object_y + Object_size * 3, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);
		g_Renderer->DrawSolidRect(Object_x + Object_size * 2, Object_y + Object_size * 3, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);
		g_Renderer->DrawSolidRect(Object_x - Object_size * 2, Object_y + Object_size * 3, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);

		g_Renderer->DrawSolidRect(Object_x + Object_size, Object_y + Object_size, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);
		g_Renderer->DrawSolidRect(Object_x - Object_size, Object_y + Object_size, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);

		g_Renderer->DrawSolidRect(Object_x + Object_size, Object_y - Object_size, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);
		g_Renderer->DrawSolidRect(Object_x - Object_size, Object_y - Object_size, Object_z, Object_size, COLOR * 43, COLOR * 41, COLOR * 41, 0);

		g_Renderer->DrawSolidRect(Object_x, Object_y - Object_size, Object_z, Object_size * 3, COLOR * 177, COLOR * 120, COLOR * 78, 0);

	}
}


//	float Object::GetX()
//	{
//		return Object_x;
//	}
//	float Object::GetY()
//	{
//		return Object_y;
//	}
//	float Object::GetZ()
//	{
//		return Object_z;
//	}
//	
//	float Object::GetSize()
//	{
//		return Object_size;
//	}
//	float Object::GetR()
//	{
//		return Object_r;
//	}
//	float Object::GetG()
//	{
//		return Object_g;
//	}
//	float Object::GetB()
//	{
//		return Object_b;
//	}
//	float Object::GetA()
//	{
//		return Object_a;
//	}
//	float Object::GetMod()
//	{
//		return Object_mod;
//	}
void Object::Update()
{
	Object_x +=	Object_vx;
	Object_y += Object_vy;
}

Object::~Object()
{
}