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
	
protected:
	
	virtual void update(EntityPtr entity);
	
private:
	
	void DetectTarget(EntityPtr entity);
	// Not used for now.
	void BuildRandomTower(EntityPtr entity);
	
	EntityPtr findClosestEnemy(EntityPtr entity);
	
	bool enemyNearby;
	
	
};

#endif /* defined(__Game2__AISystem__) */
