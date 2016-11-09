//
//  redis_buffer.cpp
//  redis
//
//  Created by 冯文斌 on 16/11/9.
//  Copyright © 2016年 kelvin. All rights reserved.
//

#include "redis_buffer.hpp"

RedisBuffer::RedisBuffer(size_t buffer_size, void *buffer_data) : m_buffer_size(buffer_size), m_buffer_data(buffer_data)
{
    
}

RedisBuffer::~RedisBuffer(){
    
}

size_t RedisBuffer::GetSize(){
    return m_buffer_size;
}

const void* RedisBuffer::GetData(){
    return m_buffer_data;
}