//
//  PathMoveSystem.h
//  Game2
//
//  Created by Stepanov Ilia on 23/03/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__PathMoveSystem__
#define __Game2__PathMoveSystem__

#include "../../ECS/BaseSystem.h"

class PathMoveSystem : public BaseSystem
{
	
public:
	
	void update(EntityPtr entity);
	
};

#endif /* defined(__Game2__PathMoveSystem__) */
