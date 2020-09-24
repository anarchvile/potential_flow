#include "pch.h"
#include "process.h"
#include "main.h"
#include <iostream>

#include <glut.h>

Renderer *renderer;

Process::Process()
{

}

Process::~Process()
{
	delete renderer;
}

void Process::Init()
{
	field.InitializeField();
	field.UpdateField(field.points);
	utility.InitializeKey();
	ShaderManager::LoadShader("vertex.txt", "fragment.txt", "sprite");
	spriteShader = ShaderManager::GetShader("sprite");
	glm::mat4 __projection = glm::ortho(0.0f, (float)utilParams.windowWidth, (float)utilParams.windowHeight, 0.0f, -1.0f, 1.0f);
	spriteShader.Use().SetMatrix4("projection", __projection);
	spriteShader.Use().SetInt("pixelSize", field.pixelSize);
	renderer = new Renderer(spriteShader);
}

void Process::Update()
{
	if (utilParams.windowWidth != glutGet(GLUT_WINDOW_WIDTH))
	{
		field.updateWindow = field.updateField = true;
		glm::mat4 __projection = glm::ortho(0.0f, (float)glutGet(GLUT_WINDOW_WIDTH), (float)glutGet(GLUT_WINDOW_HEIGHT), 0.0f, -1.0f, 1.0f);
		spriteShader.SetMatrix4("projection", __projection);
		utilParams.windowWidth = glutGet(GLUT_WINDOW_WIDTH);
		field.InitializeField();
		utility.UpdateKey();
		field.ReinitializeField(field.points);
	}

	else if (utilParams.windowHeight != glutGet(GLUT_WINDOW_HEIGHT))
	{
		field.updateWindow = field.updateField = true;
		glm::mat4 __projection = glm::ortho(0.0f, (float)glutGet(GLUT_WINDOW_WIDTH), (float)glutGet(GLUT_WINDOW_HEIGHT), 0.0f, -1.0f, 1.0f);
		spriteShader.SetMatrix4("projection", __projection);
		utilParams.windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
		field.InitializeField();
		utility.UpdateKey();
		field.ReinitializeField(field.points);
	}

	else field.updateWindow = false;

	if (input.upButton)
	{
		spriteShader.Use().SetInt("pixelSize", field.pixelSize);
		//input.upButton = false;
		field.InitializeField();
		field.ReinitializeField(field.points);
	}

	if (input.downButton)
	{
		spriteShader.Use().SetInt("pixelSize", field.pixelSize);
		//input.downButton = false;
		field.InitializeField();
		field.ReinitializeField(field.points);
	}

	field.UpdateField(field.points);

	if (utilParams.clear)
	{
		field.flowType.clear();
		field.InitializeField();
		utilParams.clear = false;
		field.updateField = true;
	}
}

void Process::Render()
{
	renderer->UpdateRenderData();
	renderer->Draw();
}