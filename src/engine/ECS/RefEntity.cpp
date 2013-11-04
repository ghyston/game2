//
//  RefEntity.cpp
//  Game2
//
//  Created by Stepanov Ilia on 03/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#include "RefEntity.h"
#include "Entity.h"

void RefEntity::unregister()
{
	if(pointer != NULL)
		pointer->unregister_listener(this);
}
