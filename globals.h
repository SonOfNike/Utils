#pragma once

#include "enums_typedef.h"

static const Price CENTS = 100;
static const Price DOLLAR = 100 * CENTS;
static const int32_t MD_QUEUE_SIZE = 4096;
static const int32_t LOG_QUEUE_SIZE = 2048;
static const int32_t RESP_QUEUE_SIZE = 1024;
static const int32_t ERROR_QUEUE_SIZE = 1024;
static const int32_t REQ_QUEUE_SIZE = 1024;

static const Timestamp MICRO_SECONDS = 1000;
static const Timestamp MILLI_SECONDS = 1000 * MICRO_SECONDS;
static const Timestamp SECONDS = MILLI_SECONDS * 1000;
static const Timestamp MINUTES = SECONDS * 60;
static const Timestamp HOURS = MINUTES * 60;

static const char* MD_shm_name = "/md_shared_memory";
static const char* RESP_shm_name = "/resp_shared_memory";
static const char* ERROR_shm_name = "/error_shared_memory";
static const char* REQ_shm_name = "/req_shared_memory";
static const char* LOG_shm_name = "/log_shared_memory";