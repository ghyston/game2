#include "GameEngine.h"
#include "Gui/TouchManager.h"

GameEngine*     GameEngine::instance    = (GameEngine*) 0;
GlobalData*     GameEngine::global_data = new GlobalData();
GameGui*        GameEngine::game_gui    = new GameGui();
//TouchController* GameEngine::controller = new TouchController();
TouchManager*	GameEngine::touch_manager = new TouchManager();

GameEngine::GameEngine()
{
    renderer = new Renderer();
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

void GameEngine::draw_all()
{
    renderer->render_frame();
}

void GameEngine::move_all()
{

}

GlobalData* GameEngine::get_data()
{
    return global_data;
}

GameGui* GameEngine::get_gui()
{
    return game_gui;
}

void GameEngine::process_touch(int id, int touch_type, float x, float y)
{
	TouchEvent event;
	event.id = id;
	event.type = (TouchEvent::Enum)touch_type;
	event.coords = Vec2f(x, y);
	
	touch_manager->process(event);
	
    /*switch(touch_type)
    {
    case 0:
        controller->process_down(x, y);
        break;
        
    case 1:
        controller->process_move(x, y);
        break;
        
    case 2:
        controller->process_up(x, y);
        break;
    }*/    
}

void GameEngine::init(int width, int height)
{
    global_data->init_scene();
	global_data->screen.setup(height, width);
    renderer->init(width, height);
    
}
