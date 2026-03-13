#pragma once

#include "globals.h"
#include "Request.h"
#include <atomic>

struct ReqShmem{
    std::atomic<int32_t> next_write_index = 0;
    int32_t next_write_page = 0;
    MyOrderId next_order_id = 0;
    Request m_queue[REQ_QUEUE_SIZE];
};