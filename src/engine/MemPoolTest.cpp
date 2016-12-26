//
//  MemPoolTest.cpp
//  Game2
//
//  Created by Ilja Stepanow on 26/12/2016.
//  Copyright © 2016 Stepanov Ilia. All rights reserved.
//

#include "MemPoolTest.hpp"

using namespace kringle;

int Foo::refCounter = 0;

void MemPoolTest::run()
{    
    auto pFoo = MemPool<Foo>::newObj();
    if(Foo::getCounter() != 1)
        printf("Foo::getCounter is %i, should be 1\n", Foo::getCounter());
    MemPool<Foo>::delObj(pFoo);
    if(Foo::getCounter() != 0)
        printf("Foo::getCounter is %i, should be 0\n", Foo::getCounter());
    
    int tmpCount = 150;
    for(int i = 0; i < tmpCount; i++)
        MemPool<Foo>::newObj();
    
    if(Foo::getCounter() != tmpCount)
        printf("Foo::getCounter is %i, should be %i\n", Foo::getCounter(), tmpCount);
    
    MemPool<Foo>::clear();
    if(Foo::getCounter() != 0)
        printf("Foo::getCounter is %i, should be 0\n", Foo::getCounter());
    
}
