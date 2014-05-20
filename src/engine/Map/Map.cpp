//
//  Map.cpp
//  Game2
//
//  Created by Stepanov Ilia on 15/03/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#include "Map.h"

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
	/*Vec2i old_cell_indx = entity_map.getIndexesByCoords(old_coords);
	Vec2i new_cell_indx = entity_map.getIndexesByCoords(new_coords);
	
	if(old_cell_indx == new_cell_indx)
		return;*/
	
	entity_map.removeEntityFromCell(old_coords.x, old_coords.y, entity);
	entity_map.addEntity(new_coords.x, new_coords.y, entity);


}