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
	AISystem() : target_set(false), enemyNearby(false),
		state(ENEMY_SEARCHING)
	{;}
	
protected:
	
	virtual void pre_step();
	
	virtual void update(EntityPtr entity);
	
	virtual void post_step();
	
private:
	
	enum
	{
		ENEMY_SEARCHING,
		BUILD_TO_ENEMY,
		ENEMY_ATTAKING,
		ENEMY_DEAD
	} state;
	
	//void DetectTarget(EntityPtr entity);
	// Not used for now.
	//void BuildRandomTower(EntityPtr entity);
	
	//EntityPtr findClosestEnemy(EntityPtr entity);
	
	bool enemyNearby;
	
	//@todo: thi is just temp implementation, just 4 fun.
	//@todo: create AI manager, after cell grids & path finding refactoring!
	//Vec2f GenerateRandomTarget();
	bool target_set;
	EntityPtr closest_tower;
	EntityPtr enemy_tower;
	float destination_to_closest_tower;
	Vec2f target;
	std::vector<Vec2f> path;
	std::vector<Vec2f>::iterator pathIt;
	
};

#endif /* defined(__Game2__AISystem__) */
