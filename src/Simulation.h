/*



*/




#ifndef SIMULATION_H_
#define SIMULATION_H_

// Pre-declares for g++ ... so Simulation knows what they are!

class World;

//class Robot;

class Objects;

class VisibleTimer;

class Timer;

//class Target;

class Simulation
{
private:
	static Simulation* s_instance;
	Simulation() {}

	VisibleTimer* worldTime; //Simulation has a worldTime
	Timer* timer; //Simulation has a timer
	World* world; //Simulation has a world
	Objects* objects;//Simulation has objects
	Objects** array_objects;//pointer to Objects pointer
	int numObjects;
	int objectStartingIndex;
	bool you_lose, you_win;
	float deltaTime;
	float elapsedSeconds;

public:
	static Simulation* getInstance();
	static void releaseInstance();
	void init(void);
	void update(void);
	void shutdown(void);
	float getDeltaTime();
	void set_ObjectInfo(int x, int y) { numObjects = x; objectStartingIndex = y; }
};

#endif
