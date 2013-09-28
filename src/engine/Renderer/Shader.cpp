#include "Shader.h"

GLuint Shader::loadShader(GLenum shaderType, const char* pSource) 
{
    GLuint shader = glCreateShader(shaderType);    
    glShaderSource(shader, 1, &pSource, 0); //@todo: 0 should be NULL!
    glCompileShader(shader);    
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
    return program;
}