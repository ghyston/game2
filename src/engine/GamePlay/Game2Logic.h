//
//  Game2Logic.h
//  Game2
//
//  Created by Stepanov Ilia on 05/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__Game2Logic__
#define __Game2__Game2Logic__

#include "../ECS/GameLogic.h"

class Game2Logic : public GameLogic
{
public:
	
	void LoadMap(int width, int height);
	
	void start();
	void stop();
	
	void add_tower(EntityPtr tower);
	void add_energy(EntityPtr energy, EntityPtr generator);
	
	void remove_tower(EntityPtr tower);
	
	void tower_attack(EntityPtr from, EntityPtr to);
	
	template<typename T>
	EntityPtr findClosestEntityHasCmp(Vec2f coords);
	
};

template<typename T>
EntityPtr Game2Logic::findClosestEntityHasCmp(Vec2f coords)
{
	EntityPtr result;
	// Map of entities, sorted by quad distance.
	std::map<float, EntityPtr> closest_entities;
	
	Vec2i center_cell = map.getCellIndexes(coords.x, coords.y);
	int half_rad = 0;
			
	bool allMap = false;
	while(closest_entities.empty() || !allMap)
	{
		int left = center_cell.x - half_rad;
		int top = center_cell.y - half_rad;
		int right = center_cell.x + half_rad;
		int bottom = center_cell.y + half_rad;
		
		int bound_left = std::max(left, 0);
		int bound_top = std::max(top, 0);
		int bound_right = std::min(right, map.getWidth());
		int bound_bottom = std::min(bottom, map.getHeight());
		
		allMap = (bound_left == 0) && (bound_right == map.getWidth()) &&
		(bound_top == 0) && (bound_bottom == map.getHeight());
		
		for(int itX = bound_left; itX <= bound_right; itX++)
		{
			for(int itY = bound_top; itY <= bound_bottom; itY++)
			{
				if((itX > bound_left + 1) &&
				   (itX < bound_right - 1) &&
				   (itY > bound_top + 1) &&
				   (itY < bound_bottom - 1))
					continue;
				
				Entities& ent = map.getEntitiesFromCell(itX, itY);
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

#endif /* defined(__Game2__Game2Logic__) */
