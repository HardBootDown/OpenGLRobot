/* Objects.cpp
*
*  This file contains initialized values
*  for an object.
*
*  It will create 2 objects, objectComponent
*  and renderObject which then can set and get
*  new values of the object, respectively.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Objects.h"
#include <time.h>
#include "../Managers/RenderManager.h"
#include "../Managers/ComponentManager.h"
#include "../Objects/ObjectRenderObject.h"
#include "../Objects/ObjectComponentObject.h"
#include "../ReadWriteFile.h"

#define GLUT_KEY_EXIT 1 //SHOULD BE THE Q KEY
#define ACCELERATE 0.1 
#define TURN_RATE 30.0

//****These are values that represent the resepctive indeces from the ReadWritefile
#define READ_RADIUS  (o * 3) + startingIndex
#define READ_X_COORD READ_RADIUS + 1  // These are the
#define READ_Y_COORD READ_X_COORD + 1 // Indece values
//*********************************************************************************


Objects::Objects(int o, int startingIndex)
{
    WhoAmI = o; //Represents an object

    //****This is where the indeces are referenced to get the values

    //****These lines of code reads its respective values in ReadWritefile
    x_coord = ReadWriteFile::getInstance()->get_buffer(READ_X_COORD);
    y_coord = ReadWriteFile::getInstance()->get_buffer(READ_Y_COORD);
    radius = ReadWriteFile::getInstance()->get_buffer(READ_RADIUS);
    //**************************************************************

    printf("Hi, my name is object %d\n", WhoAmI);
    printf("My radius equals %d\n", radius);
    printf("My x_coord equals %f and my y_coord equals %f\n", x_coord, y_coord);
    printf("************************************************************************\n");

    srand(time(NULL));

    width = radius * 2.0;
    height = radius * 2.0;
    speed = 1;
    //Angle = -90;
    Angle = rand() % 360;

    velocity = 0;

    renderObj = new ObjectRenderObject(this);

    RenderManager::GetInstance()->Add(renderObj);

    objectComponent = new ObjectComponentObject(this);

    ComponentManager::GetInstance()->Add(objectComponent);

}

Objects::~Objects()
{

    if (renderObj != 0)
    {
        RenderManager::GetInstance()->Remove(renderObj);
        delete renderObj;
    }

    if (objectComponent != 0)
    {
        ComponentManager::GetInstance()->Remove(objectComponent);
        delete objectComponent;
    }
}