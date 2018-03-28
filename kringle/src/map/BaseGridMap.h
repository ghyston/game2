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
#include "../common/Vector2f.h"
#include "../common/Vec2i.h"

using namespace std;

template <class T>
class BaseGridMap
{
public:
    
    virtual ~BaseGridMap() { delete [] cells; }
	
	//@note: it's half width and half height
    
    static BaseGridMap<T> * create(int width, int height, float cellSize)
    {
        auto map = new BaseGridMap<T>();
        map->init(width, height, cellSize);
        return map;
    }
	
	virtual int getHeight() const { return height; }
	virtual int getWidth() const { return width; }
	virtual float getCellSize() const { return cell_size; }
	
	virtual Vec2i getIndexesByCoords(Vec2f coords);
	virtual Vec2i getIndexesByCoords(float x, float y);
	
	virtual Vec2f getCoordsByIndex(Vec2i coords);
	virtual Vec2f getCoordsByIndex(int x, int y);
    
    virtual void implementForEachCell(function<void(T* cell)> lambda);
	
protected:
    
    BaseGridMap() {;}
    virtual void init(int width_, int height_, float cell_size_);
	
	int width;
	int height;
	float cell_size;
    
    T * const getCell(int x, int y);
    
private:
	
	T* cells;
    size_t cellByteSize;
	
};

template <class T>
void BaseGridMap<T>::init(int width_, int height_, float cell_size_)
{
	height = height_;
	width = width_;
	cell_size = cell_size_;
    cells = new T[height * width];
    cellByteSize = sizeof(T);
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
	
	/*if(cell_x >= width || cell_x <= -width ||
	   cell_y >= height || cell_y <= -height)
	{
		throw 0;
	}*/
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

template <class T>
T * const BaseGridMap<T>::getCell(int x, int y)
{
    return cells + (y * height + x) * cellByteSize;
}

template <class T>
void BaseGridMap<T>::implementForEachCell(function<void(T*const cell)> lambda)
{
    for(int i = 0; i < width * height; i++)
        lambda(cells+i*cellByteSize);
}



#endif /* defined(__Game2__BaseGridMap__) */
