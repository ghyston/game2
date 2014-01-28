//
//  EnergyGeneratorComponent.h
//  Game2
//
//  Created by Stepanov Ilia on 11/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef Game2_EnergyGeneratorComponent_h
#define Game2_EnergyGeneratorComponent_h

#include "../../ECS/BaseComponent.h"
class EnergyGeneratorComponent : public IComponent
{
public:
	
	EnergyGeneratorComponent() :
		radius(0.2f),
		intensivity(0.0f),
		activated(false) // @todo: this is just a hack
	{;}
	
	float radius;	
	float intensivity;
	bool activated;
	
	//this is a towers nearby.
	Entities towers;
};

#endif
