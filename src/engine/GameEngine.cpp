#include "GameEngine.h"


#include "GamePlay/Components.h"
#include "Renderer/RectRenderable.h"
#include "Timer.h"
#include "GamePlay/EntityFabric.h"

GameEngine*     GameEngine::instance    = (GameEngine*) 0;
GlobalData*     GameEngine::global_data = new GlobalData();
Renderer *		GameEngine::renderer = new Renderer();
InputProcessor* GameEngine::input_processor = new InputProcessor();
NewInputProcessor* GameEngine::new_input_processor = new NewInputProcessor();

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
	renderer->DrawPassGrid();
	global_data->logic.step();
	global_data->cursor.Draw();
	renderer->draw_small_rect(global_data->camera->coords);
	if(renderer->showBorderRing)
		renderer->draw_border_ring(renderer->border_ring_coords);
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
	//Vec2f world_coords = GameEngine::global_data->convert_coordinates(Vec2f(x, y));
	//new_input_processor->ProcessTouch(world_coords.x, world_coords.y, touch_type);
	input_processor->process_touch(touch_type, x, y);
}

void GameEngine::process_input(int key)
{
	//@todo: this is test feature, not fhinished correctly
	if(key == 'A') //inrease
	{
		float current_zoom = global_data->camera->zoom_koeff;
		current_zoom += 0.1;
		global_data->camera->zoom(current_zoom);
	}
	else if (key == 'S')
	{
		float current_zoom = global_data->camera->zoom_koeff;
		current_zoom -= 0.1;
		global_data->camera->zoom(current_zoom);
	}
	else if (key == 'R')
	{
		global_data->camera->zoom(1.0f);
	}
}

void GameEngine::init(int width, int height)
{
	//test_vectors();
	//test_shr_ptr();
	renderer->init();
    renderer->resize(width, height);
	global_data->logic.LoadMap(30, 30, 0.4f);
    global_data->init_scene();
	global_data->screen.setup(height, width); // @todo: do we need that?
    
	global_data->logic.start();
    
    Timer::start();
    
}
