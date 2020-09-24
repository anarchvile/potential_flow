#ifndef SHADER_H
#define SHADER_H

#include <string>

#include <GL/glew.h>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>

class Shader
{
public:
	GLuint ID;
	Shader() {}
	Shader &Use();
	void Compile(const GLchar *vertexShaderSource, const GLchar *fragmentShaderSource);
	void SetInt(const GLchar *name, GLint &value, GLboolean useShader = false);
	void SetFloat(const GLchar *name, GLfloat &value, GLboolean useShader = false);
	void SetVector3(const GLchar *name, const glm::vec4 &value, GLboolean useShader = false);
	void SetVector4(const GLchar *name, const glm::vec4 &value, GLboolean useShader = false);
	void SetMatrix4(const GLchar *name, const glm::mat4 &matrix, GLboolean useShader = false);
private:
	void checkCompileErrors(GLuint object, std::string type);
};

#endif