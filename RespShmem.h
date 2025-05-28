#pragma once

#include "globals.h"
#include "Response.h"

struct RespShmem{
    int32_t next_write_index = 0;
    Response m_queue[RESP_QUEUE_SIZE];
};