//
//  TowerRenderable.h
//  Game2
//
//  Created by Stepanov Ilia on 04/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__TowerRenderable__
#define __Game2__TowerRenderable__

#include "BaseRenderable.h"
#include "RectRenderable.h"
#include "core/GameConstants.h"

class TowerRenderable : public BaseRenderable
{
public:
	TowerRenderable() : size(GameConst::TOWER_SIZE), energy(1.0f) {;}
	
	void Init();
	
	virtual void setup_vertexes();
	
	virtual void Draw();
	
	virtual void set_energy(float energy) { this->energy = energy; }
	
//private:
	
	float size; //Tower is square
	
	float energy; // 0.0f .. 1.0f
	
	RectRenderable * back;
	RectRenderable * front;
	
};

#endif /* defined(__Game2__TowerRenderable__) */
