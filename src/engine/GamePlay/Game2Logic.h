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
#include "PathFinder.h"

class Game2Logic : public GameLogic
{
public:
	
	virtual void LoadMap(int width, int height, float cell_size);
	
	void start();
	void stop();
	
	void add_tower(EntityPtr tower);
	void add_energy(EntityPtr energy, EntityPtr generator);
	// Return false if place is holded.
	bool CanBuildTower(Vec2f coords);
	
	void remove_tower(EntityPtr tower);
	
	void tower_attack(EntityPtr from, EntityPtr to);
	
	//@todo: not good to keep it here
	bool CalcPath(Vec2f from, Vec2f to, std::vector<Vec2f>& points);
	
private:
	PathFinder path_finder;
};


#endif /* defined(__Game2__Game2Logic__) */
