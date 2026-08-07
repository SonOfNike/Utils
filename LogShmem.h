#pragma once

#include "globals.h"
#include "LogItem.h"
#include <atomic>

struct LogSlot{
    std::atomic<int32_t> next_write_index = 0;
    int32_t next_write_page = 0;
    LogItem m_queue[LOG_QUEUE_SIZE];
};

struct LogShmem{
    LogSlot slot[TRADE_WTHREADS];
};