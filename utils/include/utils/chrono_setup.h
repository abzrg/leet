#ifndef UTILS_CHRONO_CHRONO_SETUP_H
#define UTILS_CHRONO_CHRONO_SETUP_H

#include <stdint.h>
#include <stdio.h>

static double chrono_elapsed_time = 0.0; // NOLINT
static const double chrono_nsec_per_sec = 1e9;
static const double chrono_usec_per_sec = 1e6;

#define CHRONO_PRINT_START() printf("------ [CHRONO]: Start Timing...\n")

#define CHRONO_PRINT_ELAPSED(ELAPSED_TIME)                                     \
    do {                                                                       \
        printf("------ [CHRONO]: End Timing.");                                \
        printf("\n------ [CHRONO]: Elapsed Time = %lf\n\n", (ELAPSED_TIME));   \
    }                                                                          \
    while (0)

#endif // !UTILS_CHRONO_CHRONO_SETUP_H
