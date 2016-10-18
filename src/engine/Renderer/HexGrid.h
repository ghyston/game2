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
	
	HexGrid() : BaseRenderable()
	{
		vertexes_count = 6;
		draw_type = GL_LINE_LOOP;
	}
	
	float _side;
	
	void setup_vertexes();
	
};

#endif /* HexGrid_hpp */
