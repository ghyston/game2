//
//  MemPoolTest.hpp
//  Game2
//
//  Created by Ilja Stepanow on 26/12/2016.
//  Copyright © 2016 Stepanov Ilia. All rights reserved.
//

#ifndef MemPoolTest_hpp
#define MemPoolTest_hpp

#include "common/GlobalMacros.h"
#include "memory/MemPool.h"
#include "tests/BaseTest.h"


namespace kringle {
    
    class Foo
    {
    public:
        
        static int getCounter() { return refCounter; }
        
        explicit Foo()
        {
            Foo::refCounter++;
        }
        
        explicit Foo(const Foo&)
        {
            Foo::refCounter++;
        }
        
        ~Foo()
        {
            Foo::refCounter--;
        }
        
    private:
        
        static int refCounter;
        
        int oneInt;
        int twoInt;
        
    };

    class MemPoolTest : public BaseTest
    {
    public:
        
        bool init () { return true; }
        void deinit() {}
    
        void runTests();
        
    private:
        
        void addObj();
        void delObj();
        void addManyObj();
        void clear();
        
        Foo * _tmp = NULL;
    
    };
    
}

#endif /* MemPoolTest_hpp */
