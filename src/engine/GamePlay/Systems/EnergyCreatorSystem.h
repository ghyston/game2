//
//  EnergyCreatorSystem.h
//  Game2
//
//  Created by Stepanov Ilia on 11/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__EnergyCreatorSystem__
#define __Game2__EnergyCreatorSystem__

#include "../../ECS/BaseSystem.h"

class EnergyGeneratorSystem : public BaseSystem
{
public:
	
	void update(Entity * entity);
};

#endif /* defined(__Game2__EnergyCreatorSystem__) */
