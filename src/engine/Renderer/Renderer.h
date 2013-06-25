#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <math.h>
#include "Shader.h"
//#include "Grid.h"
#include "Camera.h"
#include "SceneObject.h"

/**
 * Main call for draw graphix.
 */
class Renderer 
{
public:
	
	Renderer() {;}
	
	~Renderer();
	
    void init(int width, int height);

    //void render_frame();
	
	void clear_frame();
	
	//void move_camera(Vec2f diff);
	
	//void set_default_shader(BaseRenderable * object);	
	
	GLuint get_simple_shader()	{ return simple_shader; }
	
	
private:
    
    void init_shaders();

  //  Grid grid;
    
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
	
//	void draw_game_play();

};

#endif //__RENDERER_H__
