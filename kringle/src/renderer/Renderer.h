#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "GlInclude.h"
#include <math.h>
#include "renderer/Shader.h"
#include "renderer/Camera.h"
#include "common/Matrix4f.h"

#include "renderer/RectRenderable.h"
#include "renderer/LineRenderable.h"
#include "renderer/TowerRenderable.h"
#include "renderer/CircleRenderable.h"
#include "renderer/RingRenderable.h"
#include "renderer/Grid.h"
#include "renderer/RectGrid.h"
#include "renderer/TriangleRenderable.h"
#include "renderer/PolygonRenderable.h"
#include "renderer/HexGrid.h"

#include "renderer/TextureHelper.h"
#include "renderer/TextureRectRenderable.h"

/**
 * Main call for draw graphix.
 */
class Renderer 
{
public:
	
	Renderer();
	
	~Renderer();
	
    void init();
    
    void resize(int width, int height);

	void clear_frame();
	void clear_frame_for_postrender();
    
    void draw_rect(Vec2f coords);
    void draw_small_rect(Vec2f coords);
    void draw_line(Vec2f coord_1, Vec2f coord_2);
    void draw_grid();
	void DrawPassGrid();
	//@note: energy should be 0.0f .. 1.0f!
	void draw_tower(Vec2f coords, float energy, bool is_enemy = false);
	void draw_circle(Vec2f coords);
	void draw_ring(Vec2f coords);
	void DrawTriangle(Vec2f coords, float angle);
	void DrawPolygon(Vec2f coords, int mesh_id);
	void drawHexGrid(Vec2f coords);
	
	//@todo: this is hardcode
	void draw_border_ring(Vec2f coords);
	bool showBorderRing;
	Vec2f border_ring_coords;
	
	void SetupGrid(int count_x, int count_y, float cell_size);
	void SetupPassGrid(int count_x, int count_y, float cell_size);
	
	int SetupPolygon(const std::vector<Vec2f>& points);
	
private:
    
    void init_shaders();
	
public: //@todo: remove!
    GLuint get_simple_shader()	{ return simple_shader; }
	GLuint getTextureShader()	{ return _textureShader; }
	GLuint getBWShader()	{ return _bwShader; }
	GLuint getBlurShader()	{ return _blurShader; }
private:
	
	Matrix4f* ortho;
	Matrix4f* mx_translate;
	Matrix4f* mx_scale;
	Matrix4f* mx_rotate;
	

    void setup_ortho(
            float left, float right,
            float bottom, float top,
            float near = -1.0f, float far = 1.0f);

	// Shader handlers
    GLuint simple_shader;
	GLuint _textureShader;
	GLuint _bwShader;
	GLuint _blurShader;
	
    //Primitives.
    void init_rect();
    void init_grid();
	void InitPassGrid();
    void init_line();
	void init_tower();
	void init_circle();
	void init_ring();
	void InitTriangle();
	void InitPolygon();
	void initHexGrid();
    
    RectRenderable * rect;
    RectRenderable * small_rect;
    Grid * grid;
	RectGrid * pass_grid;
    LineRenderable * line;
	TowerRenderable * tower_rend;
	CircleRenderable * circle;	
	RingRenderable * ring;
	RingRenderable * border_ring;
	TriangleRenderable * triangle;
	PolygonRenderable * polygon;
	HexGrid * _hexGrid;
	
	std::vector<float*> meshes;

};

#endif //__RENDERER_H__
