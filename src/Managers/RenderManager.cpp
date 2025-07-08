/* RenderManager.cpp
 *
 *
 *
 *
 */
#include <iostream>
#include "RenderManager.h"
#include "../Objects/RenderObject.h"
#include <assert.h>

 //using std::cout;

RenderManager* RenderManager::s_instance = NULL;

RenderManager* RenderManager::GetInstance()//RenderManager creates itself
{
	if (s_instance == NULL)
		s_instance = new RenderManager();

	return s_instance;
}

void RenderManager::ReleaseInstance()//RenderManager deletes itself
{
	if (s_instance != NULL)
	{
		delete s_instance;
		s_instance = NULL;
	}
}

void RenderManager::Update(void)//loop the vector and exicute each 
{
	//for (int index = 0; index < someNumber; index++)
	for (vector<RenderObject*>::iterator i = renderObjectList.begin(); i != renderObjectList.end(); i++)
	{
		RenderObject* ro = *i;//what the heck did I just type?
		ro->Render();
	}
}

void RenderManager::Add(RenderObject* renderObj)
{
	// sanity check for errors
	for (vector<RenderObject*>::iterator i = renderObjectList.begin(); i != renderObjectList.end(); i++)
	{
		if ((*i) == renderObj)
		{
			assert("Already in the list, idiot!");
			return;
		}
	}

	renderObjectList.push_back(renderObj);//add the renderObj to the end of the array
}

void RenderManager::Remove(RenderObject* renderObj)
{
	for (vector<RenderObject*>::iterator i = renderObjectList.begin(); i != renderObjectList.end(); i++)
	{
		if ((*i) == renderObj)
		{
			renderObjectList.erase(i, i);
			return; // optimization
		}
	}
}

