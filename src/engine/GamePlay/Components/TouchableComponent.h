//
//  TouchableComponent.h
//  Game2
//
//  Created by Stepanov Ilia on 12/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef Game2_TouchableComponent_h
#define Game2_TouchableComponent_h

#include "../../ECS/BaseComponent.h"

class TouchableComponent : public IComponent
{
public:
	
	TouchableComponent() : is_touched(false) {;}
	
	bool is_touched;
	// it's square size arount position component, that can be touched
	float touch_size;
};

#endif
