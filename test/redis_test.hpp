//
//  redis_test.hpp
//  redis
//
//  Created by 冯文斌 on 16/11/2.
//  Copyright © 2016年 kelvin. All rights reserved.
//

#ifndef redis_test_hpp
#define redis_test_hpp

#include <stdio.h>
#include "redis_client.hpp"

using namespace RedisWrap;

class TestRedis;
typedef int (TestRedis::*TestRedisMemberPointer)();

class TestRedis
{
public:
    TestRedis();
    int RunTests();
    
private:
    int Test1();
    int Test2();
    int Test3();
    int Test4();
    int Test5();
    int Test6();
    int Test7();
    int Test8();
    
    int RunTest(TestRedisMemberPointer test);
};

#endif /* redis_test_hpp */
