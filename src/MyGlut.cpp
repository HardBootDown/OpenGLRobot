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

	Simulation::getInstance()->init();

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	glutInitWindowSize(screenHeight, screenWidth);

	glutCreateWindow("Welcome to gorobot, press F1 key to exit.");

	glutDisplayFunc(gameUpdate);

	//glutReshapeFunc(reshape);

	//glutSpecialUpFunc(processKeySpecialUp);//catch the keys and send to PlayerInput

	glutIdleFunc(gameUpdate);//what to do when glut is idle

	glutMainLoop();//turn control over to glut


	cout << "Calling Simulation shutdown ..." << endl;


	Simulation::getInstance()->shutdown();
}

int MyGlut::testFunction(void)
{
	return 0;
}

void MyGlut::gameUpdate(void)
{
	Simulation::getInstance()->update();
}