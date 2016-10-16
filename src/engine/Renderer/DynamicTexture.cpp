//
//  DynamicTexture.cpp
//  Game2
//
//  Created by Stepanov Ilia on 16/10/2016.
//  Copyright © 2016 Stepanov Ilia. All rights reserved.
//

#include "DynamicTexture.h"
#include <cstddef>
#include <cstdlib>
#include "TextureHelper.h"

DynamicTexture::DynamicTexture(uint width, uint height)
{
	_width = width;
	_height = height;
	size_t ucSize = sizeof(unsigned char);
	_data = (unsigned char *)malloc( _width * _height * 4 * ucSize);
	_tex = TextureHelper::createTexture(_width, _height, _data);
}

DynamicTexture::~DynamicTexture()
{
	free(_data);
}

void DynamicTexture::setData(std::function<Color4b(Vec2i)> func)
{
	for (size_t x = 0; x < _width; ++x)
	{
		for (size_t y = 0; y < _height; ++y)
		{
			Color4b clr = func(Vec2i((int)x, (int)y));
			updatePixel(Vec2i((int)x, (int)y), clr);
		}
	}
	TextureHelper::updateTexture(_tex, _width, _height, _data);
}

void DynamicTexture::setPixel(Vec2i coords, Color4b clr)
{
	updatePixel(coords, clr);
	TextureHelper::updateTexture(_tex, _width, _height, _data);
}

void DynamicTexture::updatePixel(Vec2i coords, Color4b clr)
{
	size_t startP = (coords.y * _width + coords.x) * 4;
	_data[startP + 0] = clr.r;
	_data[startP + 1] = clr.g;
	_data[startP + 2] = clr.b;
	_data[startP + 3] = clr.a;
}

