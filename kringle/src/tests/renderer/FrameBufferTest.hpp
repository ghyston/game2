//
//  FrameBufferTest.hpp
//  Game2
//
//  Created by Stepanov Ilia on 15/09/16.
//  Copyright © 2016 Stepanov Ilia. All rights reserved.
//

#ifndef FrameBufferTest_hpp
#define FrameBufferTest_hpp

#include "GlInclude.h"
#include "TextureRectRenderable.h"
#include "Vec2i.h"

class FrameBufferTest
{
public:
	
	void init();
	void preRender();
	void postRender();
	
private:
	
	GLuint _framebuffer = 0;
	GLuint _depthbuffer = 0;
	GLuint _renderedTexture = 0;
	
	TextureRectRenderable texturedRect;
	
};

#endif /* FrameBufferTest_hpp */
