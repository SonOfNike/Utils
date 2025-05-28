#pragma once

#include "enums_typedef.h"

static const Price CENTS = 100;
static const Price DOLLAR = 100 * CENTS;
static const int32_t MD_QUEUE_SIZE = 1024;
static const int32_t RESP_QUEUE_SIZE = 1024;
static const int32_t REQ_QUEUE_SIZE = 1024;

static const char* MD_shm_name = "/md_shared_memory";
static const char* RESP_shm_name = "/resp_shared_memory";
static const char* REQ_shm_name = "/req_shared_memory";