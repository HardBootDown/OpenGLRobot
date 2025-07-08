/*

*/
#ifndef OBJECTRENDEROBJECT_H_
#define OBJECTRENDEROBJECT_H_

#include "RenderObject.h"

class Objects;

class ObjectRenderObject : public RenderObject
{
private:

	Objects* parentObjects;

public:

	ObjectRenderObject(Objects* r);

	void Render(void);

};
#endif