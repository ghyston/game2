//
//  Game2Logic.h
//  Game2
//
//  Created by Stepanov Ilia on 05/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__Game2Logic__
#define __Game2__Game2Logic__

#include "../ECS/GameLogic.h"

class Game2Logic : public GameLogic
{
public:
	void start();
	void stop();
	
	void add_tower(Entity * tower);
	void add_energy(Entity * energy, Entity * generator);
	
	void tower_attack(Entity * from, Entity * to);
	
};

#endif /* defined(__Game2__Game2Logic__) */
