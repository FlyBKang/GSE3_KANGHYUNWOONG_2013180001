#pragma once
#include "Renderer.h"
class Object
{
public:
	float Object_x;					// 포지션
	float Object_y;					// 포지션
	float Object_z;					// 포지션
	float Object_size;				// 사이즈
	float Object_r;					// 색
	float Object_g;					// 색
	float Object_b;					// 색
	float Object_a;					// 색
	float Object_vx;				// 속도x
	float Object_vy;				// 속도y
	int  Object_mod;				// 상태

	Object(float x, float y, float z, float size, float r, float g, float b, float a,float vx, float vy, int  mod);
	~Object();
	//	float GetX();
	//	float GetY();
	//	float GetZ();
	//	float GetSize();
	//	float GetR();
	//	float GetG();
	//	float GetB();
	//	float GetA();
	//	float GetMod();
	void Update();
	void Draw(Renderer *g_Renderer);
};