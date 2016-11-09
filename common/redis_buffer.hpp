//
//  redis_buffer.hpp
//  redis
//
//  Created by 冯文斌 on 16/11/9.
//  Copyright © 2016年 kelvin. All rights reserved.
//

#ifndef redis_buffer_hpp
#define redis_buffer_hpp

#include <stdio.h>

class RedisBuffer
{
public:
    RedisBuffer(size_t buffer_size, void* buffer_data);
    ~RedisBuffer();
    
    const void* GetData();
    size_t GetSize();
    
private:
    //不允许使用默认构造函数
    RedisBuffer();
    
    size_t          m_buffer_size;
    void*           m_buffer_data;

};

#endif /* redis_buffer_hpp */
