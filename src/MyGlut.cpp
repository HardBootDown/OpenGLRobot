/*



*/




#include <iostream>
#include <cstdlib>
#include <stdio.h>
#
#include "Simulation.h"
//#include "Input/PlayerInput.h"
#include "MyGlut.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

using namespace std;

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
	cout << "Height is " << screenHeight << " and width is " << screenWidth << endl;

	testFunction();

	cout << "Calling Simulation shutdown ..." << endl;


	Simulation::getInstance()->shutdown();
}

int MyGlut::testFunction(void)
{
	
}