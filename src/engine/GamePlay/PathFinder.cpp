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

bool PathFinder::CalcPath(std::vector<Vec2i>& points)
{
	opened_cells.push_back(source);
	
	Vec2i parent_cell = source; //@todo: no, not good.
	
	// check, is this cell on closed list or blocked.
	Vec2i offset = Vec2i(-1, -1);
	Vec2i cell_coords = source + offset;
	std::list<Vec2i>::iterator it =
		std::find(closed_cells.begin(), closed_cells.end(), cell_coords);
	
	if(it != closed_cells.end() || !IsCellClear(cell_coords))
		return false; //ignore this cell
	
	PathCell pcell;
	pcell.H = CallManhattanDestance(cell_coords);
	pcell.G = cells[parent_cell.x][parent_cell.y].G;
	pcell.G += (offset.x != 0 && offset.y != 0) ? COST_DIAG : COST_AXIS;
	pcell.F = pcell.H + pcell.G;
	
	
	return false;
}

bool PathFinder::IsCellClear(Vec2i coords)
{
	return GameEngine::get_data()->logic.GetCellPosibility(coords + source);
}

int PathFinder::CalcManhattanDestance(Vec2i coords)
{
	return (abs(coords.x - destination.x) + abs(coords.y - destination.y));
}

bool PathFinder::SetStartEnd(Vec2i from, Vec2i to)
{
	source = from;
	destination = to;
	return (IsCellClear(source) && IsCellClear(destination));
}
