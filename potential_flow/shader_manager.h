#ifndef SHADER_MANAGER_H
#define SHADER_MANAGER_H

#include <map>

#include "shader.h"

class ShaderManager
{
public:
	static std::map<std::string, Shader> Shaders;
	static Shader LoadShader(const GLchar *vShaderFile, const GLchar *fShaderFile, std::string name);
	static Shader GetShader(std::string name);
	static void Clear();
private:
	ShaderManager() { }
	static Shader loadShaderFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile);
};

#endif