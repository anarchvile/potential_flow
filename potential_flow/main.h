#ifndef MAIN_H
#define MAIN_H

//#include <gl/glew.h>
//#include <glut.h>
#include <glm.hpp>

struct Input
{
	bool leftMouseButtonPressed, leftMouseButtonDown, leftMouseButtonUp;
	bool rightMouseButtonPressed, rightMouseButtonDown, rightMouseButtonUp;
	glm::vec2 initialLeftMousePosition, leftMousePosition, initialRightMousePosition;
	bool upButton, downButton;
};

extern Input input;

#endif