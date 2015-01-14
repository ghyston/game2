//
//  Map.cpp
//  Game2
//
//  Created by Stepanov Ilia on 15/03/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#include "Map.h"
#include "../GlobalData.h"

const float Map::entity_grid_cell_size = 0.5f;
const float Map::pass_grid_cell_size = 0.03f;

Entities& Map::get_entities_by_coords(Vec2f& pos)
{
	return entity_map.getEntitiesFromCell(pos.x, pos.y);
}

bool Map::GetCellPosibility(Vec2i coords)
{
	return pass_map.isCellPass(coords);
}

void Map::RepositionEntityToCorrectCell(
	EntityPtr entity, Vec2f old_coords, Vec2f new_coords)
{
	Vec2i old_cell_indx = entity_map.getIndexesByCoords(old_coords);
	Vec2i new_cell_indx = entity_map.getIndexesByCoords(new_coords);
	
	if(old_cell_indx == new_cell_indx)
		return;
	
	entity_map.removeEntityFromCell(old_coords.x, old_coords.y, entity);
	entity_map.addEntity(new_coords.x, new_coords.y, entity);
}

void Map::InitGrids()
{
	entity_map.InitMap(
		map_width / entity_grid_cell_size ,
		map_height / entity_grid_cell_size , entity_grid_cell_size);
	
	pass_map.InitMap(
		map_width / pass_grid_cell_size,
		map_height / pass_grid_cell_size, pass_grid_cell_size);
}

//@todo: this is just almost copy-paste from findClosestEntityHasCmp!
EntityPtr Map::getClosestEnemyTower(Vec2f coords)
{
	EntityPtr result;
	// Map of entities, sorted by quad distance.
	std::map<float, EntityPtr> closest_entities;
	
	Vec2i center_cell = entity_map.getIndexesByCoords(coords);
	int half_rad = 0;
	
	bool allMap = false;
	int additional_iterations = 2; // To be sure, that we hav all entity in radius.
	while((closest_entities.empty() || additional_iterations > 0) && !allMap)
	{
		if(!closest_entities.empty())
			additional_iterations--;
		
		int left = center_cell.x - half_rad;
		int top = center_cell.y + half_rad;
		int right = center_cell.x + half_rad;
		int bottom = center_cell.y - half_rad;
		
		int bound_left = std::max(left, -entity_map.getWidth());
		int bound_top = std::min(top, entity_map.getHeight());
		int bound_right = std::min(right, entity_map.getWidth());
		int bound_bottom = std::max(bottom, -entity_map.getHeight());
		
		allMap =
		(bound_left <= -entity_map.getWidth()) &&
		(bound_right >= entity_map.getWidth()) &&
		(bound_top >= entity_map.getWidth()) &&
		(bound_bottom <= -entity_map.getHeight());
		
		for(int itX = bound_left; itX <= bound_right; itX++)
		{
			for(int itY = bound_bottom; itY <= bound_top; itY++)
			{
				if((itX > bound_left) &&
				   (itX < bound_right) &&
				   (itY < bound_top ) &&
				   (itY > bound_bottom))
					continue;
				
				Entities& ent = entity_map.getEntitiesFromCell(itX, itY);
				for (EntityIt it = ent.begin(); it != ent.end(); it++)
				{
					if(!HasCmpt(EnergyStorageComponent, (*it)))
						continue;
					if(!HasCmpt(PlayerIdComponent, (*it)))
						continue;
					
					//@todo: enemy here is actual player!
					GetCmpt(PlayerIdComponent, playId_com, (*it));
					if(playId_com->player_id == GlobalData::PLAYER_ID_2)
						continue;
					
					GetCmpt(PositionComponent, pos_com, (*it));
					float quad_dist = quad_distance(pos_com->position, coords);
					closest_entities[quad_dist] = *it;
				}
			}
		}
		half_rad++;
	}
	
	if(!closest_entities.empty())
	{
		result = closest_entities.begin()->second;
	}
	return result;
}