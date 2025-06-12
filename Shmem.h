#pragma once

#include "globals.h"

template <typename QUEUE_SIZE, typename DATA_TYPE>
struct Shmem{
    int32_t next_write_index = 0;
    int32_t next_write_page = 0;
};