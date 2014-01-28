//
//  AISystem.h
//  Game2
//
//  Created by Stepanov Ilia on 24/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__AISystem__
#define __Game2__AISystem__

#include "../../ECS/BaseSystem.h"
#include "../EntityFabric.h"
#include "../../GameEngine.h"

class AISystem : public BaseSystem
{
public:
	
	virtual void pre_step() {;}
	virtual void post_step() {;}
	
protected:
	
	virtual void update(EntityPtr entity);
	
};

#endif /* defined(__Game2__AISystem__) */
