/* Actor.h
 *
 * This is a class declaring what an object's
 * type is, called Actor. The life of object created
 * of this type has an initializiation and a termination.
 *
 * It contains the necessary functions
 * And variables for the Actor's
 * Position, traits, and, angle, and velocity.
 */

 /*************************************************/
 /****PLACE COLLISION ANALYSIS WITH WINDOW HERE****/
 /*************************************************/
#ifndef ACTOR_H_
#define ACTOR_H_

#include "../Objects/RenderObject.h"
#include "../Objects/ComponentObject.h"

class ComponentObject;
class RenderObject;

class Actor
{
protected://other Actors have these
    RenderObject* renderObj; //Actor has a RenderObject pointer
    ComponentObject* componentObj;//Actor has a ComponentObject pointer

    int width;
    int height;
    float radius;
    float x_coord;
    float y_coord;
    float Z_coord;

    float deltaTime;
    float position;
    float speed;
    float Angle;
    float LAngle;
    float RAngle;
    float velocity;

public:

    int getR(void);
    int getW(void);
    int getH(void);
    float getX(void);
    float getY(void);
    float getA(void);
    float getVelocity(void);
    float getSpeed(void);

    void setY(float w);
    void setX(float x);
    float setA(float A);
    void setVelocity(float v);
    void setR(int r);
    void setW(int w);
    void setH(int h);
    void setSpeed(float s);
};
#endif
