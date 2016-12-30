//
//  LineRenderable.h
//  Game2
//
//  Created by Stepanov Ilia on 10/15/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef Game2_LineRenderable_h
#define Game2_LineRenderable_h

#include "BaseRenderable.h"

class LineRenderable : public BaseRenderable
{
public:
    
    LineRenderable() : BaseRenderable()
    {
        vertexes_count = 2;
        draw_type = GL_LINES;
    }
    
    Vec2f start;
    Vec2f end;
    
    void setup_vertexes();
    
    virtual void Draw();
    
};

#endif
