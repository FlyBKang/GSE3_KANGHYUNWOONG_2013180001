/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include <iostream>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"
#include "SceneMgr.h"
using namespace std;

int checkbullet = 0;
int checkarrow = 0;
int t2checkchar = 0;
int t1checkchar = 0;
bool charcooldown = false;

int cnt = 0;
SceneMgr* scene = new SceneMgr();
void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	
	if (cnt == 0)
	{
		scene->TextureMaping();
		cnt++;
		scene->SceneSet(cnt, T1B1, OBJECT_BUILDING,1,LEVEL_GROUND);
		cnt++;
		scene->SceneSet(cnt, T1B2, OBJECT_BUILDING,1, LEVEL_GROUND);
		cnt++;
		scene->SceneSet(cnt, T1B3, OBJECT_BUILDING,1, LEVEL_GROUND);
		cnt++;
		scene->SceneSet(cnt, T2B1, OBJECT_BUILDING, 2, LEVEL_GROUND);
		cnt++;				  
		scene->SceneSet(cnt, T2B2, OBJECT_BUILDING, 2, LEVEL_GROUND);
		cnt++;				  
		scene->SceneSet(cnt, T2B3, OBJECT_BUILDING, 2, LEVEL_GROUND);
		cnt++;
	}
	scene->Rendering(MAX);
	scene->Checking();

	glutSwapBuffers();
}

void Idle(void)
{
}
void MouseInput(int button, int state, int x, int y)
{
	if ((button == GLUT_LEFT_BUTTON && state == GLUT_DOWN))
	{
		if (!charcooldown)
		{
			if((Vertical / 2) - y > 0)
				scene->SceneSet(cnt++, x - (Horizontal / 2), 0, 0, OBJECT_CHARACTER, 1, LEVEL_UNDERGROUND);
			else
				scene->SceneSet(cnt++, x - (Horizontal / 2), ((Vertical / 2) - y), 0, OBJECT_CHARACTER, 1, LEVEL_UNDERGROUND);
			charcooldown = true;
		}
	}
}

void KeyInput(unsigned char key, int x, int y)
{
}

void SpecialKeyInput(int key, int x, int y)
{
}

void timeGetTime(int value) //10ms당 1번 켜짐 -> 0.5초는 500ms 50번
{
	glutTimerFunc(TIME, timeGetTime, 1);
	checkbullet++;
	checkarrow++;
	t2checkchar++;
	if(charcooldown)
		t1checkchar++;
	if (t1checkchar > TIMER_PLAYERCOOL)
	{
		charcooldown = false;
		t1checkchar = 0;
	}
	if (t2checkchar > TIMER_ENEMYPLAYER)
	{
		switch (rand() % 3)
		{
		case 0:
		{
			scene->SceneSet(cnt, T2B1, OBJECT_CHARACTER, 2, LEVEL_UNDERGROUND); cnt++;
			break;
		}
		case 1:
		{
			scene->SceneSet(cnt, T2B2, OBJECT_CHARACTER, 2, LEVEL_UNDERGROUND); cnt++;
			break;
		}
		case 2:
		{
			scene->SceneSet(cnt, T2B3, OBJECT_CHARACTER, 2, LEVEL_UNDERGROUND); cnt++;
			break;
		}
		}
		t2checkchar = 0;
	}
	if (checkarrow > TIMER_ARROW)
	{
		cnt = scene->Moding(cnt);
		checkarrow = 0;
	}
	if (checkbullet > TIMER_BULLET)
	{
		cnt = scene->ShotBullet(cnt);
		checkbullet = 0;
	}
	RenderScene();
}
int main(int argc, char **argv)
{
	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(Horizontal, Vertical);
	glutCreateWindow("Game Software Engineering KPU");

	glewInit();
	scene->Rising();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}

	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);
	glutTimerFunc(TIME, timeGetTime, 1);
	glutMainLoop();

	scene->Ending();
	delete(scene);
    return 0;
}






