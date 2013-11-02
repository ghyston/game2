//
//  TargetComponent.cpp
//  Game2
//
//  Created by Stepanov Ilia on 02/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#include "TargetComponent.h"
#include "../../ECS/Entity.h"

TargetComponent::~TargetComponent()
{
	target.pointer->unregister_listener(&target);
}