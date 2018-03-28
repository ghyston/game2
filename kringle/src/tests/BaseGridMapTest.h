//
//  BaseGridMap.hpp
//  kringle
//
//  Created by Ilja Stepanow on 14/03/2017.
//  Copyright © 2017 Ilja Stepanow. All rights reserved.
//

#ifndef BaseGridMap_hpp
#define BaseGridMap_hpp

#include "BaseTest.h"
#include "BaseGridMap.h"

namespace kringle {
    
    class BaseGridTest : public BaseTest
    {
    public:
        
        bool init ();
        void deinit();
        
        void runTests();
        
    private:
        
        void calcIndexInMiddle();
        void calcIndexLeftEdge();
        void calcIndexRightEdge();
        
        struct DumpCell {
            
        };
        
        BaseGridMap<DumpCell>* _testMap;
    };
}

#endif /* BaseGridMap_hpp */
