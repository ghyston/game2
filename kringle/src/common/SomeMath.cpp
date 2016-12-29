//
//  SomeMath.cpp
//  Game2
//
//  Created by Stepanov Ilia on 08/06/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#include "SomeMath.h"

float areaTriangle(Vec2f a, Vec2f b, Vec2f c)
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool SegmentsIntersected(Vec2f a1, Vec2f a2, Vec2f b1, Vec2f b2)
{
	Vec2f aBB_min = Vec2f(fmin(a1.x, a2.x), fmin(a1.y, a2.y));
	Vec2f aBB_max = Vec2f(fmax(a1.x, a2.x), fmax(a1.y, a2.y));
	Vec2f bBB_min = Vec2f(fmin(b1.x, b2.x), fmin(b1.y, b2.y));
	Vec2f bBB_max = Vec2f(fmax(b1.x, b2.x), fmax(b1.y, b2.y));
	 
	// Check intersection by bounding boxes.
	if(aBB_min.x > bBB_max.x || aBB_max.x < bBB_min.x ||
	aBB_min.y > bBB_max.y || aBB_max.y < bBB_min.y)
	return false;
	 
	 // Calc area sign.
	return (areaTriangle(a1, a2, b1) * areaTriangle(a1, a2, b2) <= 0)
		&& (areaTriangle(b1, b2, a1) * areaTriangle(b1, b2, a2) <= 0);
}