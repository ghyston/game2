#include "Grid.h"

void Grid::Draw()
{
	if(!is_set)
		return;
	
	BaseRenderable::Draw();
}

void Grid::setup_vertexes()
{
    //float points[42];
    vertexes = new float [vertexes_count * 2];
    
    float limit_y = count_y * step;
    float limit_x = count_x * step;
    
    //generate vertical lines
    for(int i1 = 0; i1 <= (2 * count_x + 1); i1++)
    {
        vertexes[i1 * 4]        = -limit_x + step * i1;
        vertexes[i1 * 4 + 1]    = -limit_y;
        vertexes[i1 * 4 + 2]    = -limit_x + step * i1;
        vertexes[i1 * 4 + 3]    = limit_y;
    }
    
    //generate vertical lines
    for(int i1 = 0; i1 <= (2 * count_y + 1); i1++)
    {
        vertexes[(1 + 2 * count_x) * 4 + i1 * 4]      = -limit_x;
        vertexes[(1 + 2 * count_x) * 4 + i1 * 4 + 1]  = -limit_y + step * i1;
        vertexes[(1 + 2 * count_x) * 4 + i1 * 4 + 2]  = limit_x;
        vertexes[(1 + 2 * count_x) * 4 + i1 * 4 + 3]  = -limit_y + step * i1;
    }
}

void Grid::SetParams(int count_x, int count_y, float cell_size)
{
	this->count_x = count_x;
	this->count_y = count_y;
	this->step = cell_size;
	this->vertexes_count = (2 * count_x + 1) * 2 + (2 * count_y + 1) * 2;
	setup_vertexes();
	if(count_x > 0 && count_y > 0 && cell_size > 0.0f)
		is_set = true;
}
