/* ComponentManager.h
 *
 *
 *
 *
 */


#ifndef COMPONENTMANAGER_H_
#define COMPONENTMANAGER_H_

#include <vector>

class ComponentObject;//pre define for g++

using std::vector;

class ComponentManager
{
private:
	static ComponentManager* s_instance;

	vector<ComponentObject*> componentObjectList;

	ComponentManager() {} //default constructor

public:
	static void ReleaseInstance();
	static ComponentManager* GetInstance();

	void Update(void);
	void Add(ComponentObject* componentObj);
	void Remove(ComponentObject* componentObj);

};
#endif
