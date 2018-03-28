//
//  MathTest.cpp
//  
//
//  Created by Ilja Stepanow on 27/12/2016.
//
//

#include "MathTest.h"

#include "math/Vec2f.h"
#include "SomeMath.h"

using namespace kringle;

void MathTest::runTests()
{
    LOG_TEST_START
    intersected();
    notIntersected();
    perpendicularIntersected();
    onSameLine();
    intersectedOnOnePoint();
}

void MathTest::intersected()
{
    Vec2f a1, a2, b1, b2;
    a1 = Vec2f(-2.0f, -1.5f);
    a2 = Vec2f( 1.5f,  1.0f);
    b1 = Vec2f( 0.0f, -1.5f);
    b2 = Vec2f(-1.5f,  1.0f);
    LOG_TEST_RESULT(SegmentsIntersected(a1, a2, b1, b2));
}

void MathTest::notIntersected()
{
    Vec2f a1, a2, b1, b2;
    a1 = Vec2f(-2.0f, -1.0f);
    a2 = Vec2f(-0.5f,  1.0f);
    b1 = Vec2f(-1.5f,  2.0f);
    b2 = Vec2f( 1.0f,  1.5f);
    LOG_TEST_RESULT(!SegmentsIntersected(a1, a2, b1, b2));
}

void MathTest::perpendicularIntersected()
{
    Vec2f a1, a2, b1, b2;
    a1 = Vec2f(-0.5f, -1.5f);
    a2 = Vec2f(-0.5f,  1.0f);
    b1 = Vec2f(-1.0f, -0.5f);
    b2 = Vec2f( 1.5f, -0.5f);
    LOG_TEST_RESULT(SegmentsIntersected(a1, a2, b1, b2));
}

void MathTest::onSameLine()
{
    Vec2f a1, a2, b1, b2;
    a1 = Vec2f(-1.0f, -1.5f);
    a2 = Vec2f(-0.5f, -0.5f);
    b1 = Vec2f( 0.0f,  0.5f);
    b2 = Vec2f( 0.5f,  1.5f);
    LOG_TEST_RESULT(SegmentsIntersected(a1, a2, b1, b2));
}

void MathTest::intersectedOnOnePoint()
{
    Vec2f a1, a2, b1, b2;
    a1 = Vec2f(-1.0f, -0.5f);
    a2 = Vec2f( 0.5f, -0.5f);
    b1 = Vec2f( 0.0f, -1.5f);
    b2 = Vec2f( 1.0f,  0.5f);
    LOG_TEST_RESULT(SegmentsIntersected(a1, a2, b1, b2));
}
