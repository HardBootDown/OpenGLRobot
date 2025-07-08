/* ComponentManager.cpp
 *
 *
 *
 *
 */


#include <iostream>
#include "ComponentManager.h"
#include "../Objects/ComponentObject.h"
#include <assert.h>

using std::cout;

ComponentManager* ComponentManager::s_instance = NULL;

ComponentManager* ComponentManager::GetInstance()
{
	if (s_instance == NULL)
		s_instance = new ComponentManager();

	return s_instance;
}

void ComponentManager::ReleaseInstance()
{
	if (s_instance != NULL)
	{
		delete s_instance;
		s_instance = NULL;
	}
}

void ComponentManager::Update(void)//not sure about this
{
	//for (int index = 0; index < someNumber; index++)
	for (vector<ComponentObject*>::iterator i = componentObjectList.begin(); i != componentObjectList.end(); i++)
	{
		ComponentObject* co = *i;
		co->Update();
	}
}

void ComponentManager::Add(ComponentObject* componentObj)
{
	//sanity check for errors
	for (vector<ComponentObject*>::iterator i = componentObjectList.begin(); i != componentObjectList.end(); i++)
	{
		if ((*i) == componentObj)
		{
			assert("Already in the list, idiot!");
			return;
		}
	}

	componentObjectList.push_back(componentObj);
}


void ComponentManager::Remove(ComponentObject* componentObj)
{
	for (vector<ComponentObject*>::iterator i = componentObjectList.begin(); i != componentObjectList.end(); i++)
	{
		if ((*i) == componentObj)
		{
			componentObjectList.erase(i, i);
			return; // optimization
		}
	}
}
