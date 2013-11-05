#include <stddef.h>
#include <vector>

#include "RenderSystem.h"
#include "../../GameEngine.h"

void RenderSystem::update(Entity * entity)
{
	if(!entity->has_component<RenderComponent>())
		return;
    
	render_com = entity->get_component<RenderComponent>();
    
	switch (render_com->draw_type)
	{
		case RenderComponent::DRAW_RECT:
		{
			position_com = entity->get_component<PositionComponent>();
			GameEngine::renderer->draw_rect(position_com->position);
		}
		break;
			
		case RenderComponent::DRAW_SMALL_RECT:
		{
			position_com = entity->get_component<PositionComponent>();
			GameEngine::renderer->draw_small_rect(position_com->position);
		}
		break;
			
		case RenderComponent::DRAW_LINE:
		{
			Vec2f pos_1, pos_2; //@todo: check, will alias work!
			connector_com = entity->get_component<ConnectorComponent>();
			
			// Connector has lost one of towers
			// @todo: remove this chaecking to other place!
			if(connector_com->obj_1.pointer == NULL ||
			   connector_com->obj_2.pointer == NULL)
			{
				GameEngine::global_data->logic.remove_entity(entity);
				break;
			}
			
			position_com = connector_com->obj_1.pointer->get_component<PositionComponent>();
			pos_1 = position_com->position;
			position_com = connector_com->obj_2.pointer->get_component<PositionComponent>();
			pos_2 = position_com->position;
			
			GameEngine::renderer->draw_line(pos_1, pos_2);
		}
		break;
			
		case RenderComponent::DRAW_TOWER:
		{
			EnergyStorageComponent * enesto_com;
			enesto_com = entity->get_component<EnergyStorageComponent>();
			position_com = entity->get_component<PositionComponent>();
			GameEngine::renderer->draw_tower(
				position_com->position, enesto_com->get_percentage());
		}
		break;

			
		default:
			break;
	}
    
}


