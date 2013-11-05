//
//  Game2Logic.cpp
//  Game2
//
//  Created by Stepanov Ilia on 05/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#include "Game2Logic.h"
#include "Systems/RenderSystem.h"
#include "Systems/MoveSystem.h"
#include "Systems/TargetEnergySystem.h"
#include "Systems/CollisionSystem.h"

void Game2Logic::start()
{
	add_system(new RenderSystem());
	add_system(new MoveSystem());
	add_system(new CollisionSystem());
	add_system(new TargetEnergySystem());

}

void Game2Logic::stop()
{
	
}
