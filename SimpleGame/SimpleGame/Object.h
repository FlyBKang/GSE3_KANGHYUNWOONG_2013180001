#pragma once
#include "Renderer.h"
#include "LoadPng.h"
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
	float Object_Life;
	float Object_LifeTime;
	int Object_arrow;

public:
	Object();
	Object(float x, float y, float z, float size, float r, float g, float b, float a,float vx, float vy,  int l, int lt, int  mod);
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
	float GetLife();
	float GetTime();
	int GetArrow();

	void Set(float x, float y, float z, float size, float r, float g, float b, float a, float vx, float vy, int l, int lt, int  mod);
	void SetX(float f);
	void SetY(float f);
	void SetZ(float f);
	void SetSize(float f);
	void SetR(float f);
	void SetG(float f);
	void SetB(float f);
	void SetA(float f);
	void SetMod(int n);
	void SetVx(float f);
	void SetVy(float f);
	void SetLife(float f);
	void SetTime(float f);
	void Update(float Time);
	void SetArrow(int n);
	void Draw(Renderer *g_Renderer);
};