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

class RefEntity
{
private:
	Entity * pointer;
	
public:
	RefEntity() : pointer(NULL) {;}
	~RefEntity();
	
	//@todo: DelRef() should be just friend func to Storage class (Listnerable)!
	void DelRef() { pointer = NULL; }
	Entity * Get() { return pointer; }
	bool IsSet() { return pointer != NULL; };
	void SetPointer(Entity * pointer);
	void UnsetPointer();
	void Unregister();
};

#endif /* defined(__Game2__RefEntity__) */
