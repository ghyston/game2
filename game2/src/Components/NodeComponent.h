//
//  NodeComponent.h
//  Game2
//
//  Created by Stepanov Ilia on 08/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__NodeComponent__
#define __Game2__NodeComponent__

#include "../../ECS/Types.h"
#include "../../ECS/BaseComponent.h"

class NodeComponent : public IComponent
{
public:

	static int GetTypeImpl() { return ComponentsType::NODE_COMPONENT; }
	
	EntityPtr parent;
	Entities children;
	
};

#endif /* defined(__Game2__NodeComponent__) */
