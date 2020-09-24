#ifndef PROCESS_H
#define PROCESS_H

#include "shader_manager.h"
#include "renderer.h"
//#include "utility.h"

class Process
{
public:
	Shader spriteShader;

	Process();
	~Process();
	void Init();
	void Update();
	void Render();
};

#endif