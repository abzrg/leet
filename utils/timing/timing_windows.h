// NOT CHECKED!
#ifndef UTILS_TIMING_TIMING_WINDOWS_H
#define UTILS_TIMING_TIMING_WINDOWS_H

#include <windows.h>

double measureExecutionTime(TimedFunction function, void* data, ...);

double measureExecutionTime(TimedFunction function, void* data, ...)
{
    // Get the current time before executing the function
    LARGE_INTEGER start_time;
    QueryPerformanceCounter(&start_time);

    // Call the function with variable arguments
    va_list args;
    va_start(args, data);
    function(data, args);
    va_end(args);

    // Get the current time after executing the function
    LARGE_INTEGER end_time;
    QueryPerformanceCounter(&end_time);

    // Get the frequency of the performance counter
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);

    // Calculate the elapsed time in seconds
    double elapsed_time = (double)(end_time.QuadPart - start_time.QuadPart) /
                          (double)frequency.QuadPart;

    return elapsed_time;
}

#endif /* UTILS_TIMING_TIMING_WINDOWS_H */
