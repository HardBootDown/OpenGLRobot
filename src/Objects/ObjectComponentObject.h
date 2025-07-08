#ifndef OBJECTCOMPONENTOBJECT_H_
#define OBJECTCOMPONENTOBJECT_H_

#include "ComponentObject.h"

class Objects;

class ObjectComponentObject : public ComponentObject
{
protected:
	Objects* parentObject;

public:
	ObjectComponentObject(Objects* r);

	void Update();

	float nextXmove;

	float nextYmove;
};

#endif