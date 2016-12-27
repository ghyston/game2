//
//  PathFinder.cpp
//  Game2
//
//  Created by Stepanov Ilia on 23/03/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#include "PathFinder.h"
#include "../GameEngine.h"
#include <algorithm>
#include <math.h>

const int PathFinder::COST_AXIS = 10;
const int PathFinder::COST_DIAG = 14;

PathFinder::~PathFinder()
{
	delete [] cells;
}

bool PathFinder::CalcPathForUnit(std::vector<Vec2i>& points, Vec2f start, Vec2f end, const Entities& excluded)
{
	PathFinderParams params;
	Map* map = GameEngine::get_data()->logic.getMap();
	params.source = map->pass_map.getIndexesByCoords(start);
	params.destination = map->pass_map.getIndexesByCoords(end);
	params.min_step = 3;
	params.max_step = map->pass_map.getWidth(); //we just need limit
	params.obj_size = 1;
	params.simplify = false; //@todo: fix, it crash app!
	
	if(!IsCellClear(params.source, params.min_step) || !IsCellClear(params.destination, params.min_step))
		return false;

	this->excluded = excluded;
	return CalcPath(points, params);
}

bool PathFinder::CalcPathForTower(std::vector<Vec2i>& points, Vec2f start, Vec2f end, const Entities& excluded)
{
	PathFinderParams params;
	Map* map = GameEngine::get_data()->logic.getMap();
	params.source = map->pass_map.getIndexesByCoords(start);
	params.destination = map->pass_map.getIndexesByCoords(end);
	params.min_step = ceil(GameConst::TOWER_SIZE / map->pass_map.getCellSize());
	params.max_step = 10;
	params.obj_size = 2;
	params.simplify = false;
	
	this->excluded = excluded;
	if(!IsCellClear(params.source, params.min_step) || !IsCellClear(params.destination, params.min_step))
		return false;
	
	return CalcPath(points, params);
}

void PathFinder::InitCells(int height, int width)
{
	map_size.x = width;
	map_size.y = height;
	cells = new PathCell[ (2 * height + 1) * (2 * width + 1) ]();
	
	for(int i = -height; i <= height; i++)
		for(int j = -width; j <= width; j++)
		{
			PathCell * cell = GetCell(Vec2i(j, i));

			cell->self_coords.x = j;
			cell->self_coords.y = i;
		}
}

void PathFinder::RefreshCells()
{
	size_t cells_count = (2 * map_size.y + 1) * (2 * map_size.x + 1);
	for(size_t i = 0; i < cells_count; i++)
	{
		PathCell * cell = cells + i;
		cell->clear();
	}
}

PathFinder::PathCell * PathFinder::GetCell(Vec2i coords)
{
	if(coords.x < -map_size.x || coords.x > map_size.x ||
	   coords.y < -map_size.y || coords.y > map_size.y)
		return NULL;
	
	PathCell * cell = cells;
	size_t offset =
		(coords.y + map_size.y) * (2 * map_size.x + 1) + (coords.x + map_size.x);
	cell += offset;
	return cell;
}

/*
 offset:
 5 6 7
 3 x 4
 0 1 2
 (for min = 1)
 */
Vec2i PathFinder::GetOffset(int offset, int min)
{
	int side_size = min * 2 + 1;
	int count = 4 * min * 2;
	//bottom
	if(offset < side_size)
	{
		return Vec2i(offset - min, -min);
	}
	//top
	if (offset >= (count - side_size))
	{
		return Vec2i(offset - count + min + 1, min);
	}
	//sides
	int y = (offset - side_size) / 2 - min + 1;
	int x = ((offset - side_size) % 2) == 0 ? -min : min;
	
	return  Vec2i(x, y);
}

bool PathFinder::CalcPath(std::vector<Vec2i>& points, const PathFinderParams& params)
{
	RefreshCells();
	opened_cells.clear();
	int h1 = CalcManhattanDestance(params.source, params.destination);
	PathCell* first = GetCell(params.source);
	first->H = h1;
	first->F = h1;
	first->is_set = true;
	first->prev_cell = first;
	
	opened_cells.insert(std::pair<int, PathCell*>(h1, first));
		
	while (true) //@todo: we need to carefully check everything!
	{
		if(opened_cells.empty())
			return false; //path not found

		auto current_cell_it = opened_cells.begin();
		PathCell * current_cell = current_cell_it->second;
		opened_cells.erase(current_cell_it);
		current_cell->is_closed = true;
		
		int neightbors_count = 4 * params.min_step * 2;
		
		for(int i = 0; i < neightbors_count; i++)
		{
			Vec2i offset = GetOffset(i, params.min_step);
			PathCell * neighbour = GetCell(current_cell->self_coords + offset);
			if(!CheckLine(current_cell->self_coords, current_cell->self_coords + offset))
				continue;
			
			if(neighbour == NULL)
				continue;
			
			if(neighbour->is_set && neighbour->is_closed)
				continue;
			
			if(!IsCellClear(neighbour->self_coords, params.min_step))
				continue;
			
			neighbour->is_set = true;
			
			auto opened_it = opened_cells.end();
			for(auto open_it = opened_cells.begin();
				(open_it != opened_cells.end()) &&
				opened_it == opened_cells.end(); open_it++)
			{
				if(open_it->second == neighbour)
					opened_it = open_it;
			}
			
			int g = current_cell->G +
				((offset.x != 0 && offset.y != 0) ? COST_DIAG : COST_AXIS);
			int h = CalcManhattanDestance(neighbour->self_coords, params.destination);
			int f = g + h;
			
			if(opened_it == opened_cells.end())
			{
				neighbour->prev_cell = current_cell;
				neighbour->G = g;
				neighbour->H = h;
				neighbour->F = f;
				opened_cells.insert(std::pair<int, PathCell*>(f, neighbour));
				
				//We have found path!
				if(neighbour->self_coords == params.destination)
				{
					points.clear();
					
					if(!params.simplify)
					{
						while (neighbour != neighbour->prev_cell)
						{
							points.push_back(neighbour->self_coords);
							neighbour = neighbour->prev_cell;
						}
					}
					else
					{
						//@todo: this code just didn't work properly!!
						PathCell * prev_cell = neighbour;
						PathCell * last_added_cell = neighbour;
						points.push_back(neighbour->self_coords);
						while (neighbour != neighbour->prev_cell)
						{
							prev_cell = neighbour;
							neighbour = neighbour->prev_cell;
							if(!CheckLine(neighbour->self_coords, last_added_cell->self_coords))
							{
								points.push_back(prev_cell->self_coords);
								last_added_cell = prev_cell;
								neighbour = prev_cell;
							}
						}
						
					}
					return true;
				}
			}
			else
			{
				if(opened_it->second->G > g)
				{
					opened_it->second->prev_cell = current_cell;
					opened_it->second->G = g;
					opened_it->second->H = h;
					opened_it->second->F = f;
				}
			}
		}
	}

	return false;
}

bool PathFinder::IsCellClear(Vec2i coords, int size/* = 1*/)
{
	bool result = true;
	for(int i = 0; (i < size) && result; i++)
		for(int j = 0; (j < size) && result; j++)
		{
			if(GameEngine::get_data()->logic.getMap()->pass_map.
			   isCellPass(Vec2i(coords.x + i, coords.y + j)))
				continue;
			
			/*if(excluded.empty())
			{
				result = false;
				continue;
			}*/
			
			// Check, is entities, that blocking cell are on excluded list.
			Vec2i cell_coords = coords + Vec2i(i, j);
			Entities& blocking = GameEngine::get_data()->logic.getMap()->pass_map.GetEntitiesFrom(cell_coords);
			for(EntityIt it = blocking.begin(); it != blocking.end() && result; it++)
			{
				bool founded_on_excluded = false;
				for(EntityIt itEx = excluded.begin();
					itEx != excluded.end() && !founded_on_excluded; itEx++)
				{
					founded_on_excluded = (it->lock().get() == itEx->lock().get());
				}
				result &= founded_on_excluded;
			}
		}
	return result;
}

int PathFinder::CalcManhattanDestance(Vec2i from, Vec2i to)
{
	return COST_AXIS * (abs(from.x - to.x) + abs(from.y - to.y));
}

bool PathFinder::CheckLine(Vec2i a, Vec2i b)
{
	Vec2i left, right;
	// Swap points, a should be at left side
	if(a.x > b.x)
	{
		left = b;
		right = a;
	}
	else
	{
		left = a;
		right = b;
	}
	
	// check, is a & b on Ox
	if(left.y == right.y)
	{
		bool result = true;
		for(int dx = left.x; (dx <= right.x) && result; dx++)
		{
			result &= IsCellClear(Vec2i(dx, left.y));
		}
		return result;
	}

	// check, is a & b on Oy
	if(left.x == right.x)
	{
		bool result = true;
		int min_y = std::min(left.y, right.y);
		int max_y = std::max(left.y, right.y);
		for(int dy = min_y; (dy <= max_y) && result; dy++)
		{
			result &= IsCellClear(Vec2i(left.x, dy));
		}
		return result;
	}
	
	float s = (float)(right.y - left.y) / (float)(right.x - left.x);
	float yp = left.y; //y previous
	bool result = true;
	for(int dx = left.x; (dx < right.x) && result; dx++)
	{
		float y = (dx - left.x + 1) * s + left.y;
		/*s > 0 ?
			ceil((dx - left.x + 1) * s + left.y) :
			floor((dx - left.x + 1) * s + left.y);*/

		if(s > 0)
			for(int dy = floor(yp); (dy <= ceil(y)) && result; dy++)
				result &= IsCellClear(Vec2i(dx, dy));
		else
			for(int dy = ceil(yp); (dy >= floor(y)) && result; dy--)
				result &= IsCellClear(Vec2i(dx, dy));
		
		yp = y;
	}
	
	//last row
	if(yp < right.y)
		for(int dy = floor(yp); (dy <= right.y) && result; dy++)
		{
			result &= IsCellClear(Vec2i(right.x, dy));
		}
	else
		for(int dy = ceil(yp); (dy >= right.y) && result; dy--)
		{
			result &= IsCellClear(Vec2i(right.x, dy));
		}

	return result;
}














