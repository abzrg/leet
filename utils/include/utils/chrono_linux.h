#ifndef UTILS_CHRONO_LINUX_H
#define UTILS_CHRONO_LINUX_H

#include <time.h>

#include "./chrono_setup.h"

static struct timespec chrono_start_time = {}; // NOLINT

inline static void chrono_start(void)
{
    CHRONO_PRINT_START();

    // Get the current time before executing the function
    clock_gettime(CLOCK_MONOTONIC, &chrono_start_time);
}

inline static void chrono_stop(void)
{
    // Get the current time after executing the function
    struct timespec chrono_end_time = {};
    clock_gettime(CLOCK_MONOTONIC, &chrono_end_time);

    // Calculate the elapsed time in seconds
    double elapsed_time
        = (double)(chrono_end_time.tv_sec - chrono_start_time.tv_sec)
          + (double)(chrono_end_time.tv_nsec - chrono_start_time.tv_nsec)
                / chrono_nsec_per_sec;

    CHRONO_PRINT_ELAPSED(chrono_elapsed_time);
}

#endif /* UTILS_CHRONO_LINUX_H */
