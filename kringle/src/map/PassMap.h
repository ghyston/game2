//
//  PassMap.h
//  Game2
//
//  Created by Stepanov Ilia on 17/05/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__PassMap__
#define __Game2__PassMap__

#include "BaseGridMap.h"
#include "PassCell.h"
#include "../Common/VecShrPtr.h"

/**
 * This grid map collect info about passibility map, cell can be used(blocked) or free.
 */
class PassMap : public BaseGridMap<PassCell>
{
public:
	
	bool isCellPass(Vec2f coords);
	bool isCellPass(Vec2i coords);
	
	void BlockPass(Vec2i coords, EntityPtr entity);
	void BlockPass(Vec2f coords, EntityPtr entity);
	
	void BlockPassCells(const Vec2f& left_top, const Vec2f& right_bottom, EntityPtr entity);
	// Return true, if cells are free.
	bool CheckCellsPass(const Vec2f& left_top, const Vec2f& right_bottom);
	bool CheckCellsPass(const Vec2i& left_top, const Vec2i& right_bottom);
	
	void RecalculateCellsPassability();
	
	Entities& GetEntitiesFrom(Vec2i coords);
	
private:
	void SetPass(bool passability, Vec2i coords);
	void SetPass(bool passability, Vec2f coords);
};

#endif /* defined(__Game2__PassMap__) */
