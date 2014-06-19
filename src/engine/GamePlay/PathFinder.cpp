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
 */
Vec2i PathFinder::GetOffset(int offset)
{
	switch (offset)
	{
		case 0:	return Vec2i(-1, -1);
		case 1:	return Vec2i( 0, -1);
		case 2:	return Vec2i( 1, -1);
		case 3:	return Vec2i(-1,  0);
		case 4:	return Vec2i( 1,  0);
		case 5:	return Vec2i(-1,  1);
		case 6:	return Vec2i( 0,  1);
		case 7:	return Vec2i( 1,  1);
			
		default:
			return Vec2i(0, 0);
	}
}

bool PathFinder::CalcPath(std::vector<Vec2i>& points, bool simplify/* = true*/)
{
	RefreshCells();
	opened_cells.clear();
	int h1 = CalcManhattanDestance(source);
	PathCell* first = GetCell(source);
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
		
		bool left_clear = IsCellClear(current_cell->self_coords + GetOffset(3));
		bool rght_clear = IsCellClear(current_cell->self_coords + GetOffset(4));
		bool  top_clear = IsCellClear(current_cell->self_coords + GetOffset(6));
		bool botm_clear = IsCellClear(current_cell->self_coords + GetOffset(1));
		
		for(int i = 0; i <= 7; i++)
		{
			Vec2i offset = GetOffset(i);
			PathCell * neighbour = GetCell(current_cell->self_coords + offset);
			
			if(neighbour == NULL)
				continue;
			
			if(neighbour->is_set && neighbour->is_closed)
				continue;
			
			if(!IsCellClear(neighbour->self_coords))
				continue;
			
			// prevent edge-cut
			if(i == 0 && (!left_clear || !botm_clear))
				continue;
			if(i == 2 && (!rght_clear || !botm_clear))
				continue;
			if(i == 7 && (!rght_clear || !top_clear))
				continue;
			if(i == 5 && (!left_clear || !top_clear))
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
			int h = CalcManhattanDestance(neighbour->self_coords);
			int f = g + h;
			
			if(opened_it == opened_cells.end())
			{
				neighbour->prev_cell = current_cell;
				neighbour->G = g;
				neighbour->H = h;
				neighbour->F = f;
				opened_cells.insert(std::pair<int, PathCell*>(f, neighbour));
				
				//We have found path!
				if(neighbour->self_coords == destination)
				{
					points.clear();
					
					if(!simplify)
					{
						while (neighbour != neighbour->prev_cell)
						{
							points.push_back(neighbour->self_coords);
							neighbour = neighbour->prev_cell;
						}
					}
					else
					{
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

bool PathFinder::IsCellClear(Vec2i coords)
{
	return GameEngine::get_data()->logic.getMap()->pass_map.isCellPass(coords);
}

int PathFinder::CalcManhattanDestance(Vec2i coords)
{
	return COST_AXIS * (abs(coords.x - destination.x) + abs(coords.y - destination.y));
}

bool PathFinder::SetStartEnd(Vec2i from, Vec2i to)
{
	source = from;
	destination = to;
	return (IsCellClear(source) && IsCellClear(destination));
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














