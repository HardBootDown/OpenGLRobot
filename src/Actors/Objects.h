/* Objects.h
 *
 * This is a class for an Object.
 * It is to get information from a file
 * Determining how many of these
 * Objects are to be made and their sizes
 *
 */


#ifndef OBJECTS_H_
#define OBJECTS_H_

#include "Actor.h"

class ObjectComponentObject;

class Objects : public Actor
{
private:

	ObjectComponentObject* objectComponent;

	//which robot am I?
	int WhoAmI;

public:

	Objects(int o, int startingIndex);

	~Objects();

	ObjectComponentObject* get_objectComponent(void) { return objectComponent; }

};
#endif