//
//  RefEntity.cpp
//  Game2
//
//  Created by Stepanov Ilia on 03/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#include "RefEntity.h"
#include "Entity.h"

void RefEntity::Unregister()
{
	if(pointer != NULL)
		pointer->unregister_listener(this);
}

void RefEntity::SetPointer(Entity * pointer)
{
	this->pointer = pointer;
	if( pointer != NULL)
		pointer->register_listener(this);
}

void RefEntity::UnsetPointer()
{
	Unregister();
	DelRef();
}


RefEntity::~RefEntity()
{
	Unregister();
}