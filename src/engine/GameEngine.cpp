#include "GameEngine.h"

GameEngine* GameEngine::instance = (GameEngine*) 0;
GlobalData* GameEngine::global_data = new GlobalData();

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

void GameEngine::init(int width, int height)
{
    global_data->init_scene();
    renderer->init(width, height);    
}
