//
//  Map.cpp
//  Game2
//
//  Created by Stepanov Ilia on 15/03/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#include "Map.h"

void Map::InitMap(int width_, int height_, float cell_size_)
{
	static const int PassCellsPerMapCell = 5;//@todo: try other values
	height = height_;
	width = width_;
	pass_width = width_ * PassCellsPerMapCell + 1;
	pass_height = height_ * PassCellsPerMapCell + 1;
	cell_size = cell_size_;
	pass_cell_size = cell_size / PassCellsPerMapCell;
}

void Map::checkFroRemovedEntities()
{
	std::map<int, std::map<int, MapCell> >::iterator itX = cells.begin();
	for(; itX != cells.end(); itX++)
	{
		std::map<int, MapCell>::iterator itY = itX->second.begin();
		for(; itY != itX->second.end(); itY++)
		{
			RemoveDeletedObjectsFromContainer(itY->second.entities);
		}
			
	}
}

void Map::addEntity(float pos_x, float pos_y, EntityPtr entity)
{
	int cell_x = (pos_x  / cell_size + width * cell_size / 2);
	int cell_y = (height * cell_size / 2 - pos_y) / cell_size;
	
	if(cell_x >= width || cell_x < 0 ||
	   cell_y >= height || cell_y < 0)
	{
		throw 0;
	}
	
	cells[cell_x][cell_y].entities.push_back(entity);
	
}

Entities& Map::getEntitiesFromCell(float x, float y)
{
	Vec2i cell_coords = getCellIndexes(x, y);
	return getEntitiesFromCell(cell_coords.x, cell_coords.y);
}

Vec2i Map::getCellIndexes(float x, float y)
{
	int cell_x = (x  / cell_size + width * cell_size / 2);
	int cell_y = (height * cell_size / 2 - y) / cell_size;
	return Vec2i(cell_x, cell_y);
}

Entities& Map::getEntitiesFromCell(int x, int y)
{
	return cells[x][y].entities;
}