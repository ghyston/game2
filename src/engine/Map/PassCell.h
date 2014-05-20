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

struct PassCell
{
	PassCell() : passability(true) {;}
	bool passability;
	//EntityPtr blocked_entity;
};

#endif /* defined(__Game2__PassCell__) */
