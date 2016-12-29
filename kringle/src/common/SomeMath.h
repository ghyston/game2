//
//  SomeMath.h
//  Game2
//
//  Created by Stepanov Ilia on 08/06/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__SomeMath__
#define __Game2__SomeMath__

#include <math.h>
#include "Vector2f.h"

float areaTriangle(Vec2f a, Vec2f b, Vec2f c);

bool SegmentsIntersected(Vec2f a1, Vec2f a2, Vec2f b1, Vec2f b2);

#endif /* defined(__Game2__SomeMath__) */
