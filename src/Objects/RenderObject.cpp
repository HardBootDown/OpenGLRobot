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
	cout << "This is a place holder\n";
}
