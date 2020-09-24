#include "pch.h"
#include "renderer.h"
#include "main.h"
#include <iostream>

#include <glut.h>
#include "character_renderer.h"

GLuint __pointVBO[2], __originVBO[2], __streamVBO[2], __backgroundVBO[2], __keyVBO[2], __charVBO[2];
GLuint VAO, VBO;
int num = 0;
std::vector<float> vertices;
std::vector<float> colors;

Renderer::Renderer(Shader &shader)
{
	this->shader = shader;
	this->InitRenderData();
}

Renderer::~Renderer()
{
	glDeleteVertexArrays(1, &this->__pointVAO);
	glDeleteVertexArrays(1, &this->__originVAO);
	glDeleteVertexArrays(1, &this->__streamVAO);
	glDeleteVertexArrays(1, &this->__backgroundVAO);
	glDeleteVertexArrays(1, &this->__keyVAO);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Renderer::InitRenderData()
{	
	CharacterGeneration::LineInitialize();

	glGenVertexArrays(1, &this->__pointVAO);
	glBindVertexArray(this->__pointVAO);
	glGenBuffers(2, __pointVBO);
	glBindBuffer(GL_ARRAY_BUFFER, __pointVBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * field.points.size(), &field.points[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GL_FLOAT), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, __pointVBO[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * field.pointsColors.size(), &field.pointsColors[0], GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (void*)0);
	glEnableVertexAttribArray(1);

	glGenVertexArrays(1, &this->__originVAO);
	glBindVertexArray(this->__originVAO);
	glGenBuffers(2, __originVBO);
	glBindBuffer(GL_ARRAY_BUFFER, __originVBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * field.origin.size(), &field.origin[0], GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GL_FLOAT), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, __originVBO[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * field.originColors.size(), &field.originColors[1], GL_DYNAMIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (void*)0);
	glEnableVertexAttribArray(1);

	glGenVertexArrays(1, &this->__backgroundVAO);
	glBindVertexArray(this->__backgroundVAO);
	glGenBuffers(2, __backgroundVBO);
	glBindBuffer(GL_ARRAY_BUFFER, __backgroundVBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * field.background.size(), &field.background[0], GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GL_FLOAT), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, __backgroundVBO[1]);
	if (field.showBackground == 0) glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * field.streamColors.size(), 0, GL_DYNAMIC_DRAW);
	else if (field.showBackground == 1) glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * field.streamColors.size(), &field.streamColors[0], GL_DYNAMIC_DRAW);
	else if (field.showBackground == 2) glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * field.potentialColors.size(), &field.potentialColors[0], GL_DYNAMIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (void*)0);
	glEnableVertexAttribArray(1);

	glGenVertexArrays(1, &this->__keyVAO);
	glBindVertexArray(this->__keyVAO);
	glGenBuffers(2, __keyVBO);
	glBindBuffer(GL_ARRAY_BUFFER, __keyVBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * utilParams.keyPoints.size(), &utilParams.keyPoints[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GL_FLOAT), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, __keyVBO[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * utilParams.keyColors.size(), &utilParams.keyColors[0], GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (void*)0);
	glEnableVertexAttribArray(1);

	glGenVertexArrays(1, &__charVAO);
	glBindVertexArray(__charVAO);
	glGenBuffers(2, __charVBO);
	glBindBuffer(GL_ARRAY_BUFFER, __charVBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * CharacterGeneration::charLinePos.size(), &CharacterGeneration::charLinePos[0], GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GL_FLOAT), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, __charVBO[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * CharacterGeneration::charLineColor.size(), &CharacterGeneration::charLineColor[0], GL_DYNAMIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (void*)0);
	glEnableVertexAttribArray(1);
}

void Renderer::UpdateRenderData()
{
	if (field.updateField || field.updateWindow || input.leftMouseButtonDown || field.change || input.rightMouseButtonDown || input.upButton || input.downButton || field.del)
	{
		int count = 0;
		field.change = false;
		field.del = false;

		glBindVertexArray(this->__pointVAO);
		glBindBuffer(GL_ARRAY_BUFFER, __pointVBO[0]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * field.points.size(), NULL, GL_DYNAMIC_DRAW);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GL_FLOAT) * field.points.size(), &field.points[0]);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, __pointVBO[1]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * field.pointsColors.size(), NULL, GL_DYNAMIC_DRAW);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GL_FLOAT) * field.pointsColors.size(), &field.pointsColors[0]);
		glEnableVertexAttribArray(1);

		glBindVertexArray(this->__originVAO);
		glBindBuffer(GL_ARRAY_BUFFER, __originVBO[0]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * field.origin.size(), NULL, GL_DYNAMIC_DRAW);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GL_FLOAT) * field.origin.size(), &field.origin[0]);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, __originVBO[1]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * field.originColors.size(), NULL, GL_DYNAMIC_DRAW);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GL_FLOAT) * field.originColors.size(), &field.originColors[0]);
		glEnableVertexAttribArray(1);

		glBindVertexArray(this->__backgroundVAO);
		glBindBuffer(GL_ARRAY_BUFFER, __backgroundVBO[0]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * field.background.size(), NULL, GL_DYNAMIC_DRAW);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GL_FLOAT) * field.background.size(), &field.background[0]);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, __backgroundVBO[1]);

		if (field.showBackground == 0)
		{
			glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * 0, NULL, GL_DYNAMIC_DRAW);
			glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GL_FLOAT) * 0, NULL);
			CharacterGeneration::charLinePos.clear(); CharacterGeneration::charLineColor.clear();
			CharacterGeneration::LoadLineChar("Velocity", 10, 10, 3, 4, false, true, 0);
			CharacterGeneration::LoadLineChar("Max:" + std::to_string(field.maxVel), utilParams.keyPoints[0] - 10, utilParams.keyPoints[1] - 9, 1, 6, false, true, 8);
			CharacterGeneration::LoadLineChar("Min:" + std::to_string(field.minVel), utilParams.keyPoints[0] - 10, utilParams.keyPoints[utilParams.keyPoints.size() - 1] + 5, 1, 6, false, true, 8);
		}
		else if (field.showBackground == 1)
		{
			glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * field.streamColors.size(), NULL, GL_DYNAMIC_DRAW);
			glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GL_FLOAT) * field.streamColors.size(), &field.streamColors[0]);
			CharacterGeneration::charLinePos.clear(); CharacterGeneration::charLineColor.clear();
			CharacterGeneration::LoadLineChar("Stream", 10, 10, 3, 4, true, true, 0);
			CharacterGeneration::LoadLineChar("Max:" + std::to_string(field.maxStream), utilParams.keyPoints[0] - 10, utilParams.keyPoints[1] - 9, 1, 6, true, true, 8);
			CharacterGeneration::LoadLineChar("Min:" + std::to_string(field.minStream), utilParams.keyPoints[0] - 10, utilParams.keyPoints[utilParams.keyPoints.size() - 1] + 5, 1, 6, true, true, 8);
		}
		else if (field.showBackground == 2)
		{
			glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * field.potentialColors.size(), NULL, GL_DYNAMIC_DRAW);
			glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GL_FLOAT) * field.potentialColors.size(), &field.potentialColors[0]);
			CharacterGeneration::charLinePos.clear(); CharacterGeneration::charLineColor.clear();
			CharacterGeneration::LoadLineChar("Potential", 10, 10, 3, 4, true, true, 0);
			CharacterGeneration::LoadLineChar("Max:" + std::to_string(field.maxPotential), utilParams.keyPoints[0] - 10, utilParams.keyPoints[1] - 9, 1, 6, true, true, 8);
			CharacterGeneration::LoadLineChar("Min:" + std::to_string(field.minPotential), utilParams.keyPoints[0] - 10, utilParams.keyPoints[utilParams.keyPoints.size() - 1] + 5, 1, 6, true, true, 8);
		}
		
		input.upButton = input.downButton = false;

		glEnableVertexAttribArray(1);

		glBindVertexArray(__charVAO);
		glBindBuffer(GL_ARRAY_BUFFER, __charVBO[0]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * CharacterGeneration::charLinePos.size(), NULL, GL_DYNAMIC_DRAW);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GL_FLOAT) * CharacterGeneration::charLinePos.size(), &CharacterGeneration::charLinePos[0]);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, __charVBO[1]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * CharacterGeneration::charLineColor.size(), NULL, GL_DYNAMIC_DRAW);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GL_FLOAT) * CharacterGeneration::charLineColor.size(), &CharacterGeneration::charLineColor[0]);
		glEnableVertexAttribArray(1);

		if (field.updateWindow)
		{
			glBindVertexArray(this->__keyVAO);
			glBindBuffer(GL_ARRAY_BUFFER, __keyVBO[0]);
			glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * utilParams.keyPoints.size(), NULL, GL_DYNAMIC_DRAW);
			glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GL_FLOAT) * utilParams.keyPoints.size(), &utilParams.keyPoints[0]);
			glEnableVertexAttribArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, __keyVBO[1]);
			glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * utilParams.keyColors.size(), NULL, GL_DYNAMIC_DRAW);
			glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GL_FLOAT) * utilParams.keyColors.size(), &utilParams.keyColors[0]);
			glEnableVertexAttribArray(1);
		}
	}
}

void Renderer::Draw()
{
	this->shader.Use();
	glBindVertexArray(this->__backgroundVAO);
	glDrawArrays(GL_POINTS, 0, field.background.size());
	glBindVertexArray(0);

	glBindVertexArray(this->__pointVAO);
	glDrawArrays(GL_LINES, 0, field.points.size());
	glBindVertexArray(0);

	if (field.showOrigin)
	{
		glBindVertexArray(this->__originVAO);
		glDrawArrays(GL_POINTS, 0, field.origin.size());
		glBindVertexArray(0);
	}

	glBindVertexArray(this->__keyVAO);
	glDrawArrays(GL_TRIANGLES, 0, utilParams.keyPoints.size());
	glBindVertexArray(0);

	glBindVertexArray(this->__charVAO);
	glDrawArrays(GL_LINES, 0, CharacterGeneration::charLinePos.size());
	glBindVertexArray(0);
}