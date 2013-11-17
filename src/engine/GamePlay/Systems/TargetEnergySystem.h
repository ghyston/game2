//
//  TargetEnergySystem.h
//  Game2
//
//  Created by Stepanov Ilia on 10/17/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__TargetEnergySystem__
#define __Game2__TargetEnergySystem__

#include "../../ECS/BaseSystem.h"
#include "../../ECS/Entity.h"
#include "../Components.h"

class TargetEnergySystem : public BaseSystem
{
public:
	
	void update(Entity * entity);
	
private:
	
	void merge_energy(Entity * tower, Entity * energy);

};

#endif /* defined(__Game2__TargetEnergySystem__) */
