/* Timer.h
 *
 *
 */

#ifndef TIMER_H_
#define TIMER_H_

class Timer
{
private:
	float startTime;
	float lastDeltaCheck;
	float deltaTime;
public:

	Timer();
	//~Timer();

	float elapsedSeconds(void);

	float GetDeltaTime(void);


};
#endif