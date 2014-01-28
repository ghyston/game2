//
//  TargetComponent.h
//  Game2
//
//  Created by Stepanov Ilia on 10/17/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef Game2_TargetComponent_h
#define Game2_TargetComponent_h

#include "../../ECS/Types.h"
#include "../../ECS/BaseComponent.h"

class TargetComponent : public IComponent
{
public:
	
	TargetComponent() : target_enemy (false) {;}
    
    EntityPtr target;
	bool target_enemy;

};

#endif
