#include <vector>

#include "GlobalData.h"
#include "Common/ThreadLock.h"
#include "GameEngine.h"
#include "GamePlay/EntityFabric.h"

bool GlobalData::init_scene()
{	
	camera = new Camera();

	//-----TEST-----
	Entity * generator = EntityFabric::create_energy_generator(
		Vec2f(-0.6f, -0.4f), 0.3, 0.07);
	logic.add_entity(generator);
	
    Entity* tower_1 = EntityFabric::get_tower(NULL, Vec2f(0.9f, 0.0f));
    Entity* tower_2 = EntityFabric::get_tower(tower_1, Vec2f(0.2f, 0.3f));
	Entity* tower_3 = EntityFabric::get_tower(tower_1, Vec2f(0.5f, 0.4f));
	Entity* tower_4 = EntityFabric::get_tower(tower_2, Vec2f(-0.6f, -0.4f));
	Entity* tower_5 = EntityFabric::get_tower(tower_2, Vec2f(-0.4f, 0.4f));
	
	logic.add_entity(tower_1);
    logic.add_entity(tower_2);
	logic.add_entity(tower_3);
    logic.add_entity(tower_4);
	logic.add_entity(tower_5);
	
    logic.add_entity(EntityFabric::get_connector(tower_1,tower_2));
	
    return true;
}

Vec2f GlobalData::convert_coordinates(Vec2f screen_coord)
{
	Vec2f result;
	result.x = - 2.0f * screen_coord.x / screen.width + 1.0f;
	result.y = 2.0f * screen.ratio * screen_coord.y / screen.height - screen.ratio; // @todo: too expencive every time
	
	return result;
}