//
//  Color3b.h
//  Game2
//
//  Created by Stepanov Ilia on 16/10/2016.
//  Copyright © 2016 Stepanov Ilia. All rights reserved.
//

#ifndef Color3b_h
#define Color3b_h

#include "GlobalMacros.h"

struct Color4b
{
	uchar r;
	uchar g;
	uchar b;
	uchar a;
	
	Color4b(uchar red, uchar green, uchar blue, uchar alpha) :
	r(red), g(green), b(blue), a(alpha)
	{}
	
	Color4b(uchar gray) :
	r(gray), g(gray), b(gray), a(255)
	{}
	
	
	Color4b() : r(0), g(0), b(0), a(0)
	{}
};

#endif /* Color3b_h */
