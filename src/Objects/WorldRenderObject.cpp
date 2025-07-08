/*WorldRenderObject.cpp
*
* This file defines the render function
* For the world to be created.
*
*/

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "WorldRenderObject.h"
#include "../MyGlut.h"
#include <stdio.h>

void WorldRenderObject::Render(void)
{
#define GRID_SPACING 1

    MyGlut* mg = MyGlut::getInstance();


    glLineWidth(1.0);
    //horizontal lines first
    glBegin(GL_LINES);
    for (i = 0; i < mg->screenHeight; i += GRID_SPACING)
    {
        //glColor3f (0.0, 1.0, 0.0);
        glColor3f(0.184314, 0.309804, 0.309804);
        glVertex2i(0, i);
        glVertex2i(mg->screenWidth, i);
    }
    //vertical lines!!! 
    for (i = 0; i < mg->screenWidth; i += GRID_SPACING)
    {
        //glColor3f (0.0, 1.0, 0.0);
        glColor3f(0.184314, 0.309804, 0.309804);
        glVertex2i(i, 0);
        glVertex2i(i, mg->screenHeight);
    }
    glEnd();

}

