/* Actor.cpp
 *
 * This is where the class Actor
 * defines all the necessary variables
 * for an actor, such as the coordinates,
 * angle, width, height, etc.
 *
 * The functions below simply return
 * the values of these variables
 * for other files to pass/read/compute.
 */


#include "Actor.h"

 /*int Actor::getD (void)
 {
     return rotation;
 }*/
int Actor::getR(void)
{
    return radius;
}

float Actor::getX(void)
{
    return x_coord;
}

float Actor::getY(void)
{
    return y_coord;
}

int Actor::getW(void)
{
    return width;
}

int Actor::getH(void)
{
    return height;
}

float Actor::getA(void)
{
    return Angle;
}

float Actor::getVelocity(void)
{
    return velocity;
}

float Actor::setA(float A)
{
    while (A > 360.0)
        A -= 360.0;

    while (A < -360.0)
        A += 360.0;

    Angle = A;
}
void Actor::setX(float x)
{
    x_coord = x;
}

void Actor::setY(float y)
{
    y_coord = y;
}

void Actor::setVelocity(float v)
{
    velocity = v;
}

void Actor::setR(int r)
{
    radius = r;
}