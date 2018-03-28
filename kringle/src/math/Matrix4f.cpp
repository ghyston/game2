#include "Matrix4f.h"

using namespace kringle;

void Matrix4f::Identity()
{
    val[0] = val[5] = val[10] = val[15] = 1.0;
    val[1] = val[2] = val[3] = val[4] = 0.0;
    val[6] = val[7] = val[8] = val[9] = 0.0;
    val[11] = val[12] = val[13] = val[14] = 0.0;
}
 
void Matrix4f::Translate(float x, float y, float z)
{
    Identity();
     
    // Translate slots.
    val[12] = x;
    val[13] = y;
    val[14] = z;   
}
 
void Matrix4f::Scale(float sx, float sy, float sz)
{
    Identity();
     
    // Scale slots.
    val[0] = sx;
    val[5] = sy;
    val[10] = sz;
}
 
void Matrix4f::RotateX(float degrees)
{
    float radians = degreesToRadians(degrees);
     
    Identity();
     
    // Rotate X formula.
    val[5] = cosf(radians);
    val[6] = -sinf(radians);
    val[9] = -val[6];
    val[10] = val[5];
}
 
void Matrix4f::RotateY(float degrees)
{
    float radians = degreesToRadians(degrees);     
    Identity();
     
    // Rotate Y formula.
    val[0] = cosf(radians);
    val[2] = sinf(radians);
    val[8] = -val[2];
    val[10] = val[0];
}
 
void Matrix4f::RotateZ(float degrees)
{
    float radians = degreesToRadians(degrees);     
    Identity();
     
    // Rotate Z formula.
    val[0] = cosf(radians);
    val[1] = sinf(radians);
    val[4] = -val[1];
    val[5] = val[0];
}
