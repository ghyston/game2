#include <stddef.h>
#include <vector>

#include "RenderSystem.h"
#include "../../GameEngine.h"

void RenderSystem::update(Entity * entity)
{
	if(!entity->has_component<RenderComponent>())
		return;
    
	render_com = entity->get_component<RenderComponent>();
    
    if( render_com->draw_type == RenderComponent::DRAW_RECT)
    {
        position_com = entity->get_component<PositionComponent>();
        
        GameEngine::renderer->draw_rect(position_com->position);
        return;
    }
    
	if( render_com->draw_type == RenderComponent::DRAW_SMALL_RECT)
    {
        position_com = entity->get_component<PositionComponent>();
        
        GameEngine::renderer->draw_small_rect(position_com->position);
        return;
    }
	
    if( render_com->draw_type == RenderComponent::DRAW_LINE)
    {
        Vec2f pos_1, pos_2; //@todo: check, will alias work!
        
        connector_com = entity->get_component<ConnectorComponent>();
        
		// Connector has lost one of towers
		if(connector_com->obj_1.pointer == NULL ||
		   connector_com->obj_2.pointer == NULL)
		{
			GameEngine::global_data->logic.remove_entity(entity);
			return;
		}
		
		
        position_com = connector_com->obj_1.pointer->get_component<PositionComponent>();
        pos_1 = position_com->position;
        position_com = connector_com->obj_2.pointer->get_component<PositionComponent>();
        pos_2 = position_com->position;
		
        GameEngine::renderer->draw_line(pos_1, pos_2);
        return;
    }
    
}


