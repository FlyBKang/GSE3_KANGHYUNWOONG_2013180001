#pragma once
#include "Renderer.h"
class Object
{
	GLint Object_Texture = NULL;
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
	float Object_Life;
	float Object_LifeTime;
	int Object_arrow = -1;
	int Object_team;

public:
	Object();
	Object(float x, float y, float z, float size, float r, float g, float b, float a,float vx, float vy,  int l, int lt, int  mod,int t);
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
	int GetTeam();

	void Set(float x, float y, float z, float size, float r, float g, float b, float a, float vx, float vy, int l, int lt, int  mod, int t);
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
	void SetTeam(int n);
	void SetTexture(GLint texture);
	void Draw(Renderer *g_Renderer);
};