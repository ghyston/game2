#ifndef __MATRIX_4F_H__
#define __MATRIX_4F_H__

#include <math.h>
#include "MathMacros.h"

namespace kringle {

    class Matrix4f
    {
    private:
        
        float val[16];
        
    public:
        void Identity();
     
        void Translate(float x, float y, float z);
     
        void Scale(float sx, float sy, float sz);
     
        //@todo: possible way to optimisation: rotate not to degrees,
        // but transfer cos/sin instead to function.
        void RotateX(float degrees);
     
        void RotateY(float degrees);
     
        void RotateZ(float degrees);
        
        float& operator [] (int index)
        {
            //@todo: add assert index range here!
            return val[index];
        }
        
        float* GetValue()
        {
            return &val[0];
        }
    };
}

#endif //__MATRIX_4F_H__
