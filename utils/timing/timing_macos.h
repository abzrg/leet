#ifndef UTILS_TIMING_TIMING_MACOS_H
#define UTILS_TIMING_TIMING_MACOS_H

#include <mach/mach_time.h>

double measureExecutionTime(TimedFunction function, void* data, ...);

double measureExecutionTime(TimedFunction function, void* data, ...)
{
    // Get the current time before executing the function
    uint64_t start_time = mach_absolute_time();

    // Call the function with variable arguments
    va_list args;
    va_start(args, data);
    function(data, args);
    va_end(args);

    // Get the current time after executing the function
    uint64_t end_time = mach_absolute_time();

    // Convert elapsed time to seconds using the timebase info
    mach_timebase_info_data_t timebase;
    mach_timebase_info(&timebase);
    double elapsed_time = (double)(end_time - start_time) *
                          (double)timebase.numer / (double)timebase.denom / 1e9;

    return elapsed_time;
}

#endif /* UTILS_TIMING_TIMING_MACOS_H */
