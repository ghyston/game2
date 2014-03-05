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
	
    enum
    {
        DRAW_RECT,
		DRAW_SMALL_RECT,
        DRAW_LINE,
		DRAW_TOWER,
		DRAW_CIRCLE
    } draw_type;
	
	static int GetTypeImpl() { return ComponentsType::RENDER_COMPONENT; }
	
/*	float * vertexes;
	int vertexes_count;	
	float color [4];
	GLenum draw_type;	
	GLuint shader;*/
};

#endif	/* __RENDERCOMPONENT_H__ */

