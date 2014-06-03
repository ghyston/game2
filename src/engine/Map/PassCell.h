//
//  PassCell.h
//  Game2
//
//  Created by Stepanov Ilia on 20/03/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__PassCell__
#define __Game2__PassCell__

#include "Types.h"
#include "../Common/VecShrPtr.h"


struct PassCell
{
	PassCell() : passability(true) {;}
	bool passability;
	Entities blocked_entities;
	
	inline void RecalculatePassability()
	{
		if(passability)
			return;
		
		RemoveDeletedObjectsFromContainer(blocked_entities);
		if(blocked_entities.empty())
			passability = true;
	}
};

#endif /* defined(__Game2__PassCell__) */
