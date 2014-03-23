#ifndef __VECTOR_2I_H__
#define __VECTOR_2I_H__

#include <math.h>

struct Vec2i
{
	int x;
	int y;
	
	Vec2i() : x(0), y(0)
	{;}
	
	Vec2i(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	
	Vec2i(const Vec2i& vec)
	{
		this->x = vec.x;
		this->y = vec.y;
	}
	
	Vec2i(int size)
	{
		this->x = size;
		this->y = size;
	}
	
	Vec2i& operator+= (const Vec2i& vec)
	{
		this->x += vec.x;
		this->y += vec.y;
		return *this;
	}
	
	Vec2i& operator-= (const Vec2i& vec)
	{
		this->x -= vec.x;
		this->y -= vec.y;
		return *this;
	}
	
	// @todo: not optimaized!
//	void normalize()
//	{
//		float length = this->length();
//		x /= length;
//		y /= length;
//	}
	
	float length()
	{
		return sqrtf(x * x + y * y);
	}
	
//	void lenth(float length)
//	{
//		normalize();
//		x *= length;
//		y *= length;
//	}
};

Vec2i operator+ (const Vec2i& vec_1, const Vec2i& vec_2);
Vec2i operator- (const Vec2i& vec_1, const Vec2i& vec_2);
Vec2i operator* (const Vec2i& vec, int coeff);
Vec2i operator* (int coeff, const Vec2i& vec);
bool operator==(const Vec2i& left, const Vec2i& right);

#endif //__VECTOR_2I_H__