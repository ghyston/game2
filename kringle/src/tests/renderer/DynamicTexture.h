//
//  DynamicTexture.hpp
//  Game2
//
//  Created by Stepanov Ilia on 16/10/2016.
//  Copyright © 2016 Stepanov Ilia. All rights reserved.
//

#ifndef DynamicTexture_hpp
#define DynamicTexture_hpp

#include "../Common/GlobalMacros.h"
#include "GlInclude.h"
#include <iostream>
#include "Color4b.h"
#include "Vec2i.h"

class DynamicTexture
{
public:
	
	explicit DynamicTexture(uint width, uint height);
	~DynamicTexture();
	
	void setData(std::function<Color4b(Vec2i)> func);
	void setPixel(Vec2i coords, Color4b clr);
	
	GLuint getTextureHandler() { return _tex; }
	
private:
	
	uint _width;
	uint _height;
	GLuint _tex;
	unsigned char * _data;
	
	void updatePixel(Vec2i coords, Color4b clr);
	
};

#endif /* DynamicTexture_hpp */
