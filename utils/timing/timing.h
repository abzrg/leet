#ifndef UTILS_TIMING_TIMING_H
#define UTILS_TIMING_TIMING_H

#include <stdint.h>
#include <stdarg.h>

// Function pointer type for the code block to be timed
typedef void (*TimedFunction)(void* data, ...);

// Function to measure the execution time of a given function
double measureExecutionTime(TimedFunction function, void* data, ...);

// Platform-specific implementations
#if defined(__linux__)
#include "timing_linux.h"
#elif defined(__APPLE__)
#include "timing_macos.h"
#elif defined(_WIN32) || defined(_WIN64)
#include "timing_windows.h"
#elif defined(__OpenBSD__)
#include "timing_openbsd.h"
#else
#error "Unsupported platform"
#endif


#endif /* UTILS_TIMING_TIMING_H */
