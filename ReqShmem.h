#pragma once

#include "globals.h"
#include "Request.h"

struct ReqShmem{
    int32_t next_write_index = 0;
    Request m_queue[REQ_QUEUE_SIZE];
};