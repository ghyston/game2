
#include "NewInputProcessor.h"
#include "OutherAPI.h"

/*
 *	BaseTouchState
 */
int BaseTouchState::OnPress(float x, float y)
{
	return NewInputProcessor::TouchStates::NONE;
}

int BaseTouchState::OnMove(float x, float y)
{
	return NewInputProcessor::TouchStates::NONE;
}

int BaseTouchState::OnRelease(float x, float y)
{
	return NewInputProcessor::TouchStates::NONE;
}


/*
 *	IdleTouchState
 */
int IdleTouchState::OnPress(float x, float y)
{
	return NewInputProcessor::TouchStates::WORLD_MOVE;
}


/*
 *	MoveWorldTouchState
 */
int MoveWorldTouchState::OnMove(float x, float y)
{
	OutherAPI::MoveWorld(x, y);
	return NewInputProcessor::TouchStates::NONE;
}

int MoveWorldTouchState::OnRelease(float x, float y)
{
	return NewInputProcessor::TouchStates::IDLE;
}


/*
*	NewInputProcessor
*/
NewInputProcessor::NewInputProcessor()
{
	state = new IdleTouchState();
}

NewInputProcessor::~NewInputProcessor()
{
	delete state;
}

void NewInputProcessor::ProcessTouch(float x, float y, int type)
{
	int new_state = TouchStates::NONE;
	
	switch (type)
	{
		case TouchTypes::PRESS:
			new_state = state->OnPress(x, y);
			break;
			
		case TouchTypes::MOVE:
			new_state = state->OnMove(x, y);
			break;
			
		case TouchTypes::RELEASE:
			new_state = state->OnRelease(x, y);
			break;
			
		default:
			//@todo: we need to handle error touches!
			break;
	}
	SwitchState(new_state);
}

void NewInputProcessor::SwitchState(int new_state)
{
	// we doesn't need to change state here
	if(new_state == TouchStates::NONE)
		return;
	
	//Save old state;
	BaseTouchState * old_state = state;
	
	switch (new_state)
	{
		case TouchStates::IDLE:
			state = new IdleTouchState();
			break;
			
		case TouchStates::WORLD_MOVE:
			state = new MoveWorldTouchState();
//@todo: it can be easier!
//			(MoveWorldTouchState*)state->press_coords(old_state->prev_x)
			break;
			
		default:
			break;
	}
	delete old_state;
}