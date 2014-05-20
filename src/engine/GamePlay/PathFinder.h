//
//  PathFinder.h
//  Game2
//
//  Created by Stepanov Ilia on 23/03/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__PathFinder__
#define __Game2__PathFinder__

#include <map>
#include <list>
#include <vector>
#include "../Common/Vec2i.h"

class PathFinder
{
public:
	
	PathFinder()
	{;}
	
	bool SetStartEnd(Vec2i from, Vec2i to);
	
	void InitCells(int height, int width);
	
	/**
	 * Calculate path.
	 * return false, if there is no path.
	 */
	
	bool CalcPath(std::vector<Vec2i>& points);
	
private:
	
	static const int COST_AXIS;
	static const int COST_DIAG;
	
	bool IsCellClear(Vec2i coords);
	
	int CalcManhattanDestance(Vec2i coords);
	
//	void ProcessCell()
	
	struct PathCell
	{
		PathCell() :
			F(0), G(0), H(0), prev_cell(NULL),
			is_closed(false), is_set(false)
		{;}
		
		int F; // Sum G + H.
		int G; // Cost from source.
		int H; // Cost (aprox.) to destination.
		PathCell* prev_cell;
		Vec2i self_coords;
		bool is_closed;
		bool is_set;
	};
	
	PathCell * GetCell(Vec2i coords);
	Vec2i GetOffset(int offset);
	PathCell * cells;
	
	std::multimap<int, PathCell*> opened_cells;
	
	Vec2i source;
	Vec2i destination;
	Vec2i map_size;
	
//	std::multimap<int, Vec2i> opened_cells;
//	std::list<PathCell> closed_list;
//	std::map<int, std::map<int, PathCell> > cells;
	
	//std::list<Vec2i> opened_cells;
	//std::list<Vec2i> closed_cells;
	
	
};

#endif /* defined(__Game2__PathFinder__) */
