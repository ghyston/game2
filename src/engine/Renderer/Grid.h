#ifndef __GRID_H__
#define __GRID_H__

#include "BaseRenderable.h"

class Grid : public BaseRenderable
{
public:
    
    Grid() : BaseRenderable()
    {
        count_x = 21;
        count_y = 21;
        step = 0.5f;		
		vertexes_count = (count_x + count_y) * 2;
		draw_type = GL_LINES;
    }
    
    int count_x;
    int count_y;
    float step;
	
    void generate_grid();	
    
};

#endif //__GRID_H__