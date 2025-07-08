/* World.h
 *
 * This World class definition is to create
 * a world for an object to reside.
 * it operates on an initialization to create
 * a new world, an update to change the world's attributes
 * and a shutdown to cleanup/close and terminate the
 * world
 */


#ifndef WORLD_H_
#define WORLD_H_

#include "Actor.h"

class World : public Actor //World is a Actor
{
private:

public:
	World();
	~World();
};
#endif
