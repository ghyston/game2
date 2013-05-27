#ifndef __VECTOR_2F_H__
#define __VECTOR_2F_H__

struct Vec2f
{
	Vec2f()
	{
		this->x = 0.0f;
		this->y = 0.0f;
	}

	Vec2f(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
	
	Vec2f(const Vec2f& vec)
	{
		this->x = vec.x;
		this->y = vec.y;
	}
	
	float x;
	float y;
	
	Vec2f& operator+ (Vec2f& vec)
	{
		this->x += vec.x;
		this->y += vec.y;
		return *this;
	}
	
	Vec2f& operator- (Vec2f& vec)
	{
		this->x -= vec.x;
		this->y -= vec.y;
		return *this;
	}
};

#endif //__VECTOR_2F_H__