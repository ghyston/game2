//
//  BaseGridMap.h
//  Game2
//
//  Created by Stepanov Ilia on 17/05/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__BaseGridMap__
#define __Game2__BaseGridMap__

#include <map>
#include "../Common/Vector2f.h"
#include "../Common/Vec2i.h"

template <class T>
class BaseGridMap
{
public:
	BaseGridMap() {;}
	
	//@note: it's half width and half height
	virtual void InitMap(int width_, int height_, float cell_size_);
	
	virtual int getHeight() const { return height; }
	virtual int getWidth() const { return width; }
	virtual float getCellSize() const { return cell_size; }
	
	virtual Vec2i getIndexesByCoords(Vec2f coords);
	virtual Vec2i getIndexesByCoords(float x, float y);
	
	virtual Vec2f getCoordsByIndex(Vec2i coords);
	virtual Vec2f getCoordsByIndex(int x, int y);
	
protected:
	
	int width;
	int height;
	float cell_size;
	
	std::map<int, std::map<int, T> > cells;
	
};

template <class T>
void BaseGridMap<T>::InitMap(int width_, int height_, float cell_size_)
{
	height = height_;
	width = width_;
	cell_size = cell_size_;
}

template <class T>
Vec2i BaseGridMap<T>::getIndexesByCoords(Vec2f coords)
{
	return getIndexesByCoords(coords.x, coords.y);
}

template <class T>
Vec2i BaseGridMap<T>::getIndexesByCoords(float x, float y)
{
	int cell_x = x / cell_size;
	if(x < 0.0f)
		cell_x--;
	
	int cell_y = y / cell_size;
	if(y < 0.0f)
		cell_y--;
	
	if(cell_x >= width || cell_x <= -width ||
	   cell_y >= height || cell_y <= -height)
	{
		throw 0;
	}
	return Vec2i(cell_x, cell_y);
}

template <class T>
Vec2f BaseGridMap<T>::getCoordsByIndex(Vec2i coords)
{
	return getCoordsByIndex(coords.x, coords.y);
}

// Return coords of cell center
template <class T>
Vec2f BaseGridMap<T>::getCoordsByIndex(int x, int y)
{
	Vec2f result(x * cell_size, y * cell_size);
	return result;
}



#endif /* defined(__Game2__BaseGridMap__) */
