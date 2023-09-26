// NOT CHECKED!
#ifndef UTILS_TIMING_TIMING_OPENBSD_H
#define UTILS_TIMING_TIMING_OPENBSD_H

#include <sys/time.h>

#include "./chrono_setup.h"

static struct timeval start_time = {}; // NOLINT

inline static void chrono_start(void)
{
    CHRONO_PRINT_START();

    // Get the current time before executing the function
    gettimeofday(&start_time, NULL);
}

inline static void chrono_stop(void)
{
    // Get the current time after executing the function
    struct timeval chrono_end_time = {};
    gettimeofday(&chrono_end_time, NULL);

    // Calculate the elapsed time in seconds
    chrono_elapsed_time = (double)(chrono_end_time.tv_sec - start_time.tv_sec)
                          + (chrono_end_time.tv_usec - start_time.tv_usec)
                                / chrono_usec_per_sec;

    CHRONO_PRINT_ELAPSED(chrono_elapsed_time);
}

#endif /* UTILS_TIMING_TIMING_OPENBSD_H */
