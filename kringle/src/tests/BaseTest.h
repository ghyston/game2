//
//  BaseTest.h
//  HeroManager
//
//  Created by Stepanov Ilya on 23/06/16.
//
//

#ifndef BaseTest_h
#define BaseTest_h

#include "GlobalMacros.h"

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define LOG_TEST_RESULT(_RESULT_) \
KRILOG("%-40s %s", __func__, (_RESULT_) ? "SUCCESS" : "FAILED");

#define LOG_TEST_START \
KRILOG("Start Test: %s", __FILENAME__);

class BaseTest
{
public:
    
    virtual ~BaseTest() {}
    
    virtual bool init() = 0;
    virtual void deinit() = 0;
    
    virtual void runTests() = 0;    
};

#endif /* BaseTest_h */
