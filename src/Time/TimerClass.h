/*
 *  TimerClass.h
 *  Created by Amy Larson on 10/17/12.
 *  Copyright 2012 Chafee Family. All rights reserved.
 *
 */

#ifndef TIMERCLASS_H
#define TIMERCLASS_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define DEFAULT_RADIUS 50
#define DEFAULT_TICKS 60
#define DEFAULT_TIME 60


struct Position {
	GLfloat x;
	GLfloat y;
public:
	Position(GLfloat posX, GLfloat posY) : x(posX), y(posY) {}
};


struct Color {
	GLfloat r;
	GLfloat g;
	GLfloat b;
public:
	Color(GLfloat red, GLfloat blue, GLfloat green) : r(red), b(blue), g(green) {}
};

class VisibleTimer {

private:

	// static variables

	int radius;
	Position pos;
	Color clockColor;
	Color tickColor;

	float totalTimeInSeconds;
	int numberOfTicks;
	float secondsPerTick; // derived 


	// dynamic variables

	int tickCount;
	GLfloat startTime;

	bool expired;
	GLfloat lastFlashAt;

public:
	VisibleTimer(float totalTime = DEFAULT_TIME, int numTicks = DEFAULT_TICKS);

	// mutators (aka setters)
	void setNumberOfTicks(int numTicks);
	void setTimeSeconds(int time);
	void setRadius(int rad);
	void setPosition(GLfloat posX, GLfloat posY);

	/**********ADDED*BY*MICHAEL*WALTON*******************/
	void set_expired(bool x) { expired = x; }
	/*********************************************/

	void updateTickCount();
	void display();
	void startTimer();
	void flash();
};

#endif
