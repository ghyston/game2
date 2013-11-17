//
//  EnergyStorage.h
//  Game2
//
//  Created by Stepanov Ilia on 05/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__EnergyStorage__
#define __Game2__EnergyStorage__

#include "../../ECS/BaseComponent.h"

class EnergyStorageComponent : public IComponent
{
public:
	
	unsigned int limit;
	unsigned int value;
	float balance;
	
	float get_percentage() { return (float)value / (float)limit; }
	bool is_full() { return value >= limit; }
	bool is_empty() { return value == 0; }
	void add_energy(int count);
	
};

#endif /* defined(__Game2__EnergyStorage__) */
