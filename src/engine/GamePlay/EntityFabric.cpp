#include "EntityFabric.h"
#include "../GameEngine.h"

Entity * EntityFabric::get_tower(Vec2f coords)
{
	Entity* tower = new Entity();
	
	//setup pos component
	PositionComponent * pos_com = new PositionComponent();
	pos_com->position = coords;	
	tower->add_component(ComponentsType::POSITION_COMPONENT, pos_com);
	
	//setup render component
	RenderComponent * render_com = new RenderComponent();
	
	/*float t_width = 0.2f;
	float t_height = 0.2f;
	
	float h2 = t_height / 2;
	float w2 = t_width / 2;
		
	render_com->vertexes = new float[8];
	render_com->vertexes[0] = -w2;
		
	render_com->vertexes[1] = -h2;
	render_com->vertexes[2] = -w2;
	render_com->vertexes[3] =  h2;
		
	render_com->vertexes[4] =  w2;
	render_com->vertexes[5] = -h2;
		
	render_com->vertexes[6] =  w2;
	render_com->vertexes[7] =  h2;
    
	render_com->vertexes_count = 4;
	
	render_com->color[0] = 0.0f;
	render_com->color[1] = 0.0f;
	render_com->color[2] = 1.0f;
	
	render_com->draw_type = GL_TRIANGLE_STRIP;
	render_com->shader = GameEngine::get_renderer()->get_simple_shader();
	*/
	tower->add_component(ComponentsType::RENDER_COMPONENT, render_com);
	
	//setup move component
	MovementComponent * move_com = new MovementComponent();
	move_com->speed = Vec2f(0.0f, 0.0f);
	move_com->velocity = Vec2f(0.2f, -0.03f);
	tower->add_component(ComponentsType::MOVEMENT_COMPONENT, move_com);
	return tower;
}
