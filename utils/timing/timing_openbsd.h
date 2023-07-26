// NOT CHECKED!
#ifndef UTILS_TIMING_TIMING_OPENBSD_H
#define UTILS_TIMING_TIMING_OPENBSD_H

#include <sys/time.h>

double measureExecutionTime(TimedFunction function, void* data, ...);

double measureExecutionTime(TimedFunction function, void* data, ...)
{
    // Get the current time before executing the function
    struct timeval start_time;
    gettimeofday(&start_time, NULL);

    // Call the function with variable arguments
    va_list args;
    va_start(args, data);
    function(data, args);
    va_end(args);

    // Get the current time after executing the function
    struct timeval end_time;
    gettimeofday(&end_time, NULL);

    // Calculate the elapsed time in seconds
    double elapsed_time = (end_time.tv_sec - start_time.tv_sec) +
                          (end_time.tv_usec - start_time.tv_usec) / 1e6;

    return elapsed_time;
}

#endif /* UTILS_TIMING_TIMING_OPENBSD_H */
