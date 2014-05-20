//
//  PassMap.cpp
//  Game2
//
//  Created by Stepanov Ilia on 17/05/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#include "PassMap.h"

bool PassMap::isCellPass(Vec2i coords)
{
	return cells[coords.x][coords.y].passability;
}

bool PassMap::isCellPass(Vec2f coords)
{
	Vec2i iCoords = getIndexesByCoords(coords);
	return isCellPass(iCoords);
}

void PassMap::SetPass(bool passability, Vec2i coords)
{
	cells[coords.x][coords.y].passability = passability;
}

void PassMap::SetPass(bool passability, Vec2f coords)
{
	return SetPass(passability, getIndexesByCoords(coords));
}

void PassMap::BlockPassCells(const Vec2f& left_top, const Vec2f& right_bottom)
{
	Vec2i iLT = getIndexesByCoords(left_top);
	Vec2i iRB = getIndexesByCoords(right_bottom);
	
	for(int i = iLT.x; i <= iRB.x; i++)
	{
		for(int j = iRB.y; j <= iLT.y; j++)
		{
			SetPass(false, Vec2i(i,j));
		}
	}
}

bool PassMap::CheckCellsPass(const Vec2f& left_top, const Vec2f& right_bottom)
{
	Vec2i iLT = getIndexesByCoords(left_top);
	Vec2i iRB = getIndexesByCoords(right_bottom);
	
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
