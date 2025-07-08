/* RenderManager.h
 *
 *
 *
 *
 */


#ifndef RENDERMANAGER_H_
#define RENDERMANAGER_H_

#include <vector>

 //Pre-declares

class RenderObject;

using std::vector;

class RenderManager
{
private:
	static RenderManager* s_instance;

	vector<RenderObject* > renderObjectList;

	RenderManager() {}

public:
	static RenderManager* GetInstance();

	static void ReleaseInstance();

	void Update(void);

	void Add(RenderObject* renderObj);

	void Remove(RenderObject* renderObj);
};
#endif
