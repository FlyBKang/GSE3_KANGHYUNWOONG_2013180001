#pragma once
#include "Renderer.h"
class Object
{
public:
	float Object_x;					// ������
	float Object_y;					// ������
	float Object_z;					// ������
	float Object_size;				// ������
	float Object_r;					// ��
	float Object_g;					// ��
	float Object_b;					// ��
	float Object_a;					// ��
	float Object_vx;				// �ӵ�x
	float Object_vy;				// �ӵ�y
	int  Object_mod;				// ����

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