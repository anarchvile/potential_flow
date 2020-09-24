#ifndef RENDERER_H
#define RENDERER_H

#include "field.h"
#include "shader.h"
#include "utility.h"

class Renderer
{
public:
	//constructor (initialize shaders/shapes)
	Renderer(Shader &shader);
	//destructor
	~Renderer();
	//initialize and configure the object's buffer and vertex attributes
	void InitRenderData();
	void UpdateRenderData();
	//render an object with proper coloring
	void Draw();
private:
	//render state
	Shader shader;
	GLuint __pointVAO, __originVAO, __streamVAO, __backgroundVAO, __keyVAO, __charVAO;
	//initialize the VBOs and VAOs
};

#endif
