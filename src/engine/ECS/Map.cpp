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
	pass_width = width_ * PassCellsPerMapCell;
	pass_height = height_ * PassCellsPerMapCell;
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

void Map::BlockPassCells(const Vec2f& left_top, const Vec2f& right_bottom)
{
	Vec2i iLT = getPassCellIndexes(left_top);
	Vec2i iRB = getPassCellIndexes(right_bottom);
	
	for(int i = iLT.x; i <= iRB.x; i++)
	{
		for(int j = iRB.y; j <= iLT.y; j++)
		{
			SetPass(false, Vec2i(i,j));
		}
	}
}

bool Map::CheckCellsPass(const Vec2f& left_top, const Vec2f& right_bottom)
{
	Vec2i iLT = getPassCellIndexes(left_top);
	Vec2i iRB = getPassCellIndexes(right_bottom);
	
	for(int i = iLT.x; i <= iRB.x; i++)
	{
		for(int j = iRB.y; j <= iLT.y; j++)
		{
			if(!isCellPass(Vec2i(i, j)))
				return false;
		}
	}
	return true;
}

Vec2i Map::getCellIndexes(float x, float y) const
{
	//@todo: check!
	int cell_x = (width * cell_size / 2 - x) / cell_size;
	int cell_y = (height * cell_size / 2 - y) / cell_size;
	return Vec2i(cell_x, cell_y);
}

Vec2i Map::getPassCellIndexes(const Vec2f& coords) const
{
	int cell_x = (pass_width * pass_cell_size / 2 + coords.x)  / pass_cell_size;
	int cell_y = (pass_height * pass_cell_size / 2 + coords.y) / pass_cell_size;
	return Vec2i(cell_x, cell_y);
}

Entities& Map::getEntitiesFromCell(int x, int y)
{
	return cells[x][y].entities;
}

bool Map::isCellPass(Vec2i coords)
{
	return pass_cells[coords.x][coords.y].passability;
}

bool Map::isCellPass(Vec2f coords)
{
	Vec2i iCoords = getPassCellIndexes(coords);
	return isCellPass(iCoords);
}

void Map::SetPass(bool passability, Vec2i coords)
{
	pass_cells[coords.x][coords.y].passability = passability;
}

void Map::SetPass(bool passability, Vec2f coords)
{
	return SetPass(passability, getPassCellIndexes(coords));
}
