#include "BaseController.h"
#include "GameEngine.h"

void BaseController::proceed(Event event)
	{		
		if((event.device == Event::Devices::keyboard) && (event.type == Event::Types::press))
		{
			switch(event.key)
			{
				case Event::Keys::arrow_down:
					GameEngine::get_instance()->player->move(HysVec2f(0.0f, -0.01f));
				break;

				case Event::Keys::arrow_up:
					GameEngine::get_instance()->player->move(HysVec2f(0.0f, 0.01f));
				break;

				case Event::Keys::arrow_left:
					GameEngine::get_instance()->player->move(HysVec2f(-0.01f, 0.0f));
				break;

				case Event::Keys::arrow_right:
					GameEngine::get_instance()->player->move(HysVec2f(0.01f, 0.0f));
				break;
			}
		}
	}