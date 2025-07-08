/* RenderObject.h
 *
 * Class to draw an object
 * Necessary variables to draw are given
 */

#ifndef RENDEROBJECT_H_
#define RENDEROBJECT_H_

class RenderObject
{
protected:
  
   int height;
   int width;
   int x_coord;
   int y_coord;
   int radius;

public:
	virtual void Render (void);
};
#endif

