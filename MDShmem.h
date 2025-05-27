#pragma once

#include "globals.h"
#include "MDupdate.h"

struct MDShmem{
    int next_write_index = 0;
    MDupdate m_queue[MD_QUEUE_SIZE];
};