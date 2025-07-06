/*



*/




#include <iostream>
#include <cstdlib>
#include <stdio.h>
#
#include "Simulation.h"
//#include "Input/PlayerInput.h"
#include "MyGlut.h"

MyGlut* MyGlut::s_instance = NULL;

MyGlut* MyGlut::getInstance()
{
	if (s_instance == NULL)
	{
		s_instance = new MyGlut();

		return s_instance;
	}
	else
	{
		return s_instance;
	}
}

void MyGlut::releaseInstance()
{
	if (s_instance != NULL)
	{
		delete s_instance;
		s_instance = NULL;
	}
}

void MyGlut::init(int argc, char** argv)
{
	//band aid for setting screen height and width from file
	MyGlut* mg = MyGlut::getInstance();

	int width = mg->screenWidth;

	int height = mg->screenHeight;
	//*******************************************************

	printf("height %d width %d at the start of Init method\n", height, width);

	Simulation::getInstance()->shutdown();
}