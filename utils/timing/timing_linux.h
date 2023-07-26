#ifndef UTILS_TIMING_TIMING_LINUX_H
#define UTILS_TIMING_TIMING_LINUX_H

#include <time.h>

double measureExecutionTime(TimedFunction function, void* data, ...);

double measureExecutionTime(TimedFunction function, void* data, ...)
{
    // Get the current time before executing the function
    struct timespec start_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    // Call the function with variable arguments
    va_list args;
    va_start(args, data);
    function(data, args);
    va_end(args);

    // Get the current time after executing the function
    struct timespec end_time;
    clock_gettime(CLOCK_MONOTONIC, &end_time);

    // Calculate the elapsed time in seconds
    double elapsed_time = (end_time.tv_sec - start_time.tv_sec) +
                          (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

    return elapsed_time;
}

#endif /* UTILS_TIMING_TIMING_LINUX_H */
