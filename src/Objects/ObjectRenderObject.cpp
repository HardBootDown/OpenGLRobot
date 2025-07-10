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
    parentObject = r;
}

void ObjectRenderObject::Render(void)
{
    glPushMatrix();
    glTranslatef(parentObject->getX(), parentObject->getY(), 0);
    glRotatef(parentObject->getA(), 0, 0, 1);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0, 1.5, 0.0);

    for (int i = 0; i < 100; i++)
    {
        glVertex2f(parentObject->getR() * cos(i * 2.0f * PI / 20.0f),
            parentObject->getR() * sin(i * 2.0f * PI / 20.0f));
    }

    glEnd();
    glPopMatrix();

}