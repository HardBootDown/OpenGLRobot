/* ObjectComponentObject.cpp
*
*  This file calculates changes the object's
*  new values.
*  It calculates velocity, angle, and collision
*  response.
*
*  Sets some values for Objects.cpp
*
*/

#include "ObjectComponentObject.h"
#include <stdio.h>
#include "../Actors/Objects.h"
#include "../Simulation.h"
#include "../MyGlut.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159
#define DEG_TO_RAD PI / 180.0

ObjectComponentObject::ObjectComponentObject(Objects* r)
{
    parentObject = r;
}

void ObjectComponentObject::Update()
{
    parentObject->setVelocity(30);

    //parentObject->setA(parentObject->getA() + 30);

    //get the width and height of the display window ... defined in main.
    MyGlut* mg = MyGlut::getInstance();

    float deltaTime = Simulation::getInstance()->getDeltaTime();

    //error check the delta time
      //printf("RobotComponent::Update has a delta time of %.8f\n", deltaTime);

      // get a unit vector pointing in the correct rotation
    float x = -sin(parentObject->getA() * DEG_TO_RAD);

    float y = cos(parentObject->getA() * DEG_TO_RAD);

    // scale by the velocity of the robot (scaled by delta time for the frame)
    x *= parentObject->getVelocity() * deltaTime;

    y *= parentObject->getVelocity() * deltaTime;

    //check the x axis
      //calculate the next X move
    nextXmove = parentObject->getX() + x;

    if (nextXmove > mg->screenWidth)
    {
        parentObject->setX(mg->screenWidth - parentObject->getR());

        parentObject->setA(-parentObject->getA());

    }
    else if (nextXmove < 0)
    {
        parentObject->setX(0 + parentObject->getR());

        parentObject->setA(-parentObject->getA());
    }
    else
    {
        parentObject->setX(nextXmove);
    }

    //check the Y axis
    //calculate the next Y move
    nextYmove = parentObject->getY() + y;

    if (nextYmove > mg->screenHeight)
    {
        parentObject->setY(mg->screenHeight - parentObject->getR());

        parentObject->setA(parentObject->getA() - 180); //band aid for the Y direction...
    }
    else if (nextYmove < 0)
    {
        parentObject->setY(0);

        parentObject->setA(parentObject->getA() + 180); //band aid for the Y direction...
    }
    else
    {
        parentObject->setY(nextYmove);
    }

}
