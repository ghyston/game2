#ifndef __VECTOR_2F_H__
#define __VECTOR_2F_H__

#include <math.h>

namespace kringle
{
    struct Vec2f
    {
        float x;
        float y;
        
        Vec2f() : x(0.0f), y(0.0f)
        {;}

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
        
        Vec2f(float size)
        {
            this->x = size;
            this->y = size;
        }
        
        Vec2f& operator+= (const Vec2f& vec)
        {
            this->x += vec.x;
            this->y += vec.y;
            return *this;
        }
        
        Vec2f& operator-= (const Vec2f& vec)
        {
            this->x -= vec.x;
            this->y -= vec.y;
            return *this;
        }
        
        void Normalize()
        {
            float length = this->Length();
            x /= length;
            y /= length;
        }
        
        float Length()
        {
            return sqrtf(x * x + y * y);
        }
        
        void Length(float length)
        {
            Normalize();
            x *= length;
            y *= length;
        }
    };

    Vec2f operator+ (const Vec2f& vec_1, const Vec2f& vec_2);
    Vec2f operator- (const Vec2f& vec_1, const Vec2f& vec_2);
    Vec2f operator* (const Vec2f& vec, float coeff);
    Vec2f operator* (float coeff, const Vec2f& vec);

    float QuadDistance(const Vec2f& point_1, const Vec2f& point_2);
    float Distance(const Vec2f& point_1, const Vec2f& point_2);
    
}

#endif //__VECTOR_2F_H__
