//
//  main.cpp
//  kringle_tests
//
//  Created by Ilja Stepanow on 13/03/2017.
//  Copyright © 2017 Ilja Stepanow. All rights reserved.
//

#include <iostream>
#include <stack>
#include "MathTest.h"
#include "MemPoolTest.h"

using namespace kringle;

int main(int argc, const char * argv[])
{
    std::stack<BaseTest *> tests;
    
    //@note: add new tests here
    tests.push(new MemPoolTest());
    tests.push(new MathTest());
    
    while (!tests.empty()) {
        BaseTest * test = tests.top();
        test->runTests();
        delete test;
        tests.pop();
    }
    
    return 0;
}
