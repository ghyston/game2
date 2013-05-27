#include "TouchController.h"
#include "../GameEngine.h"

bool TouchController::process_down(float x, float y)
{
    Vec2f space_coords = translateCoordsDevToSpace(Vec2f(x, y));
    switch(state)
    {
        case Idle:
        {
			Vec2f cam_pos = GameEngine::get_instance()->get_data()->camera->coords;
			
            touched_widget = 
                GameEngine::get_gui()->on_touch(space_coords.x + cam_pos.x, space_coords.y + cam_pos.y);
            if(touched_widget != NULL)
            {
                state = WidgetDragged;
            }
            else
            {
                touched_point = space_coords;
                state = MapDragged;
            }
            return true;
            break;
        }
            
    case WidgetDragged:
        break;
        
    case MapDragged:
                break;
    }
       
    return false;        
}
	
bool TouchController::process_move(float x, float y)
{
    Vec2f space_coords = translateCoordsDevToSpace(Vec2f(x, y));
    switch(state)
    {
    case Idle:
        return false;
        break;
        
    case WidgetDragged:
    {
        if(touched_widget == NULL)
                return false;
        touched_widget->coords = 
		  space_coords + GameEngine::get_instance()->get_data()->camera->coords;  
        break;
    }
        
    case MapDragged:
		GameEngine::get_instance()->get_data()->camera->move(			
			touched_point - space_coords);
		touched_point = space_coords;
        break;
    }
    
    return false;
}
	
bool TouchController::process_up(float x, float y)
{
    switch(state)
    {
    case Idle:
        break;
        
    case WidgetDragged:
        touched_widget->on_release();
        touched_widget = NULL;
        state = Idle; 
        return true;
        break;
        
    case MapDragged:
        touched_point.x = -1.0f;
        touched_point.y = -1.0f;
        state = Idle;
        return true;
        break;
        
    }
}

Vec2f TouchController::translateCoordsDevToSpace(Vec2f device_coords)
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

