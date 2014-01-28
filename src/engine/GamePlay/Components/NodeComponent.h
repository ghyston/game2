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
#include "../../ECS/Types.h"
#include <list>

class NodeComponent : public IComponent
{
public:

	EntityPtr parent;
	Entities children;
	
};

#endif /* defined(__Game2__NodeComponent__) */
