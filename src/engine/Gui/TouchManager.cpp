#include "TouchManager.h"
#include "GameGui.h"
#include "../GameEngine.h"
#include "TowerTouchProcessor.h"

void TouchManager::process()
{
	is_processed = true;
	//TODO: pop loop
	for(size_t i = 0; i < touch_events.size(); i++)
	{
		process(touch_events[i]);
	}
	touch_events.clear();
	is_processed = false;
}

void TouchManager::push_event(const TouchEvent& touch_event)
{
	//GameEngine::get_instance()->get_data()->tower_mutex.Lock();
	BaseTower* last_tower = 
	  GameEngine::get_instance()->get_data()->towers.back();
	GameEngine::get_instance()->get_data()->add_tower(
	  Vec2f(last_tower->coords.x + 0.01f, last_tower->coords.x + 0.01f));
	//GameEngine::get_instance()->get_data()->tower_mutex.Unlock();
	
	
	
	//if(!is_processed)
	//	touch_events.push_back(touch_event);	
}

void TouchManager::process(TouchEvent& touch_event)
{	
	//On new finger - create new processor
	if(touch_event.type == TouchEvent::ACTION_DOWN)
		processors[touch_event.id] = 
		  ChooseProcessor(touch_event.coords);	
	
	//Just checking, assert is better.
	if(processors[touch_event.id] == NULL) return;
	
	//Translate coords and send action to processor
	touch_event.coords = 
	  processors[touch_event.id]->translate_coords(touch_event.coords);
	processors[touch_event.id]->process(touch_event);
  
	//On finger release - del processor
	if(touch_event.type == TouchEvent::ACTION_UP)
	{
		delete processors[touch_event.id];
		processors[touch_event.id] = NULL;
	}
}

Vec2f TouchManager::translateCoordsDevToSpace(Vec2f device_coords)
{
    //Worst code, that I have ever wrote. Ever.
    float dev_x = device_coords.x;
    float dev_y = device_coords.y;
    
    float x = dev_x / (float)(GameEngine::get_instance()->get_data()->screen.width);
    float y = dev_y / (float)(GameEngine::get_instance()->get_data()->screen.height);    
    float rank = GameEngine::get_instance()->get_data()->screen.ratio;
    
    x = 2.0f * x - 1.0f;
    y = rank * (- 2.0f * y + 1.0f);
    
    return Vec2f(x, y);
}

BaseTouchProcessor* TouchManager::ChooseProcessor(Vec2f coords)
{
	Vec2f space_coords = translateCoordsDevToSpace(coords);
	//TODO: gui is not realized yet
	//GameEngine::get_instance()->get_gui()->on_touch(space_coords.x, space_coords.y);	

	BaseTower* touched_tower = 
		GameEngine::get_instance()->get_data()->touch_tower(space_coords);
	
	if(touched_tower != NULL)
		return new TowerTouchProcessor(touched_tower);
	else
		return NULL;
}