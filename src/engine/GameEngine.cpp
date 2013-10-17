#include "GameEngine.h"


#include "GamePlay/Components.h"
#include "GamePlay/Systems/RenderSystem.h"
#include "GamePlay/Systems/MoveSystem.h"
#include "GamePlay/Systems/TargetEnergySystem.h"
#include "Renderer/RectRenderable.h"
#include "Timer.h"
#include "GamePlay/EntityFabric.h"
#include "GamePlay/Systems/CollisionSystem.h"

GameEngine*     GameEngine::instance    = (GameEngine*) 0;
GlobalData*     GameEngine::global_data = new GlobalData();
Renderer *		GameEngine::renderer = new Renderer();

GameEngine::GameEngine()
{
    
}

GameEngine* GameEngine::get_instance()
{
    return instance;
}

bool GameEngine::create_instance()
{
    instance = new GameEngine();
    return true;
}

void GameEngine::step()
{
	Timer::tick();
    renderer->clear_frame();
    renderer->draw_grid();
	global_data->logic.step();
}

GlobalData* GameEngine::get_data()
{
    return global_data;
}

Renderer* GameEngine::get_renderer()
{
	return renderer;
}

void GameEngine::process_touch(int id, int touch_type, float x, float y)
{
	// @todo: process touch inputs here!
}

void GameEngine::init(int width, int height)
{
    global_data->init_scene();
	global_data->screen.setup(height, width); // @todo: do we need that?
    renderer->init();
    renderer->resize(width, height);

	global_data->logic.add_system(new RenderSystem());
	global_data->logic.add_system(new MoveSystem());
	global_data->logic.add_system(new CollisionSystem());
	global_data->logic.add_system(new TargetEnergySystem());
    
    Timer::start();
	
	///--------TEST----------
    Entity* tower_1 = EntityFabric::get_tower(Vec2f(0.2f, 0.0f));
    Entity* tower_2 = EntityFabric::get_tower(Vec2f(-0.5f, 0.3f));
	global_data->logic.add_entity(tower_1);
    global_data->logic.add_entity(tower_2);
    global_data->logic.add_entity(
		EntityFabric::get_connector(tower_1,tower_2));
	global_data->logic.add_entity(
		EntityFabric::create_energy(Vec2f(0.1f, -0.3f)));
	  ///--------TEST----------
	
    
}
