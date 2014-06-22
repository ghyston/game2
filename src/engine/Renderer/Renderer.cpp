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
	InitPassGrid();
    init_line();
	init_tower();
	init_circle();
	init_ring();
	InitTriangle();
	InitPolygon();
}

void Renderer::init_rect()
{
    // @todo: height and width is temparable
    rect = new RectRenderable(0.1f, 0.1f);
    rect->setup_vertexes();
    rect->set_shader(simple_shader);
	rect->SetColor(0.0f, 0.0f, 1.0f);
    
    // @todo: height and width is temparable
    small_rect = new RectRenderable(0.02f, 0.02f);
    small_rect->setup_vertexes();
    small_rect->set_shader(simple_shader);
	small_rect->SetColor(1.0f, 0.2f, 0.2f);
}

void Renderer::init_grid()
{
    grid = new Grid();
	Color3f gray_color(0.7f);
	grid->SetColor(gray_color);
    grid->set_shader(simple_shader);
}

void Renderer::SetupGrid(int count_x, int count_y, float cell_size)
{
	grid->SetParams(count_x, count_y, cell_size);
}

int Renderer::SetupPolygon(const std::vector<Vec2f>& points)
{
	for(auto it = points.begin(); it != points.end(); it++)
	{
		polygon->AddVertex(*it);
	}
	polygon->setup_vertexes();
	meshes.push_back(polygon->vertexes);
	//@todo: not a good thing, cannot delete vertexes here
	return (meshes.size() - 1);
}

void Renderer::InitPassGrid()
{
	pass_grid = new RectGrid();
	pass_grid->set_shader(simple_shader);
}

void Renderer::SetupPassGrid(int count_x, int count_y, float cell_size)
{
	pass_grid->SetParams(count_x, count_y, cell_size);
}

void Renderer::init_line()
{
    line = new LineRenderable();
    line->set_shader(simple_shader);
    line->vertexes = new float [4];
    line->SetColor(0.0f, 1.0f, 0.0f);
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
	circle->radius(GameConst::GENERATOR_RAD);
	circle->setup_vertexes();
	circle->SetColor(0.2f, 0.5f, 0.2f);
}

void Renderer::init_ring()
{
	ring = new RingRenderable();
	ring->set_shader(simple_shader);
	ring->radius(GameConst::TOWER_TOUCH_SIZE);
	ring->setup_vertexes();
	ring->SetColor(0.1f, 0.8f, 0.4f);
	
	border_ring = new RingRenderable();
	border_ring->set_shader(simple_shader);
	border_ring->radius(GameConst::TOWER_MAX_DIST);
	border_ring->setup_vertexes();
	border_ring->SetColor(0.5f, 0.2f, 0.3f);
}

void Renderer::InitTriangle()
{
	triangle = new TriangleRenderable();
	triangle->set_shader(simple_shader);
	triangle->radius(0.05f);
	triangle->SetColor(0.7f, 0.1f, 0.3f);
	triangle->setup_vertexes();
}

void Renderer::InitPolygon()
{
	polygon = new PolygonRenderable();
	polygon->set_shader(simple_shader);
	polygon->SetColor(0.5f, 0.5f, 0.5f);
}

void Renderer::draw_grid()
{
    if(grid != NULL)
        grid->Draw();
}

void Renderer::DrawPassGrid()
{
    if(pass_grid != NULL && pass_grid->IsSet())
        pass_grid->Draw();
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
		tower_rend->front->SetColor(0.7f, 0.2f, 0.2f);
	}
	else
	{
		tower_rend->front->SetColor(0.0f, 0.3f, 0.9f);
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

void Renderer::DrawTriangle(Vec2f coords, float angle)
{
	if(triangle == NULL)
		return;
		
	triangle->coords = coords;
	triangle->angle = angle;
	triangle->Draw();
}

void Renderer::DrawPolygon(Vec2f coords, int mesh_id)
{
	if(polygon == NULL)
		return;
	
	if(mesh_id < 0 || mesh_id >= meshes.size())
		return;
	
	polygon->vertexes = meshes[mesh_id];
	polygon->coords = coords;
	polygon->Draw();
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
