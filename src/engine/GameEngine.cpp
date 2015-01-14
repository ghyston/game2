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
int GameEngine::grid_draw = DrawGrid::DRAW_MAP_CELLS;

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
	
	if(GameEngine::grid_draw == DrawGrid::DRAW_PASS ||
	   GameEngine::grid_draw == DrawGrid::DRAW_BOTH)
		renderer->DrawPassGrid();
	
	if(GameEngine::grid_draw == DrawGrid::DRAW_MAP_CELLS ||
	   GameEngine::grid_draw == DrawGrid::DRAW_BOTH)
		renderer->draw_grid();
	
	
	global_data->logic.step();
	global_data->cursor.Draw();
	
	if(renderer->showBorderRing)
		renderer->draw_border_ring(renderer->border_ring_coords);
	
	// Test draw texture
	
	
	//Vec2f coords(0, 0);
	
	/*static GLuint texture = 0;
	static TextureRectRenderable * testRect = NULL;
	
	static GLuint texture2 = 0;
	static TextureRectRenderable * testRect2 = NULL;
	
	if(texture == 0)
	{
		TextureLoader tl;
		int textureWidth = 0;
		int textureHeight = 0;
		texture = tl.png_texture_load("/Users/Hyston/projects/game2_github/resourses/biohazard.png", &textureWidth, &textureHeight);
	}
	
	if(testRect == NULL)
	{
		testRect = new TextureRectRenderable();
		testRect->set_height(0.1f);
		testRect->set_width(0.1f);
		testRect->setTexture(texture);
		testRect->set_shader(renderer->getTextureShader());
		testRect->setup_vertexes();
		testRect->SetColor(0.0f, 0.0f, 1.0f);
	}
	
	if(texture2 == 0)
	{
		TextureLoader tl;
		int textureWidth = 0;
		int textureHeight = 0;
		texture2 = tl.png_texture_load("/Users/Hyston/projects/game2_github/resourses/monster_cupcake.png", &textureWidth, &textureHeight);
	}
	
	if(testRect2 == NULL)
	{
		testRect2 = new TextureRectRenderable();
		testRect2->set_height(0.1f);
		testRect2->set_width(0.1f);
		testRect2->setTexture(texture2);
		testRect2->set_shader(renderer->getTextureShader());
		testRect2->setup_vertexes();
		testRect2->SetColor(0.0f, 0.0f, 1.0f);
		testRect2->coords = Vec2f(0.1f, 0.1f);
	}
	
	testRect->Draw();
	testRect2->Draw();*/
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

void GameEngine::process_input(int key, int action)
{
	//@todo: this is test feature, not fhinished correctly
	if(key == 'A' && action == 1) //inrease
	{
		float current_zoom = global_data->camera->zoom_koeff;
		current_zoom += 0.1;
		global_data->camera->zoom(current_zoom);
	}
	else if (key == 'S' && action == 1)
	{
		float current_zoom = global_data->camera->zoom_koeff;
		current_zoom -= 0.1;
		global_data->camera->zoom(current_zoom);
	}
	else if (key == 'R' && action == 1)
	{
		global_data->camera->zoom(1.0f);
	}
	else if (key == 'G' && action == 1)
	{
		GameEngine::grid_draw++;
		GameEngine::grid_draw %= 4;
	}
	// Path finding is not ready now.
	else if (key == 'P')
	{
		if(action == 1) //press
		{
			input_processor->pathKeyPressed = true;
		}
		else if(action == 0) //release
		{
			input_processor->pathKeyPressed = false;
		}
	}
}

void GameEngine::init(int width, int height)
{
	//test_vectors();
	//test_shr_ptr();
	//test_math();
	renderer->init();
    renderer->resize(width, height);
	global_data->logic.LoadMap(3, 3);
    global_data->init_scene();
	global_data->screen.setup(height, width); // @todo: do we need that?
    
	global_data->logic.start();
    
    Timer::start();
    
}
