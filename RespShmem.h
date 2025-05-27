#pragma once

#include "globals.h"
#include "Response.h"

struct RespShmem{
    int next_write_index = 0;
    Response queue[RESP_QUEUE_SIZE];
};