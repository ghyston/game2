#include <stddef.h>
#include <vector>

#include "RenderSystem.h"

void RenderSystem::update(Entity * entity)
{
	position_com = (PositionComponent*)entity->
	  get_component(ComponentsType::POSITION_COMPONENT);
	render_com = (RenderComponent*)entity->
	  get_component(ComponentsType::RENDER_COMPONENT);
	
	renderable.coords = position_com->position;
	// @todo: not good!
	renderable.color[0] = render_com->color[0];
	renderable.color[1] = render_com->color[1];
	renderable.color[2] = render_com->color[2];
	renderable.color[3] = render_com->color[3];
	renderable.draw_type = render_com->draw_type;
	renderable.vertexes = render_com->vertexes;
	renderable.vertexes_count = render_com->vertexes_count;
	
	renderable.set_shader(render_com->shader);
	
	renderable.Draw();
}


