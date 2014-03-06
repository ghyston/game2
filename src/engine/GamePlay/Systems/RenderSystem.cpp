#include <stddef.h>
#include <vector>

#include "RenderSystem.h"
#include "../../GameEngine.h"

void RenderSystem::update(EntityPtr entity)
{
	if(!HasCmpt(RenderComponent, entity))
		return;
    
	GetCmpt(RenderComponent, render_com, entity);
    
	switch (render_com->draw_type)
	{
		case RenderComponent::DRAW_RECT:
		{
			GetCmpt(PositionComponent, position_com, entity);
			GameEngine::renderer->draw_rect(position_com->position);
		}
		break;
			
		case RenderComponent::DRAW_SMALL_RECT:
		{
			GetCmpt(PositionComponent, position_com, entity);
			GameEngine::renderer->draw_small_rect(position_com->position);
		}
		break;
			
		case RenderComponent::DRAW_LINE:
		{
			//@todo: this was test code for connections,
			//draw just regular line
			return;
			
			/*Vec2f pos_1, pos_2; //@todo: check, will alias work!
			GetCmpt(ConnectorComponent, connector_com, entity);
			
			// Connector has lost one of towers
			// @todo: remove this chaecking to other place!
			if(!connector_com->obj_1.IsSet() ||
			   !connector_com->obj_2.IsSet())
			{
				GameEngine::global_data->logic.remove_entity(entity);
				break;
			}
			
			GetCmpt(PositionComponent, pos_com_1, connector_com->obj_1.Get());
			pos_1 = pos_com_1->position;
			
			GetCmpt(PositionComponent, pos_com_2, connector_com->obj_2.Get());
			pos_2 = pos_com_2->position;
			
			GameEngine::renderer->draw_line(pos_1, pos_2);*/
		}
		break;
			
		case RenderComponent::DRAW_TOWER:
		{
			GetCmpt(EnergyStorageComponent, enesto_com, entity);
			GetCmpt(PositionComponent, position_com, entity);
			GetCmpt(PlayerIdComponent, plIdCmpt, entity);
			
			bool is_enemy = (plIdCmpt->player_id == GlobalData::PLAYER_ID_2);

			GameEngine::renderer->draw_tower(
				position_com->position, enesto_com->get_percentage(), is_enemy);
			
			GetCmpt(NodeComponent, node_com, entity);
			EntityIt it = node_com->children.begin();
			while (it != node_com->children.end())
			{
				//@todo: not optimizable, create ref to cmpt every step!
				GetCmpt(PositionComponent, pos_com, (it->get()));
				GameEngine::renderer->draw_line(position_com->position, pos_com->position);
				it++;
			}
		}
		break;
			
		case RenderComponent::DRAW_CIRCLE:
		{
			// @todo: get rad from it and use!
//			GetCmpt(EnergyGeneratorComponent, en_gen_cmpt, entity);
			GetCmpt(PositionComponent, pos_com, entity);
			GameEngine::renderer->draw_circle(pos_com->position);
		}
		break;

			
		default:
			break;
	}
    
}


