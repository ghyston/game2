/* 
 * File:   Color3f.h
 * Author: Hyston
 *
 * Created on 12 Май 2013 г., 9:38
 */

#ifndef __COLOR3F_H__
#define	__COLOR3F_H__

struct Color3f
{
	float r;
	float g;
	float b;
	
	Color3f(float red, float green, float blue) :
		r(red), g(green), b(blue) 
	{}
	
	Color3f(float gray) :
	r(gray), g(gray), b(gray)
	{}

	
	Color3f() : r(0.0f), g(0.0f), b(0.0f)
	{}
};



#endif	/* COLOR3F_H */

