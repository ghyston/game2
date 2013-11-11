//
//  EnergyBalanceSystem.h
//  Game2
//
//  Created by Stepanov Ilia on 05/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__EnergyBalanceSystem__
#define __Game2__EnergyBalanceSystem__

#include "../../ECS/BaseSystem.h"

class EnergyBalanceSystem : public BaseSystem
{
	unsigned int sum_energy;
	unsigned int count_storage;
	
	//EnergyStorageComponent * enesto;
	
public:
	
	// This keep sum_energy/count_storage, that calculates every step.
	static int average_energy;
	
	virtual void update(Entity * entity);

	virtual void pre_step();
	virtual void post_step();
	
};

#endif /* defined(__Game2__EnergyBalanceSystem__) */
