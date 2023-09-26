#ifndef UTILS_CHRONO_MACOS_H
#define UTILS_CHRONO_MACOS_H

#include <mach/mach_time.h>

#include "./chrono_setup.h"

static uint64_t chrono_start_time = { 0 }; // NOLINT

inline static void chrono_start(void)
{
    CHRONO_PRINT_START();

    // Get the current time before executing the function
    chrono_start_time = mach_absolute_time();
}

inline static void chrono_stop(void)
{
    // Get the current time after executing the function
    uint64_t chrono_end_time = mach_absolute_time();

    // Convert elapsed time to seconds using the timebase info
    mach_timebase_info_data_t timebase;
    mach_timebase_info(&timebase);
    chrono_elapsed_time = (double)(chrono_end_time - chrono_start_time)
                          * (double)timebase.numer / (double)timebase.denom
                          / chrono_nsec_per_sec;

    CHRONO_PRINT_ELAPSED(chrono_elapsed_time);
}

#endif /* UTILS_CHRONO_MACOS_H */
