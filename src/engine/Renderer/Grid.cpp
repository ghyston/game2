#include "Grid.h"

void Grid::setup_vertexes()
{
    //float points[42];
    vertexes = new float [count_x * 4 + count_y * 4];
    
    float limit_y = (count_y - 1) * step / 2;
    float limit_x = (count_x - 1) * step / 2;
    
    //generate vertical lines
    for(int i1 = 0; i1 < count_x; i1++)
    {
        vertexes[i1 * 4]        = -limit_x + step * i1;
        vertexes[i1 * 4 + 1]    = -limit_y;
        vertexes[i1 * 4 + 2]    = -limit_x + step * i1;
        vertexes[i1 * 4 + 3]    = limit_y;
    }
    
    //generate vertical lines
    for(int i1 = 0; i1 < count_y; i1++)
    {
        vertexes[count_x * 4 + i1 * 4]      = -limit_x;
        vertexes[count_x * 4 + i1 * 4 + 1]  = -limit_y + step * i1;
        vertexes[count_x * 4 + i1 * 4 + 2]  = limit_x;
        vertexes[count_x * 4 + i1 * 4 + 3]  = -limit_y + step * i1;
    }
    
    color[0] = 0.1f;
    color[1] = 0.1f;
    color[2] = 0.1f;
    color[3] = 1.0f;
}