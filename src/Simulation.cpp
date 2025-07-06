/*



*/




#include <stdio.h>
#include <iostream>
#include <math.h>
//#include "Managers/RenderManager.h"
//#include "Managers/ComponentManager.h"
//#include "Input/PlayerInput.h"
#include "Simulation.h"
//#include "Actors/Robot.h"
//#include "Actors/World.h"
//#include "Actors/Objects.h"
//#include "Actors/Target.h"
//#include "Time/TimerClass.h"
//#include "Time/Timer.h"
#include "MyGlut.h"
//#include "Objects/RobotAIComponent.h"

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

void Simulation::shutdown(void)
{
	std::cout << "Deleting all objects" << std::endl;

	MyGlut::releaseInstance();
	Simulation::releaseInstance();
}