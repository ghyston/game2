/* 
 * File:   RenderComponent.h
 * Author: Hyston
 *
 * Created on 23 Июнь 2013 г., 9:55
 */

#ifndef __RENDERCOMPONENT_H__
#define	__RENDERCOMPONENT_H__

//#include <GLES2/gl2.h>
//#include <GLES2/gl2ext.h>
//#include <OpenGL/gl.h>

class RenderComponent : public IComponent
{
public:
	
	int get_id() { return ComponentsType::RENDER_COMPONENT; }
    
    enum
    {
        DRAW_RECT,
		DRAW_SMALL_RECT,
        DRAW_LINE
    } draw_type;
	
/*	float * vertexes;
	int vertexes_count;	
	float color [4];
	GLenum draw_type;	
	GLuint shader;*/
};

#endif	/* __RENDERCOMPONENT_H__ */

