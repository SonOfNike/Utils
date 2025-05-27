#pragma once

#include "globals.h"
#include "Request.h"

struct ReqShmem{
    int next_write_index = 0;
    Request queue[REQ_QUEUE_SIZE];
};