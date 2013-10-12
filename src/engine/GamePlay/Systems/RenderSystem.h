/* 
 * File:   RenderSystem.h
 * Author: Hyston
 *
 * Created on 17 Июнь 2013 г., 16:31
 */

#ifndef __RENDERSYSTEM_H__
#define	__RENDERSYSTEM_H__

#include "../../ECS/BaseSystem.h"
#include "../../ECS/Entity.h"
#include "../Components.h"
#include "../../Renderer/BaseRenderable.h"

/*class IRenderable
{
	virtual void render() = 0;
};*/

class RenderSystem : public BaseSystem
{
	//BaseRenderable renderable;
	
	PositionComponent* position_com;
	RenderComponent* render_com;
	
public:
	
	void update(Entity * entity);

};

#endif	/* __RENDERSYSTEM_H__ */
