#include "Renderer.h"
#include "shaders.h"
#include "BaseRenderable.h"
#include "Grid.h"
#include "../GameEngine.h"

Renderer::Renderer()
{
    rect = NULL;
    grid = NULL;
	circle = NULL;
	
	showBorderRing = false;
}

Renderer::~Renderer()
{
    if(grid != NULL) delete grid;
    if(rect != NULL) delete rect;
	delete ortho;
}

void Renderer::init()
{
	init_shaders();

	ortho = new Matrix4f();
	mx_translate = new Matrix4f();
	mx_scale = new Matrix4f();
	mx_rotate = new Matrix4f();
    
    init_rect();
    init_grid();
    init_line();
	init_tower();
	init_circle();
	init_ring();
}

void Renderer::init_rect()
{
    // @todo: height and width is temparable
    rect = new RectRenderable(0.1f, 0.1f);
    rect->setup_vertexes();
    rect->set_shader(simple_shader);
    rect->color[0] = 0.0f;
	rect->color[1] = 0.0f;
	rect->color[2] = 1.0f;
    
    // @todo: height and width is temparable
    small_rect = new RectRenderable(0.02f, 0.02f);
    small_rect->setup_vertexes();
    small_rect->set_shader(simple_shader);
    small_rect->color[0] = 1.0f;
	small_rect->color[1] = 0.2f;
	small_rect->color[2] = 0.2f;
}

void Renderer::init_grid()
{
    grid = new Grid();
   // grid->step = 0.01f;
    grid->setup_vertexes();
    grid->set_shader(simple_shader);
    grid->color[0] = 0.8f;
	grid->color[1] = 0.8f;
	grid->color[2] = 0.8f;
}

void Renderer::init_line()
{
    line = new LineRenderable();
    line->set_shader(simple_shader);
    line->vertexes = new float [4];
    
    line->color[0] = 0.0f;
    line->color[1] = 1.0f;
    line->color[2] = 0.0f;
    line->color[3] = 1.0f;
}

void Renderer::init_tower()
{
	tower_rend = new TowerRenderable();
	tower_rend->set_shader(simple_shader);
	tower_rend->Init();
}

void Renderer::init_circle()
{
	circle = new CircleRenderable();
	circle->set_shader(simple_shader);
	circle->radius(0.3f); //value here is hardcoded
	circle->setup_vertexes();
	circle->color[0] = 0.2f;
    circle->color[1] = 0.5f;
    circle->color[2] = 0.2f;
    circle->color[3] = 1.0f;
}

void Renderer::init_ring()
{
	ring = new RingRenderable();
	ring->set_shader(simple_shader);
	ring->radius(0.05f);
	ring->setup_vertexes();
	ring->color[0] = 0.1f;
    ring->color[1] = 0.8f;
    ring->color[2] = 0.4f;
    ring->color[3] = 1.0f;
	
	border_ring = new RingRenderable();
	border_ring->set_shader(simple_shader);
	border_ring->radius(0.4f); //@todo: WHAT THE FUCK?!!
	// @todo: HYSTON!!!! REMOVE this F-U-C-K-I-N-G HARDCODE!!!
	// Seriously, you should stop doing that.
	// But, I have only 20 min to finish gameplay :(
	border_ring->setup_vertexes();
	border_ring->color[0] = 0.5f;
    border_ring->color[1] = 0.2f;
    border_ring->color[2] = 0.3f;
    border_ring->color[3] = 1.0f;
}



void Renderer::draw_grid()
{
    if(grid != NULL)
        grid->Draw();
}

void Renderer::draw_rect(Vec2f coords)
{
    if(rect != NULL)
    {
        rect->coords = coords;
        rect->Draw();
    }
}

void Renderer::draw_small_rect(Vec2f coords)
{
    if(small_rect != NULL)
    {
        small_rect->coords = coords;
        small_rect->Draw();
    }
}

void Renderer::draw_line(Vec2f coord_1, Vec2f coord_2)
{
    if(line == NULL)
        return;
    
    line->start = coord_1;
    line->end = coord_2;
    line->setup_vertexes();
    line->Draw();
}

void Renderer::draw_tower(Vec2f coords, float energy, bool is_enemy/* = false*/)
{
	if(is_enemy)
	{
		tower_rend->front->color[0] = 0.7f;
		tower_rend->front->color[1] = 0.2f;
		tower_rend->front->color[2] = 0.2f;
	}
	else
	{
		tower_rend->front->color[0] = 0.0f;
		tower_rend->front->color[1] = 0.3f;
		tower_rend->front->color[2] = 0.9f;
	}
	
	tower_rend->coords = coords;
	tower_rend->set_energy(energy);
	tower_rend->Draw();
}

void Renderer::draw_circle(Vec2f coords)
{
	if(circle == NULL)
		return;
	
	circle->coords = coords;
	circle->Draw();
}

void Renderer::draw_ring(Vec2f coords)
{
	if(ring == NULL)
		return;
	
	ring->coords = coords;
	ring->Draw();
}

void Renderer::draw_border_ring(Vec2f coords)
{
	if(border_ring == NULL)
		return;
	
	border_ring->coords = coords;
	border_ring->Draw();
}

void Renderer::resize(int width, int height)
{
    glViewport(0, 0, width, height);
}

void Renderer::clear_frame()
{
	glClearColor(0.95f, 0.95f, 0.95f, 1.0f);
	
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	Vec2f cam_pos = GameEngine::get_data()->camera->coords;
	float zoom = GameEngine::get_data()->camera->zoom_koeff;
	float koeff = GameEngine::get_data()->screen.ratio;
	setup_ortho(
		cam_pos.x - zoom * 1.0f, cam_pos.x + zoom * 1.0f,
		cam_pos.y - zoom * koeff, cam_pos.y + zoom * koeff);
}

void Renderer::init_shaders()
{
    // @todo: add glGetError() checking!
	simple_shader = Shader::createProgram(gVertexShader, gFragmentShader);
	gvPositionHandle = glGetAttribLocation(simple_shader, "vPosition");
}

void Renderer::setup_ortho(float left, float right, float bottom, float top, float near, float far)
{
	float a = 2.0f / (right - left);
	float b = 2.0f / (top - bottom);
	float c = -2.0f / (far - near);

	float tx = -(right + left) / 2.0f;
	float ty = -(top + bottom) / 2.0f;
	float tz = -(far + near) / (far - near);

	mx_translate->Translate(tx, ty, tz);
	mx_scale->Scale(a, b, c);
	mx_rotate->Identity();
	matrixMultiply(*mx_scale, *mx_translate, *ortho);
	GLint projectionUniform = glGetUniformLocation(simple_shader, "Projection");
	glUniformMatrix4fv(projectionUniform, 1, GL_FALSE, ortho->get_val());

}
