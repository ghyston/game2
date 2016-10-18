//
//  HexGrid.hpp
//  Game2
//
//  Created by Stepanov Ilia on 17/10/2016.
//  Copyright © 2016 Stepanov Ilia. All rights reserved.
//

#ifndef HexGrid_hpp
#define HexGrid_hpp

#include "BaseRenderable.h"

class HexGrid : public BaseRenderable
{
public:
	
	HexGrid(int width, int height, float side) :
		_w(width), _h(height), _side(side),
		BaseRenderable()
	{
		vertexes_count = 6 * _w * _h;
		draw_type = GL_LINE_LOOP;
	}
	
	float _side;
	int _w;
	int _h;
	
	void setup_vertexes();
	
};

#endif /* HexGrid_hpp */
