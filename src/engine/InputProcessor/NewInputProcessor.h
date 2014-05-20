//
//  File.h
//  Game2
//
//  Created by Stepanov Ilia on 05/02/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__NewInputProcessor__
#define __Game2__NewInputProcessor__

#include "../Common/Vector2f.h"

//@note: it doesn't in use now.

class BaseTouchState
{
protected:
	virtual int OnPress(float x, float y);
	virtual int OnMove(float x, float y);
	virtual int OnRelease(float x, float y);
	
private:
	
	float prev_x;
	float prev_y;
	//@todo: add time!
	
	friend class NewInputProcessor;
};

class IdleTouchState : public BaseTouchState
{
	virtual int OnPress(float x, float y);
};

class MoveWorldTouchState : public BaseTouchState
{
	virtual int OnMove(float x, float y);
	virtual int OnRelease(float x, float y);
	
	Vec2f press_coords;
};


class NewInputProcessor
{
public:
	
	NewInputProcessor();
	~NewInputProcessor();
	
	struct TouchTypes
	{
		enum
		{
			PRESS,
			MOVE,
			RELEASE
		};
	};
	
	struct TouchStates
	{
		enum
		{
			NONE,
			IDLE,
			WORLD_MOVE
		};
	};

	
	void ProcessTouch(float x, float y, int type);
	
	void SwitchState(int new_state);
	
private:
	
	//@todo: copy c-tor
	//@todo: operator =
	
	BaseTouchState * state;
};


#endif /* defined(__Game2__NewInputProcessor__) */
