/* 605. Can Place Flowers

(EASY)

You have a long flowerbed in which some of the
plots are planted, and some are not. However,
flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's
and 1's, where 0 means empty and 1 means not
empty, and an integer n, return true if n new
flowers can be planted in the flowerbed without
violating the no-adjacent-flowers rule and false
otherwise.


Constraints:

- 1 <= flowerbed.length <= 2 * 104
- flowerbed[i] is 0 or 1.
- There are no two adjacent flowers in flowerbed.
- 0 <= n <= flowerbed.length

*/

#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_SIZE(ARR) ((sizeof((ARR)) / sizeof((ARR)[0])))

#ifndef NOCHRONO
#include "utils/chrono.h"
#endif

enum State { EMPTY, PLANTED };

void validate_constraints(const int* fb, size_t fb_size, size_t n);
bool can_place_flowers(int* fb, size_t fb_size, size_t n);

int main(void)
{
#if 1 // Case 1
    int fb[] = { PLANTED, EMPTY, EMPTY, EMPTY, PLANTED };
    size_t n = 1;
#else // Case 2
    int fb[] = { PLANTED, EMPTY, EMPTY, EMPTY, PLANTED };
    size_t n = 2;
#endif

    size_t fb_size = ARR_SIZE(fb);

    // Validate the flowerbed against the constraints
    validate_constraints(fb, fb_size, n);

    bool can_place = false;

    chrono
    {
        can_place = can_place_flowers(fb, fb_size, n);
    }

    printf("ans = %d\n", can_place);

    return 0;
}

/**
 * Returns -1 when initial state is not valid, otherwise non-negative index of
 * wrong plot
 */
void validate_constraints(const int* fb, size_t fb_size, size_t n)
{
    if (fb_size < 1 || fb_size > 2 * 104) {
        fprintf(stderr, "Incorrect flowerbed length\n"); // NOLINT
    }

    if (n > fb_size) {
        fprintf(stderr, "Incorrect number of flowers to plant\n"); // NOLINT
    }

    for (size_t i = 0; i < fb_size; i++) {
        if (fb[i] != EMPTY && fb[i] != PLANTED) {
            fprintf(stderr, // NOLINT
                    "Incorrect Initial State:"
                    " Invalid plot at index: %zu\n",
                    i);
        }
    }

    int wrong_index = -1;
    for (size_t i = 0; i < fb_size; i++) {
        if (fb[i] == EMPTY) {
            continue;
        }

        if (i == 0 && fb[i + 1] == PLANTED) {
            wrong_index = (int)i;
        } else {
            continue;
        }

        if (i == fb_size - 1 && fb[i - 1] == PLANTED) {
            wrong_index = (int)i;
        } else {
            break;
        }

        if (fb[i - 1] == PLANTED || fb[i + 1] == PLANTED) {
            wrong_index = (int)i;
        }
    }


    if (wrong_index != -1) {
        fprintf(stderr, // NOLINT
                "Incorrect Initial State:"
                " Wrongly planted plot at index: %d\n",
                wrong_index);
    }
}

/**
 * @param:
 *  - fb:  flowerbed
 *  - n:   count of flowers to plant
 */
bool can_place_flowers(int* fb, size_t fb_size, size_t n) // NOLINT
{
    for (size_t i = 0; i < fb_size; i++) {
        if (fb[i] == EMPTY && (i == 0 || fb[i - 1] == EMPTY)
            && (i == fb_size - 1 || fb[i + 1] == EMPTY)) {
            fb[i] = PLANTED;
            n--;
        }
    }

    // Return true if all flowers are planted
    return n <= 0;
}
