//
//  ConnectorComponent.cpp
//  Game2
//
//  Created by Stepanov Ilia on 03/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#include "ConnectorComponent.h"
#include "../../ECS/Entity.h"

ConnectorComponent::~ConnectorComponent()
{
	obj_1.unregister();
    obj_2.unregister();

}