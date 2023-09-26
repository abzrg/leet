// CHRONO
// ------
//
// A tool for timing code
//
// Usage:
//
//      chrono
//      {
//          your code here...
//      }
//
// This prints the elapsed time to standard output
//
// To disable timing define the `NOCHRONO` symbol at the top of your code
//
//      #define NOCHRONO

#ifndef UTILS_CHRONO_CHRONO_H
#define UTILS_CHRONO_CHRONO_H

#include <assert.h>
#include <stdint.h>

#include "./defer.h"

#if defined(__linux__)
#include "chrono_linux.h"
#elif defined(__APPLE__)
#include "chrono_macos.h"
#elif defined(_WIN32) || defined(_WIN64)
#include "chrono_windows.h"
#elif defined(__OpenBSD__)
#include "chrono_openbsd.h"
#else
#error "Unsupported platform"
#endif

#ifndef NOCHRONO
#define chrono defer(chrono_start(), chrono_stop())
#else
#define chrono ((void)0);
#endif

#endif /* UTILS_CHRONO_CHRONO_H */
