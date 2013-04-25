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
	
	float x;
	float y;
	
	/*Vector2f& operator + (Vector2f&)
	{
		
	}*/
};

#endif //__VECTOR_2F_H__