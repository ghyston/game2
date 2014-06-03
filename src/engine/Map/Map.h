//
//  Map.h
//  Game2
//
//  Created by Stepanov Ilia on 15/03/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__Map__
#define __Game2__Map__

#include "../Common/VecShrPtr.h"
#include "../Common/Vec2i.h"
#include "../Common/Vector2f.h"

#include "PassMap.h"
#include "EntityContainerMap.h"
#include "../GamePlay/Components.h"

class Map
{
public:
	Map() {;}
	
	void InitGrids();
	
	Entities& get_entities_by_coords(Vec2f& pos);
	
	bool GetCellPosibility(Vec2i coords);
	void RepositionEntityToCorrectCell(
		EntityPtr entity, Vec2f old_coords, Vec2f new_coords);
	
	template<typename T>
	EntityPtr findClosestEntityHasCmp(Vec2f coords);
	
	template<typename T>
	EntityPtr getFirstEntityHasCmp();
	
	PassMap pass_map;
	EntityContainerMap entity_map;
	
	float map_width;
	float map_height;
	
private:
	
	static const float entity_grid_cell_size;
	static const float pass_grid_cell_size;
	
};

//////////////////////////////////////////////////////////////////

template<typename T>
EntityPtr Map::findClosestEntityHasCmp(Vec2f coords)
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
					if(!HasCmpt(T, (*it)))
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

template<typename T>
EntityPtr Map::getFirstEntityHasCmp()
{
	for(int i = -entity_map.getWidth(); i <= entity_map.getWidth(); i++)
	{
		for(int j = -entity_map.getHeight(); j <= entity_map.getHeight(); j++)
		{
			Entities& ent = entity_map.getEntitiesFromCell(i, j);
			for (EntityIt it = ent.begin(); it != ent.end(); it++)
			{
				if(!HasCmpt(T, (*it)))
					continue;
				
				return (*it);
			}
		}
	}
	return EntityPtr(NULL);
}


#endif /* defined(__Game2__Map__) */
