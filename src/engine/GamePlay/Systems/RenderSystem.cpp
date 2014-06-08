#include <stddef.h>
#include <vector>
#include <math.h>

#include "RenderSystem.h"
#include "../../GameEngine.h"

void RenderSystem::pre_step()
{
	entities_to_draw.clear();
}

void RenderSystem::update(EntityPtr entity)
{
	if(!HasCmpt(RenderComponent, entity))
		return;
    
	GetCmpt(RenderComponent, render_com, entity);
	entities_to_draw[render_com->draw_layer].push_back(entity);
}

void RenderSystem::post_step()
{
	std::map<int, Entities>::iterator it = entities_to_draw.begin();
	
	for(; it != entities_to_draw.end(); it++)
	{
		EntityIt entIt = it->second.begin();
		for(; entIt != it->second.end(); entIt++)
		{
			EntityPtr& entity = *entIt;
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
					GetCmpt(PositionComponent, pos_com, entity);
					GameEngine::renderer->draw_circle(pos_com->position);
				}
				break;
					
				case RenderComponent::DRAW_TRINAGE:
				{
					GetCmpt(PositionComponent, pos_com, entity);
					GetCmpt(MovementComponent, mov_com, entity);
					
					//@todo: remove this strange angle calculation!
					float angleRad = atanf(mov_com->speed.y / mov_com->speed.x);
					float angle = radiansToDegrees(angleRad);
					if(isnan(angle))
						angle = 0.0f;
					else
					if(mov_com->speed.x < 0)
					{
						angle += 180;
					}
					
					//@todo: fix, tan cannot show right quater!
					
					GameEngine::renderer->DrawTriangle(pos_com->position, angle);
				}
				break;
					
				case RenderComponent::DRAW_POLYGON:
				{
					GetCmpt(PositionComponent, pos_com, entity);
					GameEngine::renderer->DrawPolygon(pos_com->position, render_com->mesh_id);
				}
				break;
			
				default:
					break;
			}
		}
	}
}


