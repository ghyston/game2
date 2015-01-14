//
//  AiComponent.h
//  Game2
//
//  Created by Stepanov Ilia on 16/02/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#ifndef Game2_AiComponent_h
#define Game2_AiComponent_h

#include "../../ECS/BaseComponent.h"

class AiComponent : public IComponent
{
public:
	
	AiComponent() : is_head(false) {;}
	
	static int GetTypeImpl() { return ComponentsType::AI_COMPONENT; }
	
	bool is_head;
	
};

#endif
