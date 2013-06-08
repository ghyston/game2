#include "TowerTouchProcessor.h"
#include "../GameEngine.h"

void TowerTouchProcessor::process_down(Vec2f coords)
{
	BaseTower* new_tower = 
	  GameEngine::get_instance()->get_data()->add_tower(coords);
	
	//tower = new_tower;
	
	//towers.push_back(new_tower);
	//GameEngine::get_instance()->get_data()->add_tower(coords);
}

void TowerTouchProcessor::process_move(Vec2f coords)
{
	tower->coords = coords;
}

void TowerTouchProcessor::process_up(Vec2f coords)
{
	tower = NULL;
}

Vec2f TowerTouchProcessor::translate_coords(Vec2f device_coords)
{
	return TouchManager::translateCoordsDevToSpace(device_coords);
}
