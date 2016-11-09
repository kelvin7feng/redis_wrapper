//
//  redis_test.cpp
//  redis
//
//  Created by 冯文斌 on 16/11/2.
//  Copyright © 2016年 kelvin. All rights reserved.
//

#include "redis_test.hpp"
#include "redis_client.hpp"

TestRedis::TestRedis()
{
    
}
    
int TestRedis::Test1()
{
    int failed = 0;
    
    RedisClient rc("127.0.0.1",6379);
    int result = rc.Connect();
    if(result == REDIS_OK)
    {
        
    } else {
        failed = 1;
    }
    
    return failed;
}

int TestRedis::Test2()
{
    RedisClient rc("127.0.0.1",6379);
    rc.Connect();
    
    string key = "name";
    string value = "hello";
    int result = rc.Set(key, value);
    if(result == REDIS_OK){
        return 0;
    } else {
        return 1;
    }
}

int TestRedis::Test3()
{
    RedisClient rc("127.0.0.1",6379);
    rc.Connect();
    
    int result = rc.Set(9999, "set");
    if(result == REDIS_OK){
        return 0;
    } else {
        return 1;
    }
}

int TestRedis::Test4()
{
    RedisClient rc("127.0.0.1",6379);
    rc.Connect();
    
    int result = rc.HSet("student", "name", "kelvin");
    if(result == REDIS_OK){
        return 0;
    } else {
        return 1;
    }
}

int TestRedis::Test5()
{
    RedisClient rc("127.0.0.1",6379);
    rc.Connect();

    int result = rc.HSet(11, 91, "kelvin");
    if(result == REDIS_OK){
        return 0;
    } else {
        return 1;
    }
}

int TestRedis::Test6()
{
    RedisClient rc("127.0.0.1",6379);
    rc.Connect();
    
    string key = "name";
    redisReply reply;
    int result = rc.Get(key, reply);
    std::string str = rc.GetReplyContent(reply);
    std::cout << str << std::endl;
    if(result == REDIS_OK){
        return 0;
    } else {
        return 1;
    }
}


int TestRedis::Test7()
{
    RedisClient rc("127.0.0.1",6379);
    rc.Connect();
    
    int64_t key = 9999;
    redisReply reply;
    int result = rc.Get(key, reply);
    std::string str = rc.GetReplyContent(reply);
    std::cout << str << std::endl;
    if(result == REDIS_OK){
        return 0;
    } else {
        return 1;
    }
}

int TestRedis::Test8()
{
    RedisClient rc("127.0.0.1",6379);
    rc.Connect();
    
    redisReply reply;
    int result = rc.HGet("student", "name", reply);
    std::string str = rc.GetReplyContent(reply);
    std::cout << str << std::endl;
    if(result == REDIS_OK){
        return 0;
    } else {
        return 1;
    }
}

int TestRedis::RunTest(TestRedisMemberPointer test)
{
    int failed = (this->*test)();
    return failed;
}

int TestRedis::RunTests()
{
    int failures = 0;
    
    failures += RunTest(&TestRedis::Test1);
    failures += RunTest(&TestRedis::Test2);
    failures += RunTest(&TestRedis::Test3);
    failures += RunTest(&TestRedis::Test4);
    failures += RunTest(&TestRedis::Test5);
    failures += RunTest(&TestRedis::Test6);
    failures += RunTest(&TestRedis::Test7);
    failures += RunTest(&TestRedis::Test8);
    
    return failures;
}
