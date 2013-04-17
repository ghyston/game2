#ifndef __SHADER_H__
#define __SHADER_H__

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

class Shader
{

/*const char gVertexShader[] = 
    "attribute vec4 vPosition;\n"
    "void main() {\n"
    "  gl_Position = vPosition;\n"
    "}\n";

const char gFragmentShader[] = 
    "precision mediump float;\n"
    "void main() {\n"
    "  gl_FragColor = vec4(0.0, 1.0, 0.0, 1.0);\n"
    "}\n";*/
	
public:
	static GLuint createProgram(
		const char* pVertexSource, 
		const char* pFragmentSource
		);
		
		
private:
	static GLuint loadShader(GLenum shaderType, const char* pSource);
	
};

#endif //__SHADER_H__