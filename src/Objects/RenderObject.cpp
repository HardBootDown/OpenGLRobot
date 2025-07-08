/*
COMMENTS HERE
*/

#ifdef __APPLE__
  #include <GLUT/glut.h>
#else
  #include <GL/glut.h>
#endif

#include <iostream>
#include "RenderObject.h"

using std::cout;

void RenderObject::Render (void)
{
	/*glBegin(GL_QUADS); THE OLD ROBOT
        glColor3f (1.0, 0.0, 0.0);
        glVertex2f (parentRobot->getX(), parentRobot->getY());
        glVertex2f (parentRobot->getX() + parentRobot->getW(), parentRobot->getY());
        glVertex2f (parentRobot->getX() + parentRobot->getW(), parentRobot->getY() + parentRobot->getH());
        glVertex2f (parentRobot->getX(), parentRobot->getY() + parentRobot->getH());
    glEnd();*/
}
