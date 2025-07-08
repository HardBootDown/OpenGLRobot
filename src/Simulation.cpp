/*



*/




#include <stdio.h>
#include <iostream>
#include <math.h>
#include "Managers/RenderManager.h"
#include "Managers/ComponentManager.h"
//#include "Input/PlayerInput.h"
#include "Simulation.h"
//#include "Actors/Robot.h"
#include "Actors/World.h"
#include "Actors/Objects.h"
//#include "Actors/Target.h"
#include "Time/TimerClass.h"
#include "Time/Timer.h"
#include "MyGlut.h"
//#include "Objects/RobotAIComponent.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

Simulation* Simulation::s_instance = NULL;

Simulation* Simulation::getInstance()
{
	if (s_instance == NULL)
	{
		s_instance = new Simulation();

		return s_instance;
	}

	return s_instance;
}

void Simulation::releaseInstance()
{
	if (s_instance != NULL)
	{
		delete s_instance;
		s_instance = NULL;
	}
}

void Simulation::init(void)
{
	you_lose = you_win = false;

	array_objects = (Objects**)malloc(sizeof(Objects*) * numObjects);

	for (int o = 0; o < numObjects; o++)
	{
		objects = new Objects(o, objectStartingIndex);
		array_objects[o] = objects;
	}

	//Create new world object
	world = new World();

	//Create a new Timer object
	timer = new Timer();

	//Create a new worldTime object and start the timer
	worldTime = new VisibleTimer();
	worldTime->startTimer();
}

void Simulation::shutdown(void)
{
	std::cout << "Deleting all objects" << std::endl;

	delete world;
	delete objects;
	delete worldTime;
	delete timer;

	RenderManager::ReleaseInstance();
	MyGlut::releaseInstance();
	Simulation::releaseInstance();
}


void Simulation::update(void)
{
	deltaTime = timer->GetDeltaTime();

	elapsedSeconds = timer->elapsedSeconds();

	if (elapsedSeconds >= 60.0)
	{
		you_lose = true;
	}
		
	//Game_Over();

	//printf("\n\nIn Simulation deltaTime equals %f\n\n", deltaTime);

	//ComponentManager::GetInstance()->Update();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//this clears the screen

	//BoundaryAnalysis();//check for collisions

	//RenderManager::GetInstance()->Update();//Run RenderManager Update

	worldTime->display();


	//Displays text to screen depending on if user "wins" or "loses"
	//if (you_lose)
	//{
		//RenderString(30, 15, GLUT_BITMAP_TIMES_ROMAN_24, "GAME OVER");
	//}


	//if (you_win)
	//{
		//RenderString(30, 15, GLUT_BITMAP_TIMES_ROMAN_24, "YOU WIN");
	//}


	glutSwapBuffers();//flip the render buffer!
}

float Simulation::getDeltaTime()
{
	return deltaTime;
}