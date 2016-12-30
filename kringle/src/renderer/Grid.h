#ifndef __GRID_H__
#define __GRID_H__

#include "BaseRenderable.h"

/**
 * Grid class represents base renderable grid.
 */
class Grid : public BaseRenderable
{
public:
    
    Grid() : BaseRenderable(), is_set(false)
    {
        draw_type = GL_LINES;
    }
	
	void SetParams(int count_x, int count_y, float cell_size);
	
    virtual void setup_vertexes();
	virtual void Draw();
	
private:
	bool is_set;
    
	int count_x;
    int count_y;
    float step;
};

#endif //__GRID_H__
