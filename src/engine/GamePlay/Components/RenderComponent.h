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
	
	RenderComponent() : IComponent(), mesh_id(-1)
	{;}
	
    enum
    {
        DRAW_RECT,
		DRAW_SMALL_RECT,
        DRAW_LINE,
		DRAW_TOWER,
		DRAW_CIRCLE,
		DRAW_TRINAGE,
		DRAW_POLYGON
    } draw_type;
	
	enum
	{
		FIRST_LAYER,
		SECOND_LAYER,
		THIRD_LAYER
	} draw_layer;
	
	int mesh_id;
	
	static int GetTypeImpl() { return ComponentsType::RENDER_COMPONENT; }
};

#endif	/* __RENDERCOMPONENT_H__ */

