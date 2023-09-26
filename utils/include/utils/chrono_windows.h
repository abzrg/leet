// NOT TESTED!
#ifndef UTILS_CHRONO_WINDOWS_H
#define UTILS_CHRONO_WINDOWS_H

#include <windows.h>

LARGE_INTEGER chrono_start_time;

inline static void chrono_start(void)
{
    CHRONO_PRINT_START();

    // Get the current time before executing the function
    QueryPerformanceCounter(&start_time);
}

inline static void chrono_stop(void)
{
    // Get the current time after executing the function
    LARGE_INTEGER chrono_end_time;
    QueryPerformanceCounter(&end_time);

    // Get the frequency of the performance counter
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);

    // Calculate the elapsed time in seconds
    chrono_elapsed_time
        = (double)(chrono_end_time.QuadPart - chrono_start_time.QuadPart)
          / (double)frequency.QuadPart;

    CHRONO_PRINT_ELAPSED(chrono_elapsed_time);
}

#endif /* UTILS_CHRONO_WINDOWS_H */
