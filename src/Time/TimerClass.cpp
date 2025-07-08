/*
 *  TimerClass.cpp
 *  Created by Amy Larson on 10/17/12.
 */

#include "TimerClass.h"
#include <math.h>
#include <stdio.h>

#define calcSecondsPerTick() secondsPerTick = totalTimeInSeconds / numberOfTicks;


VisibleTimer::VisibleTimer(float totalTime, int numTicks) :
	pos(690.0f, 60.0f),
	clockColor(1.0f, 1.0f, 1.0f),
	tickColor(1.0f, 0.0f, 0.0f)

{
	radius = DEFAULT_RADIUS;

	totalTimeInSeconds = totalTime;
	numberOfTicks = numTicks;
	calcSecondsPerTick(); //= totalTimeInSeconds / numberOfTicks;

	tickCount = 0;
	startTime = glutGet(GLUT_ELAPSED_TIME);
	expired = false;
	lastFlashAt = 0.0f;
}

void VisibleTimer::startTimer() {

	startTime = glutGet(GLUT_ELAPSED_TIME);

	//printf(" Start Time == %d\n", startTime);

	tickCount = 0;
	expired = false;
	lastFlashAt = 0.0f;
}

void VisibleTimer::updateTickCount() {

	if (expired) return;

	GLfloat now = glutGet(GLUT_ELAPSED_TIME);

	float elapsedSeconds = (now - startTime) / 1000.0f;

	tickCount = (int)(elapsedSeconds / secondsPerTick);

	if (tickCount > numberOfTicks) {
		expired = true;
		lastFlashAt = now;
	}
}

void VisibleTimer::display() {

	this->updateTickCount();

	if (expired) {
		this->flash();
		return;
	}

	glPushMatrix();
	glTranslatef(pos.x, pos.y, 0.0f);
	// these rotations start ticks at top and move them clockwise
	glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
	glRotatef(180.0f, 0.0f, 0.0f, 0.0f);

	// display the clock without any ticks.
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(clockColor.r, clockColor.g, clockColor.b);
	glVertex2f(0.0f, 0.0f);
	for (int i = 0; i <= numberOfTicks; i++) {
		glVertex2f(radius * cos(i * 2 * 3.14 / numberOfTicks),
			radius * sin(i * 2 * 3.14 / numberOfTicks));
	}
	glEnd();

	// display the ticks on top of the clock
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(tickColor.r, tickColor.g, tickColor.b);
	glVertex2f(0.0f, 0.0f);
	for (int i = 0; i <= tickCount; i++) {
		glVertex2f(radius * cos(i * 2 * 3.14 / numberOfTicks),
			radius * sin(i * 2 * 3.14 / numberOfTicks));
	}
	glEnd();
	glPopMatrix();
}

void VisibleTimer::flash() {

	// flash() toggles the color of the clock between black and white.
	// the frequency of the flash is 0.5 second
	static GLfloat color = 0.0f;

	GLfloat now = glutGet(GLUT_ELAPSED_TIME);
	if (500.0 < (now - lastFlashAt)) {
		lastFlashAt = now;
		if (0.0f == color) {
			color = 1.0f;
		}
		else {
			color = 0.0f;
		}
	}

	glPushMatrix();
	glTranslatef(pos.x, pos.y, 0.0f);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(color, color, color);
	glVertex2f(0.0f, 0.0f);
	for (int i = 0; i <= numberOfTicks; i++) {
		glVertex2f(radius * cos(i * 2 * 3.14 / numberOfTicks),
			radius * sin(i * 2 * 3.14 / numberOfTicks));
	}
	glEnd();
	glPopMatrix();
}

void VisibleTimer::setRadius(int rad) {

	if ((rad > glutGet(GLUT_WINDOW_WIDTH)) || (rad > glutGet(GLUT_WINDOW_HEIGHT))) {
		radius = DEFAULT_RADIUS;
	}
	else {
		radius = rad;
	}
}

void VisibleTimer::setNumberOfTicks(int totTicks) {

	if (0 > totTicks) {
		numberOfTicks = DEFAULT_TICKS;
	}

	else {
		numberOfTicks = totTicks;
	}
	calcSecondsPerTick();
}

void VisibleTimer::setTimeSeconds(int time) {
	totalTimeInSeconds = time;
	calcSecondsPerTick();
}
void VisibleTimer::setPosition(GLfloat posX, GLfloat posY) {
	if (posX > glutGet(GLUT_WINDOW_WIDTH)) posX = 300.0f;
	if (posY > glutGet(GLUT_WINDOW_HEIGHT)) posY = 300.0f;
	pos.x = posX;
	pos.y = posY;
}


