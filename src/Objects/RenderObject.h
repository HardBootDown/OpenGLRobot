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
  
   //int height;
   //int width;
   //int x_coord;
   //int y_coord;
   //int radius;

public:
	virtual void Render (void);

	/*int get_height(void) { return height; }
	void set_height(int h) { height = h; }
	int get_width(void) { return width; }
	void set_width(int w) { width = w; }
	int get_x_coord(void) { return x_coord; }
	void set_x_coord(int x) { x_coord = x; }
	int get_y_coord(void) { return y_coord; }
	void set_y_coord(int y) { y_coord = y; }
	int get_radius(void) { return radius; }
	void set_radius(int r) { radius = r; }*/
};
#endif

