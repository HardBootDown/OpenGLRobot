/*



*/




#ifndef MYGLUT_H_
#define MYGLUT_H_

class MyGlut
{
private:
	static MyGlut* s_instance;
	MyGlut() {}

public:
	int screenHeight;
	int screenWidth;

	void init(int argc, char** argv);
	static void shutdown(void);
	static void gameUpdate(void);
	//static void reshape(int height, int width);
	//static void processKeySpecealUp(int key, int x, int y);
	static MyGlut* getInstance();
	static void releaseInstance();
	int testFunction(void);

};

#endif
