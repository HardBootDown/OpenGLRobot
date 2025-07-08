#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "ObjectRenderObject.h"
#include "../Actors/Objects.h"
#include <math.h>

#define PI 3.14159


ObjectRenderObject::ObjectRenderObject(Objects* r)
{
    parentObjects = r;
}

void ObjectRenderObject::Render(void)
{
    //****This draws the robot as a circle****   
    glPushMatrix();

    glTranslatef(parentObjects->getX(), parentObjects->getY(), 0);
    glRotatef(parentObjects->getA(), 0, 0, 1);

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0, 0.5, 0.0);
    glVertex2f(0, 0);
    for (int i = 0; i <= 100; i++)
    {
        glVertex2f(parentObjects->getR() * cos(i * 2.0f * PI / 20.0f),
            parentObjects->getR() * sin(i * 2.0f * PI / 20.0f));
    }
    glEnd();

    glPopMatrix();
}