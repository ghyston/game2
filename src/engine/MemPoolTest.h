//
//  MemPoolTest.hpp
//  Game2
//
//  Created by Ilja Stepanow on 26/12/2016.
//  Copyright © 2016 Stepanov Ilia. All rights reserved.
//

#ifndef MemPoolTest_hpp
#define MemPoolTest_hpp

#include "MemPool.h"

namespace kringle {
    
    class Foo
    {
    public:
        
        static int getCounter() { return refCounter; }
        
        Foo()
        {
            Foo::refCounter++;
        }
        
        Foo(const Foo&)
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

    //@todo: merge with other existing tests and make them automatic!
    class MemPoolTest
    {
    public:
    
        static void run();
    
    };
    
}

#endif /* MemPoolTest_hpp */
