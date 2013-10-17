#include <stddef.h>
#include <vector>

#include "RenderSystem.h"
#include "../../GameEngine.h"

void RenderSystem::update(Entity * entity)
{
    //@todo: check, is there a render/position component!
	
	if(!entity->has_component(ComponentsType::RENDER_COMPONENT))
		return;
    
	render_com = (RenderComponent*)entity->
	  get_component(ComponentsType::RENDER_COMPONENT);
    
    if( render_com->draw_type == RenderComponent::DRAW_RECT)
    {
        position_com = (PositionComponent*)entity->
            get_component(ComponentsType::POSITION_COMPONENT);
        
        GameEngine::renderer->draw_rect(position_com->position);
        return;
    }
    
	if( render_com->draw_type == RenderComponent::DRAW_SMALL_RECT)
    {
        position_com = (PositionComponent*)entity->
		get_component(ComponentsType::POSITION_COMPONENT);
        
        GameEngine::renderer->draw_small_rect(position_com->position);
        return;
    }
	
    if( render_com->draw_type == RenderComponent::DRAW_LINE)
    {
        Vec2f pos_1, pos_2; //@todo: check, will alias work!
        
        connector_com = (ConnectorComponent*)entity->
            get_component(ComponentsType::CONNECTOR_COMPONENT);
        
        position_com = (PositionComponent*)connector_com->obj_1->get_component(ComponentsType::POSITION_COMPONENT);
        
        pos_1 = position_com->position;
        
        position_com = (PositionComponent*)connector_com->obj_2->get_component(ComponentsType::POSITION_COMPONENT);
        
        pos_2 = position_com->position;
        GameEngine::renderer->draw_line(pos_1, pos_2);
        return;
    }
    
}


