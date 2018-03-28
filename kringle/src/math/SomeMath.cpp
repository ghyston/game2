//
//  SomeMath.cpp
//  Game2
//
//  Created by Stepanov Ilia on 08/06/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#include "SomeMath.h"

using namespace kringle;

float AreaTriangle(Vec2f a, Vec2f b, Vec2f c)
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
	return (AreaTriangle(a1, a2, b1) * AreaTriangle(a1, a2, b2) <= 0)
		&& (AreaTriangle(b1, b2, a1) * AreaTriangle(b1, b2, a2) <= 0);
}

void MatrixMultiply(Matrix4f& m1, Matrix4f& m2, Matrix4f& result)
{
    // Fisrt Column
    result[0] = m1[0]*m2[0] + m1[4]*m2[1] + m1[8]*m2[2] + m1[12]*m2[3];
    result[1] = m1[1]*m2[0] + m1[5]*m2[1] + m1[9]*m2[2] + m1[13]*m2[3];
    result[2] = m1[2]*m2[0] + m1[6]*m2[1] + m1[10]*m2[2] + m1[14]*m2[3];
    result[3] = m1[3]*m2[0] + m1[7]*m2[1] + m1[11]*m2[2] + m1[15]*m2[3];
    
    // Second Column
    result[4] = m1[0]*m2[4] + m1[4]*m2[5] + m1[8]*m2[6] + m1[12]*m2[7];
    result[5] = m1[1]*m2[4] + m1[5]*m2[5] + m1[9]*m2[6] + m1[13]*m2[7];
    result[6] = m1[2]*m2[4] + m1[6]*m2[5] + m1[10]*m2[6] + m1[14]*m2[7];
    result[7] = m1[3]*m2[4] + m1[7]*m2[5] + m1[11]*m2[6] + m1[15]*m2[7];
    
    // Third Column
    result[8] = m1[0]*m2[8] + m1[4]*m2[9] + m1[8]*m2[10] + m1[12]*m2[11];
    result[9] = m1[1]*m2[8] + m1[5]*m2[9] + m1[9]*m2[10] + m1[13]*m2[11];
    result[10] = m1[2]*m2[8] + m1[6]*m2[9] + m1[10]*m2[10] + m1[14]*m2[11];
    result[11] = m1[3]*m2[8] + m1[7]*m2[9] + m1[11]*m2[10] + m1[15]*m2[11];
    
    // Fourth Column
    result[12] = m1[0]*m2[12] + m1[4]*m2[13] + m1[8]*m2[14] + m1[12]*m2[15];
    result[13] = m1[1]*m2[12] + m1[5]*m2[13] + m1[9]*m2[14] + m1[13]*m2[15];
    result[14] = m1[2]*m2[12] + m1[6]*m2[13] + m1[10]*m2[14] + m1[14]*m2[15];
    result[15] = m1[3]*m2[12] + m1[7]*m2[13] + m1[11]*m2[14] + m1[15]*m2[15];
}
