#pragma once

#include <pthread.h>
#include <thread>

void pin_thread_to_core(std::thread& t, int core_id);

void pin_current_thread(int core_id);