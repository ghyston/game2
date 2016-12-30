#ifndef __SHADER_H__
#define __SHADER_H__

#include "GlInclude.h"

#include <string.h>
#include <sstream>
//@todo: create simple log!!

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