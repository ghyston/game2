//
//  Vector2f.cpp
//  Game2
//
//  Created by Stepanov Ilia on 08/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#include "Vector2f.h"

Vec2f operator+ (const Vec2f& vec_1, const Vec2f& vec_2)
{
	return Vec2f (vec_1.x + vec_2.x, vec_1.y + vec_2.y);
}

Vec2f operator- (const Vec2f& vec_1, const Vec2f& vec_2)
{
	return Vec2f(vec_1.x - vec_2.x, vec_1.y - vec_2.y);;
}

Vec2f operator* (const Vec2f& vec, float coeff)
{
	return Vec2f(vec.x * coeff, vec.y * coeff);
}

Vec2f operator* (float coeff, const Vec2f& vec)
{
	return Vec2f(vec.x * coeff, vec.y * coeff);
}

float quad_distance(const Vec2f& point_1, const Vec2f& point_2)
{
	Vec2f s = point_2 - point_1;
	return s.x * s.x + s.y * s.y;
}

float distance(const Vec2f& point_1, const Vec2f& point_2)
{
	return sqrtf(quad_distance(point_1, point_2));
}