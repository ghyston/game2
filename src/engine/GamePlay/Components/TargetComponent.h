//
//  TargetComponent.h
//  Game2
//
//  Created by Stepanov Ilia on 10/17/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef Game2_TargetComponent_h
#define Game2_TargetComponent_h

class Entity; //@todo: is it good?

class TargetComponent : public IComponent
{
public:
	
	int get_id() { return ComponentsType::TARGET_COMPONENT; }
    
    Entity * target;

};

#endif
