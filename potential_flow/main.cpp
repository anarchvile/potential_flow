#include "pch.h"
#include "process.h"
#include "main.h"

#include <iostream>
#include <gl/glew.h>
#include <glm.hpp>
#include <glut.h>

//#include <iostream>

#define FPS 30

Input input;
Process process;

void changeSize(int w, int h) {

	if (h == 0) h = 1;
	float ratio = w / h;

	//use the projection matrix
	glMatrixMode(GL_PROJECTION);

	//reset matrix
	glLoadIdentity();

	//set the viewport to be the entire window
	glViewport(0, 0, w, h);

	//set the correct perspective
	gluOrtho2D(0, 500, 0, 500);

	//get back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	process.Update();
	process.Render();

	glutSwapBuffers();
}

void mousePressed(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		input.initialLeftMousePosition = glm::vec2(x, y);
		input.leftMousePosition = glm::vec2(x, y);
		input.leftMouseButtonPressed = input.leftMouseButtonDown = true;
		input.leftMouseButtonUp = false;
	}

	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		input.leftMouseButtonDown = false;
		input.leftMouseButtonUp = true;
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		input.initialRightMousePosition = glm::vec2(x, y);
		input.rightMouseButtonPressed = input.rightMouseButtonDown = true;
		input.rightMouseButtonUp = false;
	}

	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
	{
		input.rightMouseButtonDown = false;
		input.rightMouseButtonUp = true;
	}
}

void mouseMove(int x, int y)
{
	input.leftMousePosition = glm::vec2(x, y);
}

void keyPressed(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'u':
		field.uniformBool = true;
		field.sourceBool = false;
		field.vortexBool = false;
		field.doubletBool = false;
		break;
	case 's':
		field.uniformBool = false;
		field.sourceBool = true;
		field.vortexBool = false;
		field.doubletBool = false;
		break;
	case 'g':
		field.uniformBool = false;
		field.sourceBool = false;
		field.vortexBool = false;
		field.doubletBool = false;
		field.sinkBool = true;
		break;
	case 'v':
		field.uniformBool = false;
		field.sourceBool = false;
		field.vortexBool = true;
		field.doubletBool = false;
		break;
	case 'd':
		field.uniformBool = false;
		field.sourceBool = false;
		field.vortexBool = false;
		field.doubletBool = true;
		break;
	case 'o':
		field.showOrigin = !field.showOrigin;
		break;
	case 'c':
		utilParams.clear = true;
		break;
	case 32:
		if (field.showBackground < 2) ++field.showBackground;
		else field.showBackground = 0;
		field.change = true;
		break;
	case 127:
		field.del = true;
		break;
	}
}

void specialKeyPressed(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		field.pixelSize += 1;
		input.upButton = true;
		input.downButton = false;
		break;
	case GLUT_KEY_DOWN:
		if (field.pixelSize > 1) field.pixelSize -= 1;
		else field.pixelSize = 1;
		input.upButton = false;
		input.downButton = true;
		break;
	}
}

void idle(int)
{
	glutIgnoreKeyRepeat(1);
	glutMouseFunc(mousePressed);
	glutMotionFunc(mouseMove);
	glutKeyboardFunc(keyPressed);
	glutSpecialFunc(specialKeyPressed);
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, idle, 0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Potential Flow");

	glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
	glutDisplayFunc(renderScene);
	process.Init();
	
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, idle, 0);

	glutMainLoop();

	return 1;
}