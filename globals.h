#pragma once

const extern int CENTS = 100;
const extern int DOLLAR = 100 * CENTS;
const extern int MD_QUEUE_SIZE = 1024;
const extern int RESP_QUEUE_SIZE = 1024;
const extern int REQ_QUEUE_SIZE = 1024;

const char* MD_shm_name = "/md_shared_memory";
const char* RESP_shm_name = "/resp_shared_memory";
const char* REQ_shm_name = "/req_shared_memory";