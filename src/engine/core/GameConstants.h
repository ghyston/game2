//
//  GameConstants.h
//  Game2
//
//  Created by Stepanov Ilia on 22/06/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#ifndef Game2_GameConstants_h
#define Game2_GameConstants_h

namespace GameConst
{
	static const float TOWER_SIZE = 0.1f;
	static const float TOWER_TOUCH_SIZE = TOWER_SIZE / 2;
	static const float TOWER_MIN_DIST = 0.02; // minimal distance betweeen two connected towers
	static const float TOWER_MAX_DIST = 0.3; // max distance betweeen two connected towers
	static const int MIN_ENERGY_TO_ACTION = 60;
	static const int TOWER_BUILD_COST = 50;
	static const float GENERATOR_INTESIVITY = 0.01f;
	static const float GENERATOR_RAD = 0.2f;
}

//#define TOWER_SIZE 0.1f;
//#define TOWER_TOUCH_SIZE 0.05f; //TOWER_SIZE / 2


#endif
