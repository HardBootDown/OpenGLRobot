/* Timer.cpp
 *
 * Calculates passed time for Glut
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Timer.h"
#include <stdio.h>

Timer::Timer()
{
	startTime = lastDeltaCheck = glutGet(GLUT_ELAPSED_TIME);
}

float Timer::elapsedSeconds(void)
{
	float now = glutGet(GLUT_ELAPSED_TIME);

	//printf("We think now is %.8f\n", now);

	return (now - startTime) / 1000.0f;

}

float Timer::GetDeltaTime(void)
{
	float now = glutGet(GLUT_ELAPSED_TIME);

	float delta = now - lastDeltaCheck;

	lastDeltaCheck = now;

	return delta / 1000.0f;
}