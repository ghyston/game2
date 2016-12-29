//
//  PathFindComponent.h
//  Game2
//
//  Created by Stepanov Ilia on 23/03/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__PathFindComponent__
#define __Game2__PathFindComponent__

#include "../../ECS/BaseComponent.h"
#include "../../ECS/Types.h"
#include "../../Common/Vector2f.h"

class PathFindComponent : public IComponent
{
public:
	Entities path;
	
	static int GetTypeImpl() { return ComponentsType::PATH_FIND_COMPONENT; }
};

#endif /* defined(__Game2__PathFindComponent__) */
