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

/**
 * This grid map collect info about passibility map, cell can be used(blocked) or free.
 */
class PassMap : public BaseGridMap<PassCell>
{
public:
	
	bool isCellPass(Vec2f coords);
	bool isCellPass(Vec2i coords);
	void SetPass(bool passability, Vec2i coords);
	void SetPass(bool passability, Vec2f coords);
	
	void BlockPassCells(const Vec2f& left_top, const Vec2f& right_bottom);
	// Return true, if cells are free.
	bool CheckCellsPass(const Vec2f& left_top, const Vec2f& right_bottom);

	
	
private:
};

#endif /* defined(__Game2__PassMap__) */
