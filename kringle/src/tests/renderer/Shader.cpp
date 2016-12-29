#include <stddef.h>
#include "Shader.h"

GLuint Shader::loadShader(GLenum shaderType, const char* pSource) 
{
    GLuint shader = glCreateShader(shaderType);    
    glShaderSource(shader, 1, &pSource, NULL ); //@todo: 0 should be NULL!
    glCompileShader(shader);
    
    ///-----CHECKING---------
    GLint params = -1;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &params);
	GLchar* info_log;
    if(params == GL_FALSE)
    {
        info_log = new GLchar[100];
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &params);
        glGetShaderInfoLog(shader, 100, &params, info_log);
		printf("Failed to load shader %s", info_log);
		throw 0;
    }
    
    ///-----CHECKING---------
    
    
    return shader;
}

GLuint Shader::createProgram(const char* pVertexSource, const char* pFragmentSource) 
{
    GLuint vertexShader = loadShader(GL_VERTEX_SHADER, pVertexSource);
    GLuint pixelShader = loadShader(GL_FRAGMENT_SHADER, pFragmentSource);    
    GLuint program = glCreateProgram();    
    glAttachShader(program, vertexShader);    
    glAttachShader(program, pixelShader);    
    glLinkProgram(program);
    
    
    ///-----CHECKING---------
    glValidateProgram(program);
    GLint params = -1;
    glGetProgramiv(program, GL_VALIDATE_STATUS, &params);
	GLchar* info_log;
    if(params == GL_FALSE)
    {
		info_log = new GLchar[100];
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &params);
		glGetProgramInfoLog(program, 100, &params, info_log);
	}
    ///-----CHECKING---------
    
    return program;
}