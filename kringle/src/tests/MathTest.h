//
//  MathTest.hpp
//  
//
//  Created by Ilja Stepanow on 27/12/2016.
//
//

#ifndef MathTest_hpp
#define MathTest_hpp

#include "tests/BaseTest.h"

namespace kringle {
    
    class MathTest : public BaseTest
    {
    public:
        
        bool init () { return true; }
        
        void runTests();
        
    private:
        
        void intersected();
        void notIntersected();
        void perpendicularIntersected();
        void onSameLine();
        void intersectedOnOnePoint();
    };
}

#endif /* MathTest_hpp */
