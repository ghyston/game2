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

class RenderSystem : public BaseSystem
{
public:
	
	virtual void pre_step();
	virtual void update(EntityPtr entity);
	virtual void post_step();

	//@todo: reserve?
	std::map<int, Entities> entities_to_draw;

};

#endif	/* __RENDERSYSTEM_H__ */
