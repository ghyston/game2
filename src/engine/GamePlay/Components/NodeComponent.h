//
//  NodeComponent.h
//  Game2
//
//  Created by Stepanov Ilia on 08/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__NodeComponent__
#define __Game2__NodeComponent__

#include "../../ECS/BaseComponent.h"
#include "../../ECS/RefEntity.h"
#include <vector>

class NodeComponent : public IComponent
{
public:
	//@todo: use some smart pointers!
	Entity * parent;
	std::vector<Entity*> children;
	
};

#endif /* defined(__Game2__NodeComponent__) */
