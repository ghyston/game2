#include "GameEngine.h"


#include "GamePlay/Components.h"
#include "GamePlay/Systems/RenderSystem.h"
#include "GamePlay/Systems/MoveSystem.h"
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
	global_data->screen.setup(height, width);
    renderer->init(width, height);
	
	global_data->logic.add_system(new RenderSystem());
	global_data->logic.add_system(new MoveSystem());
	global_data->logic.add_system(new CollisionSystem());
	
	///--------TEST_TOWER----------	
	global_data->logic.add_entity(EntityFabric::get_tower(Vec2f(0.0f, 0.1f)));	  
	  ///--------TEST_TOWER----------
	
    
}
