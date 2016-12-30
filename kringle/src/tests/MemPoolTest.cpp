//
//  MemPoolTest.cpp
//  Game2
//
//  Created by Ilja Stepanow on 26/12/2016.
//  Copyright © 2016 Stepanov Ilia. All rights reserved.
//

#include "MemPoolTest.h"

using namespace kringle;

int Foo::refCounter = 0;

void MemPoolTest::runTests()
{
    LOG_TEST_START
    addObj();
    delObj();
    addManyObj();
    clear();
}

void MemPoolTest::addObj()
{
    _tmp = MemPool<Foo>::newObj();
    LOG_TEST_RESULT(Foo::getCounter() == 1)
}


void MemPoolTest::delObj()
{
    MemPool<Foo>::delObj(_tmp);
    LOG_TEST_RESULT(Foo::getCounter() == 0)
}

void addManyObj()
{
    int tmpCount = 150;
    for(int i = 0; i < tmpCount; i++)
        MemPool<Foo>::newObj();
    
    LOG_TEST_RESULT(Foo::getCounter() == tmpCount)
}

void MemPoolTest::clear()
{
    MemPool<Foo>::clear();
    LOG_TEST_RESULT(Foo::getCounter() == 0)
}
