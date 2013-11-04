//
//  RefEntity.h
//  Game2
//
//  Created by Stepanov Ilia on 02/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__RefEntity__
#define __Game2__RefEntity__

#include <iostream>

class Entity;

struct RefEntity
{
	Entity * pointer;
	void del_ref() { pointer = NULL; }
	void unregister();
};

#endif /* defined(__Game2__RefEntity__) */
