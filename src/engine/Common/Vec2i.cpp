//
//  Vec2i.cpp
//  Game2
//
//  Created by Stepanov Ilia on 20/03/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#include "Vec2i.h"

Vec2i operator+ (const Vec2i& vec_1, const Vec2i& vec_2)
{
	return Vec2i (vec_1.x + vec_2.x, vec_1.y + vec_2.y);
}

Vec2i operator- (const Vec2i& vec_1, const Vec2i& vec_2)
{
	return Vec2i(vec_1.x - vec_2.x, vec_1.y - vec_2.y);;
}

Vec2i operator* (const Vec2i& vec, int coeff)
{
	return Vec2i(vec.x * coeff, vec.y * coeff);
}

Vec2i operator* (int coeff, const Vec2i& vec)
{
	return Vec2i(vec.x * coeff, vec.y * coeff);
}