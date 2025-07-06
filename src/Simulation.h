/*



*/




#ifndef SIMULATION_H_
#define SIMULATION_H_

class Simulation
{
private:
	static Simulation* s_instance;
	Simulation() {}

public:
	static Simulation* getInstance();
	static void releaseInstance();

	void init(void);
	void update(void);
	void shutdown(void);
};

#endif
