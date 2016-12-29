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
#include "../ECS/Types.h"
#include "../Common/Vec2i.h"
#include "../Common/Vector2f.h"

class PathFinder
{
public:
	
	PathFinder()
	{;}
	
	//@todo: it's time to start writing destructors and release memory everywhere!
	~PathFinder();
	
	void InitCells(int height, int width); //inline?
	
	bool CalcPathForUnit(std::vector<Vec2i>& points, Vec2f start, Vec2f end, const Entities& excluded);
	bool CalcPathForTower(std::vector<Vec2i>& points, Vec2f start, Vec2f end, const Entities& excluded);
	
	/*
	 * Return true, if segment [a;b] doesn't intersect any blocked pass cells.
		false otherwise.
	 */
	bool CheckLine(Vec2i a, Vec2i b);
	
protected:
	
	struct PathFinderParams
	{
		Vec2i source;
		Vec2i destination;
		int min_step;
		int max_step;
		int obj_size;
		bool simplify;
	};
	
	bool CalcPath(std::vector<Vec2i>& points, const PathFinderParams& params);
	
	static const int COST_AXIS;
	static const int COST_DIAG;
	
	bool IsCellClear(Vec2i coords, int size = 1);
	
	void RefreshCells();
	
	int CalcManhattanDestance(Vec2i from, Vec2i to);
		
	struct PathCell
	{
		PathCell()
		{
			clear();
		}
		
		int F; // Sum G + H.
		int G; // Cost from source.
		int H; // Cost (aprox.) to destination.
		PathCell* prev_cell;
		Vec2i self_coords;
		bool is_closed;
		bool is_set;
		
		void clear()
		{
			F = 0;
			G = 0;
			H = 0;
			prev_cell = NULL;
			is_closed = false;
			is_set = false;
		}
		
	};
	
	PathCell * GetCell(Vec2i coords);
	Vec2i GetOffset(int offset, int min);
	PathCell * cells;
	
	std::multimap<int, PathCell*> opened_cells;
	Entities excluded;
	Vec2i map_size;
		
};

#endif /* defined(__Game2__PathFinder__) */
