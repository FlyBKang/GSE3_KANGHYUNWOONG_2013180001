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
#include "Object.h"
#include "Renderer.h"
#include "SceneMgr.h"
using namespace std;

int cnt = 0;
SceneMgr* scene = new SceneMgr();

void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
	if (cnt == 0)
	{
		scene->SceneSet(cnt, 0, 0, 0, OBJECT_BUILDING);
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
		scene->SceneSet(cnt++, x - 250, -(y - 250), 0, OBJECT_CHARACTER);
		
	}
}

void KeyInput(unsigned char key, int x, int y)
{
}

void SpecialKeyInput(int key, int x, int y)
{
}
int checkbullet = 0;
void timeGetTime(int value) //10ms당 1번 켜짐 -> 0.5초는 500ms 50번
{
	glutTimerFunc(TIME, timeGetTime, 1);
	checkbullet++;
	if (checkbullet > 50)
	{
		//scene->SceneSet(cnt, 0, 0, 0, OBJECT_BULLET);
		//cnt++;
		checkbullet = 0;
		cnt = scene->Moding(cnt);
		
	}
	RenderScene();
}
int main(int argc, char **argv)
{
	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
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

