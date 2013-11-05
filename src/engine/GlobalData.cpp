#include <vector>

#include "GlobalData.h"
#include "Common/ThreadLock.h"
#include "GameEngine.h"
#include "GamePlay/EntityFabric.h"

bool GlobalData::init_scene()
{	
	camera = new Camera();

	//-----TEST-----
    Entity* tower_1 = EntityFabric::get_tower(Vec2f(0.2f, 0.0f));
    Entity* tower_2 = EntityFabric::get_tower(Vec2f(-0.5f, 0.3f));
	logic.add_entity(tower_1);
    logic.add_entity(tower_2);
    logic.add_entity(EntityFabric::get_connector(tower_1,tower_2));
	
	for(int i = 0; i < 25; ++i)
	{
		logic.add_entity(EntityFabric::create_energy(Vec2f(0.1f, -0.3f)));
	}
    return true;
}
