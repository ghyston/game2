#ifndef __RENDERER_H__
#define __RENDERER_H__

//#include <GLES2/gl2.h>
//#include <GLES2/gl2ext.h>
#include <OpenGL/gl.h>
#include <math.h>
#include "Shader.h"
#include "Camera.h"
#include "../Common/Matrix4f.h"
#include "RectRenderable.h"
#include "LineRenderable.h"
#include "Grid.h"

/**
 * Main call for draw graphix.
 */
class Renderer 
{
public:
	
	Renderer();
	
	~Renderer();
	
    void init();
    
    void resize(int width, int height);

	void clear_frame();
    
    void draw_rect(Vec2f coords);
    
    void draw_line(Vec2f coord_1, Vec2f coord_2);
    
    void draw_grid();
	
private:
    
    void init_shaders();
    
    GLuint get_simple_shader()	{ return simple_shader; }
    
	Matrix4f* ortho;
	Matrix4f* mx_translate;
	Matrix4f* mx_scale;
	Matrix4f* mx_rotate;
	

    void setup_ortho(
            float left, float right,
            float bottom, float top,
            float near = -1.0f, float far = 1.0f);

    GLuint simple_shader;
    GLuint gvPositionHandle;
    
    //Primitives.
    
    void init_rect();
    
    void init_grid();
    
    void init_line();
    
    RectRenderable * rect;
    
    Grid * grid;
    
    LineRenderable * line;

};

#endif //__RENDERER_H__
