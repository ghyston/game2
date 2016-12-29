#include "Matrix4f.h"

void matrixMultiply(Matrix4f& m1, Matrix4f& m2, Matrix4f& result)
{
    // Fisrt Column
    result[0] = m1[0]*m2[0] + m1[4]*m2[1] + m1[8]*m2[2] + m1[12]*m2[3];
    result[1] = m1[1]*m2[0] + m1[5]*m2[1] + m1[9]*m2[2] + m1[13]*m2[3];
    result[2] = m1[2]*m2[0] + m1[6]*m2[1] + m1[10]*m2[2] + m1[14]*m2[3];
    result[3] = m1[3]*m2[0] + m1[7]*m2[1] + m1[11]*m2[2] + m1[15]*m2[3];
     
    // Second Column
    result[4] = m1[0]*m2[4] + m1[4]*m2[5] + m1[8]*m2[6] + m1[12]*m2[7];
    result[5] = m1[1]*m2[4] + m1[5]*m2[5] + m1[9]*m2[6] + m1[13]*m2[7];
    result[6] = m1[2]*m2[4] + m1[6]*m2[5] + m1[10]*m2[6] + m1[14]*m2[7];
    result[7] = m1[3]*m2[4] + m1[7]*m2[5] + m1[11]*m2[6] + m1[15]*m2[7];
     
    // Third Column
    result[8] = m1[0]*m2[8] + m1[4]*m2[9] + m1[8]*m2[10] + m1[12]*m2[11];
    result[9] = m1[1]*m2[8] + m1[5]*m2[9] + m1[9]*m2[10] + m1[13]*m2[11];
    result[10] = m1[2]*m2[8] + m1[6]*m2[9] + m1[10]*m2[10] + m1[14]*m2[11];
    result[11] = m1[3]*m2[8] + m1[7]*m2[9] + m1[11]*m2[10] + m1[15]*m2[11];
     
    // Fourth Column
    result[12] = m1[0]*m2[12] + m1[4]*m2[13] + m1[8]*m2[14] + m1[12]*m2[15];
    result[13] = m1[1]*m2[12] + m1[5]*m2[13] + m1[9]*m2[14] + m1[13]*m2[15];
    result[14] = m1[2]*m2[12] + m1[6]*m2[13] + m1[10]*m2[14] + m1[14]*m2[15];
    result[15] = m1[3]*m2[12] + m1[7]*m2[13] + m1[11]*m2[14] + m1[15]*m2[15];
}

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