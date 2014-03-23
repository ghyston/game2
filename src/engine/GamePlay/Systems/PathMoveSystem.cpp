//
//  PathMoveSystem.cpp
//  Game2
//
//  Created by Stepanov Ilia on 23/03/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#include "PathMoveSystem.h"
#include "../Components.h"

void PathMoveSystem::update(EntityPtr entity)
{
	// @todo: some of this logic can be passed to component functions!
	if(!HasCmpt(PathFindComponent, entity))
		return;
	
	GetCmpt(PathFindComponent, path_com, entity);
	GetCmpt(PositionComponent, pos_com, entity);
	GetCmpt(MovementComponent, mov_com, entity);
	
	if(path_com->path.empty())
		return;
	
	EntityPtr next_waypoint = path_com->path.front();
	GetCmpt(PositionComponent, wp_pos_com, next_waypoint);
	
	Vec2f between = wp_pos_com->position - pos_com->position;
	float dist = between.length();
	if(dist <= 0.01f) // remove target
	{
		mov_com->speed = Vec2f(0.0f, 0.0f);
		next_waypoint->mark_deleted();
		path_com->path.pop_front();
	}
	else //Keep moving
	{
		between.length(0.1f);
		mov_com->speed = between;
	}
}