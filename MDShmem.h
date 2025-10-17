#pragma once

#include "globals.h"
#include "MDupdate.h"
#include <atomic>

struct MDShmem{
    std::atomic<int32_t> next_write_index = 0;
    int32_t next_write_page = 0;
    MDupdate m_queue[MD_QUEUE_SIZE];
};