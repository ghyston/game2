//
//  ConnectorComponent.h
//  Game2
//
//  Created by Stepanov Ilia on 10/15/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef Game2_ConnectorComponent_h
#define Game2_ConnectorComponent_h

#include "../../ECS/RefEntity.h"
#include "../../ECS/BaseComponent.h"

// This component we need to connect two entities (towers)
class ConnectorComponent : public IComponent
{
public:
    
    RefEntity obj_1;
    RefEntity obj_2;
	
	~ConnectorComponent();
};

#endif
