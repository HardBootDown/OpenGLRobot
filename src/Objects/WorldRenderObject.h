/*

*/

#ifndef WORLDRENDEROBJECT_H_
#define WORLDRENDEROBJECT_H_
#include "RenderObject.h"

class WorldRenderObject : public  RenderObject//WorldRenderObject is a RenderObject
{
private:
	int i;//for the for loops

public: //redefine RenderObject Render()
	void Render(void);
};

#endif
