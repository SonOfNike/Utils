#include "pin_thread_functions.h"


void pin_thread_to_core(std::thread& t, int core_id) {
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(core_id, &cpuset);
    
    pthread_t native_handle = t.native_handle();
    int rc = pthread_setaffinity_np(native_handle, sizeof(cpu_set_t), &cpuset);
    if (rc != 0) {
        // Handle error (e.g., logging)
    }
}

void pin_current_thread(int core_id) {
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(core_id, &cpuset);

    pthread_t face = pthread_self(); 
    int success = pthread_setaffinity_np(face, sizeof(cpu_set_t), &cpuset);
    
    if (success != 0) {
        // Handle error (e.g., logging)
    }
}