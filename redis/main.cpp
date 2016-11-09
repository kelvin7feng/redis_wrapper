//
//  main.cpp
//  redis
//
//  Created by 冯文斌 on 16/10/31.
//  Copyright © 2016年 kelvin. All rights reserved.
//

#include <iostream>
#include <string>

#include "redis_test.hpp"

int main(int argc, char **argv)
{
    TestRedis test_redis;
    int failures = test_redis.RunTests();
    std::cout << "failures: " << failures <<std::endl;
    
    return 0;
}