#ifndef __SHADER_H__
#define __SHADER_H__

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

class Shader
{

public:
	static GLuint createProgram(
		const char* pVertexSource, 
		const char* pFragmentSource
		);
		
		
private:
	static GLuint loadShader(GLenum shaderType, const char* pSource);
	
};

#endif //__SHADER_H__