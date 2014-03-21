//
//  Map.h
//  Game2
//
//  Created by Stepanov Ilia on 15/03/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__Map__
#define __Game2__Map__

#include "MapCell.h"
#include "PassCell.h"
#include "../Common/VecShrPtr.h"
#include "../Common/Vec2i.h"

class Map
{
public:
	Map() {;}
	
	void InitMap(int width_, int height_, float cell_size_);
	
	void addEntity(float pos_x, float pos_y, EntityPtr entity);
	
	void checkFroRemovedEntities();
	
	//Entities& getClosestEntity(float x, float y);
	Entities& getEntitiesFromCell(float x, float y);
	Entities& getEntitiesFromCell(int x, int y);
	Vec2i getCellIndexes(float x, float y);
	
	int getHeight() { return height; }
	int getWidth() { return width; }
	float getCellSize() { return cell_size; }
	
	int getPassHeight() { return pass_height; }
	int getPassWidth() { return pass_width; }
	float getPassCellSize() { return pass_cell_size; }
	
private:
	
	int width;
	int height;
	float cell_size;
	
	int pass_width;
	int pass_height;
	float pass_cell_size;
	
	std::map<int, std::map<int, MapCell> > cells;
	std::map<int, std::map<int, PassCell> > pass_cells;
};

#endif /* defined(__Game2__Map__) */
