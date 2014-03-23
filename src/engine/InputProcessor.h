//
//  InputProcessor.h
//  Game2
//
//  Created by Stepanov Ilia on 12/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__InputProcessor__
#define __Game2__InputProcessor__

#include <string.h>
#include <sstream>

#include "GlobalData.h"


class InputProcessor
{
public:
	
	struct TouchTypes
	{
		enum
		{
			PRESS,
			MOVE,
			RELEASE
		};
	};

	
	InputProcessor() : touched_entity(NULL), new_entity_created(false), pathKeyPressed(false) {;}
	
	void process_touch(int type, float screen_x, float screen_y);
	
	bool pathKeyPressed;
	
private:
		
	Vec2f press_coords;
	Vec2f old_cam_pos;
	
	//@todo: entity can be destroyed here, be carefull!
	EntityPtr touched_entity;
	Vec2f old_entity_coords;
	bool new_entity_created;
	
	// return pointer to founded entity or NULL if not found.
	EntityPtr find_entity(Vec2f world_coords);
	
	
	
};

#endif /* defined(__Game2__InputProcessor__) */
