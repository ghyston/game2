#include "BaseTouchProcessor.h"
#include "TouchManager.h"

void BaseTouchProcessor::process(TouchEvent& event)
{
	switch (event.type)
	{
	case TouchEvent::ACTION_DOWN:
		process_down(event.coords);
		break;

	case TouchEvent::ACTION_MOVE:
		process_move(event.coords);
		break;

	case TouchEvent::ACTION_UP:
		process_up(event.coords);
		break;
	}
}
