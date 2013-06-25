#include <vector>

#include "GlobalData.h"
#include "Renderer/SceneObject.h"
#include "Common/ThreadLock.h"
#include "GameEngine.h"

bool GlobalData::init_scene()
{	
	camera = new Camera();	
    return true;
}
/*
BaseTower* GlobalData::add_tower(Vec2f coords)
{		
	BaseTower* new_tower = new BaseTower(coords.x, coords.y);	
	towers.push_back(new_tower);
	return new_tower;
}

BaseTower* GlobalData::touch_tower(Vec2f coords)
{
	//tower_mutex.Lock();
	for(size_t i = 0; i < towers.size(); i++)
	{
		if(towers[i]->is_touched(coords))
		{
			//tower_mutex.Unlock();
			return towers[i];
		}
	}
	//tower_mutex.Unlock();
	return NULL;
}*/