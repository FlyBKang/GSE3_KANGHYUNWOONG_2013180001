#pragma once
#include "Renderer.h"
class Object
{
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

public:
	Object(float x, float y, float z, float size, float r, float g, float b, float a,float vx, float vy, int  mod);
	~Object();
	float GetX();
	float GetY();
	float GetZ();
	float GetSize();
	float GetR();
	float GetG();
	float GetB();
	float GetA();
	float GetMod();
	float GetVx();
	float GetVy();
	void SetX(float f);
	void SetY(float f);
	void SetZ(float f);
	void SetSize(float f);
	void SetR(float f);
	void SetG(float f);
	void SetB(float f);
	void SetA(float f);
	void SetMod(int n);
	void Update();
	void Draw(Renderer *g_Renderer);
};