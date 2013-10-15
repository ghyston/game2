//
//  ConnectorComponent.h
//  Game2
//
//  Created by Stepanov Ilia on 10/15/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef Game2_ConnectorComponent_h
#define Game2_ConnectorComponent_h

class Entity; //@todo: is it good?

// This component we need to connect two entities (towers)
class ConnectorComponent : public IComponent
{
public:
	
	int get_id() { return ComponentsType::CONNECTOR_COMPONENT; }
    
    Entity * obj_1;
    Entity * obj_2;
};

#endif
