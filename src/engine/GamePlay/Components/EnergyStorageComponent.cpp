//
//  EnegyStorageComponent.cpp
//  Game2
//
//  Created by Stepanov Ilia on 16/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#include "EnergyStorageComponent.h"

void EnergyStorageComponent::add_energy(int count)
{
	value += count;
	if(value > limit)
		value = limit;
}

void EnergyStorageComponent::rem_energy(int count)
{
	value = (value >= count) ? (value - count) : 0;
}