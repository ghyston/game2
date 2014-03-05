//
//  PlayerIdComponent.h
//  Game2
//
//  Created by Stepanov Ilia on 17/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef Game2_PlayerIdComponent_h
#define Game2_PlayerIdComponent_h

#include "../../ECS/BaseComponent.h"

class PlayerIdComponent : public IComponent
{
public:
	
	PlayerIdComponent() : player_id(0) {;}
	

	static int GetTypeImpl() { return ComponentsType::PLAYER_ID_COMPONENT; }
	
	unsigned int player_id;
};

#endif
