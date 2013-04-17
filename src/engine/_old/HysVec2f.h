#ifndef __HYSVEC2f_h__
#define __HYSVEC2f_h__

#include <cmath>


/**
* 2D vector pure class. 
* TODO: implement +-, at least
*/
struct HysVec2f
{
	float x;
	float y;

	HysVec2f(float _x = 0.0f, float _y = 0.0f) :
		x(_x), y(_y)
	{}

	//TODO: check, is it right!!
	HysVec2f& operator += (HysVec2f vector)
	{
		this->x += vector.x;
		this->y += vector.y;
		return (*this);
	}

	float getLength() const;

	void setLength(float new_value);
};

#endif //__HYSVEC2f_h__

