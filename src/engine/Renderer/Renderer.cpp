#include "Renderer.h"
#include "shaders.h"
#include "BaseRenderable.h"
#include "Grid.h"
#include "../GameEngine.h"

void Renderer::init(int width, int height)
{
	glViewport(0, 0, width, height);
	init_shaders();

	//grid.set_shader(simple_shader);
	//grid.setup_vertexes();

	ortho = new Matrix4f();
	mx_translate = new Matrix4f();
	mx_scale = new Matrix4f();
	mx_rotate = new Matrix4f();

	//setup gui. TODO: move it to fabric or somewhat
	//GameEngine::get_gui()->reset_widget_iterator();
	/*Widget* widget = GameEngine::get_gui()->get_first_widget();
	//while(widget != NULL)
	//{
	widget->set_shader(simple_shader);
	
	//TODO: remove it!
	for(size_t i = 0; i < GameEngine::get_instance()->get_data()->towers.size(); i++)
	{
		BaseTower* tower = GameEngine::get_instance()->get_data()->towers[i];
		tower->setup_vertexes();
		tower->set_shader(simple_shader);
	}	*/
}

void Renderer::clear_frame()
{
	glClearColor(0.9f, 0.9f, 0.9f, 1.0f);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	Vec2f cam_pos = GameEngine::get_data()->camera->coords;
	float koeff = GameEngine::get_data()->screen.ratio;
	setup_ortho(
		cam_pos.x - 1.0f, cam_pos.x + 1.0f,
		cam_pos.y - koeff, cam_pos.y + koeff);
}

/*void Renderer::render_frame()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	Vec2f cam_pos = GameEngine::get_data()->camera->coords;
	float koeff = GameEngine::get_data()->screen.ratio;
	setup_ortho(
		cam_pos.x - 1.0f, cam_pos.x + 1.0f,
		cam_pos.y - koeff, cam_pos.y + koeff);
	
	grid.Draw();


	GameEngine::get_gui()->draw_gui();
	draw_game_play();
}*/

void Renderer::init_shaders()
{
	simple_shader = Shader::createProgram(gVertexShader, gFragmentShader);
	gvPositionHandle = glGetAttribLocation(simple_shader, "vPosition");
}

void Renderer::setup_ortho(float left, float right, float bottom, float top, float near, float far)
{
	float a = 2.0f / (right - left);
	float b = 2.0f / (top - bottom);
	float c = -2.0f / (far - near);

	float tx = -(right + left) / (right - left);
	float ty = -(top + bottom) / (top - bottom);
	float tz = -(far + near) / (far - near);

	mx_translate->Translate(tx, ty, tz);
	mx_scale->Scale(a, b, c);
	mx_rotate->Identity();
	matrixMultiply(*mx_scale, *mx_translate, *ortho);
	//ortho->Translate(tx, ty, tz);
	//ortho->Scale(a, b, c);

	GLint projectionUniform = glGetUniformLocation(simple_shader, "Projection");
	glUniformMatrix4fv(projectionUniform, 1, GL_FALSE, ortho->get_val()/*&ortho[0]*/);

}

/*void Renderer::move_camera(Vec2f diff)
{

}*/

/*void Renderer::set_default_shader(BaseRenderable * object)
{
	object->set_shader(simple_shader);
}*/

/*void Renderer::draw_game_play()
{
	GameEngine::get_instance()->get_data()->tower_mutex->Lock();
	for(size_t i = 0; 
	  i < GameEngine::get_instance()->get_data()->towers.size(); i++)
	{
		GameEngine::get_instance()->get_data()->towers[i]->set_shader(simple_shader);
		GameEngine::get_instance()->get_data()->towers[i]->Draw();
	}
	
	GameEngine::get_instance()->get_data()->tower_mutex->Unlock();
}*/

Renderer::~Renderer()
{
	delete ortho;
}