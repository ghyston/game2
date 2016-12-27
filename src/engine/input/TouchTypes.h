//
//  TouchTypes.h
//  Game2
//
//  Created by Stepanov Ilia on 16/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__TouchTypes__
#define __Game2__TouchTypes__

#include "Common/Vector2f.h"
#include "ECS/Entity.h"

/**
 * Base interface to touches.
 */
class ITouchInput
{
public:
	virtual void OnPress(Vec2f coords) = 0;
	virtual void OnMove(Vec2f coords) = 0;
	virtual void OnRelease(Vec2f coords) = 0;
	//		virtual void DoWork() = 0; @todo: made it for dbl click!
};

class SimpleTouchInput : public ITouchInput
{
	virtual void OnPress(Vec2f coords);
	virtual void OnMove(Vec2f coords);
	virtual void OnRelease(Vec2f coords);
};

/**
 * Touch, that move scene.
 */
class WorldTouchInput : public ITouchInput
{
public:
	
	virtual void OnPress(Vec2f coords);
	virtual void OnMove(Vec2f coords);
	virtual void OnRelease(Vec2f coords);
	
private:
	Vec2f press_coords;
	Vec2f old_cam_pos;
};

class TowerMoveTouchInput : public ITouchInput
{
public:
	
	virtual void OnPress(Vec2f coords);
	virtual void OnMove(Vec2f coords);
	virtual void OnRelease(Vec2f coords);
	
	virtual void SetEntity(Entity * entity);
	
private:
	
	//@todo: entity can be destroyed here, be carefull!
	Vec2f press_coords;
	Entity * touched_entity;
	Vec2f old_entity_coords;
};

class CommonInput
{
	ITouchInput * input;
	
	enum TouchInputTypes
	{
		SIMPLE,
		WORLD_MOVE,
		TOWER_SIMPLE,
		TOWER_TO_WORLD,
		TOWER_TO_TOWER
	};
	
	void SetType(TouchInputTypes type)
	{
	}
	
};

#endif /* defined(__Game2__TouchTypes__) */
