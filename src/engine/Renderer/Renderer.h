#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <math.h>
#include "Shader.h"

/**
* Main call for draw graphix.
*/
class Renderer
{
private:
	int screen_width;
	int screen_height;
	
	void draw_grid();
	void init_shaders();
	
	void setup_ortho(
		float left, float right, 
		float bottom, float top, 
		float near = -1.0f, float far = 1.0f);
	
	GLuint simple_shader;
	GLuint gvPositionHandle;

public:
	void init(int width, int height);
	
	void render_frame();
	
};

#endif //__RENDERER_H__