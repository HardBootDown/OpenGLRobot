/* World.cpp
 *
 * This is the simulated world that is created
 * for an object to live in. The world's life
 * is dictated by its initialization, update,
 * and shutdown.
 */


#include "World.h"
#include "../Managers/RenderManager.h"
#include "../Objects/WorldRenderObject.h"

World::World()
{
	renderObj = new WorldRenderObject;

	RenderManager::GetInstance()->Add(renderObj);
}

World::~World()
{
	if (renderObj != 0)
	{
		RenderManager::GetInstance()->Remove(renderObj);
		delete renderObj;

	}
}
