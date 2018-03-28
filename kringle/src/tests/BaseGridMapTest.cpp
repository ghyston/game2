//
//  BaseGridMap.cpp
//  kringle
//
//  Created by Ilja Stepanow on 14/03/2017.
//  Copyright © 2017 Ilja Stepanow. All rights reserved.
//

#include "BaseGridMapTest.h"

using namespace kringle;

bool BaseGridTest::init ()
{
    _testMap = BaseGridMap<DumpCell>::create(10, 10, 0.5);
    return true;
}

void BaseGridTest::deinit()
{
    delete _testMap;
}

void BaseGridTest::runTests()
{
    calcIndexInMiddle();
    calcIndexLeftEdge();
    calcIndexRightEdge();
}

void BaseGridTest::calcIndexInMiddle()
{
    Vec2f coords = _testMap->getCoordsByIndex(0, 0);
    LOG_TEST_RESULT(coords.x = 0.0f && coords.y == 0.0f)
}

void BaseGridTest::calcIndexLeftEdge()
{
    Vec2f coords = _testMap->getCoordsByIndex(-6, 1);
    LOG_TEST_RESULT(coords.x = -3.0f && coords.y == 0.5)
}

void BaseGridTest::calcIndexRightEdge()
{
    Vec2f coords = _testMap->getCoordsByIndex(6, -1);
    LOG_TEST_RESULT(coords.x = 3.0f && coords.y == -0.5)
}

