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
#include <iostream>
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
#define READ_RADIUS  3
#define READ_X_COORD 4
#define READ_Y_COORD 5 

Objects::Objects(int o, int startingIndex)
{
    WhoAmI = o; //Represents an object

    

    setX(1); //set X cord
    setY(2); //set Y cord
    setR(10); //set Radius
    setW(getR() * 2.0); //width = radius * 2.0
    setH(getR() * 2.0); //height = radius * 2.0
    setSpeed(1.0);
    setVelocity(0.0);

    

    srand(time(NULL));
    Angle = rand() % 360;
    //setA(rand() % 360);

    printf("Hi, my name is object %d\n", WhoAmI);
    printf("My radius equals %f\n", radius);
    printf("My x_coord equals %f and my y_coord equals %f\n", x_coord, y_coord);
    printf("My width equals %d \n", getW());
    printf("My height equals %d \n", getH());
    printf("My speed equals %f \n", getSpeed());
    printf("My velocity equals %f \n", getVelocity());
    printf("************************************************************************\n");

    renderObj = new ObjectRenderObject(this);

    RenderManager::GetInstance()->Add(renderObj);

    componentObj = new ObjectComponentObject(this);

    ComponentManager::GetInstance()->Add(componentObj);

}

Objects::~Objects()
{

    if (renderObj != 0)
    {
        RenderManager::GetInstance()->Remove(renderObj);
        delete renderObj;
    }

    if (componentObj != 0)
    {
        ComponentManager::GetInstance()->Remove(componentObj);
        delete componentObj;
    }
}