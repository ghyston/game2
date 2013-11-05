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
#include "TowerRenderable.h"
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
    
    void draw_small_rect(Vec2f coords);
    
    void draw_line(Vec2f coord_1, Vec2f coord_2);
    
    void draw_grid();
	
	//@note: energy should be 0.0f .. 1.0f!
	void draw_tower(Vec2f coords, float energy);
	
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
	
	void init_tower();
    
    RectRenderable * rect;
    
	//@todo: not good
    RectRenderable * small_rect;
    
    Grid * grid;
    
    LineRenderable * line;
	
	TowerRenderable * tower_rend;

};

#endif //__RENDERER_H__
