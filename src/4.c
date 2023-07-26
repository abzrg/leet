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

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>

//-----------------------------------------------------------------------------

#define ARR_SIZE(ARR) ((sizeof((ARR)) / sizeof((ARR)[0])))

// #define TIME

#ifdef TIME
#include "utils/timing/timing.h"
#endif

enum State {
    EMPTY,
    PLANTED
};

//-----------------------------------------------------------------------------

void validate_constraints(int* fb, size_t fb_size, size_t n);
bool can_place_flowers(int *fb, size_t fb_size, size_t n);

//-----------------------------------------------------------------------------

struct CodeblockData {
    int *fb;
    size_t fb_size;
    size_t n;
};

void codeblock(void* data, ...)
{
    struct CodeblockData* cb_data = (struct CodeblockData*)data;
    int *fb = cb_data->fb;
    size_t fb_size = cb_data->fb_size;
    size_t n = cb_data->n;

    printf("ans = %d\n", can_place_flowers(fb, fb_size, n));
}

//-----------------------------------------------------------------------------


int main(void)
{
#if 1
    int fb[] = { PLANTED, EMPTY, EMPTY, EMPTY, PLANTED };
    size_t n = 1;
#else
    int fb[] = { PLANTED, EMPTY, EMPTY, EMPTY, PLANTED };
    size_t n = 2;
#endif
    size_t fb_size = ARR_SIZE(fb);
    // validate the flowerbed against the constraints
    validate_constraints(fb, fb_size, n);

#ifdef TIME
    double time = measureExecutionTime(codeblock, fb, fb_size, n);
    printf("\nElapsed Time: %e seconds\n", time);
#else
    printf("ans = %d\n", can_place_flowers(fb, fb_size, n));
#endif

    return 0;
}

//-----------------------------------------------------------------------------

/**
 * Note: returns -1 when initial state is not
 * valid, otherwise non-negative index of wrong
 * plot
 */
void validate_constraints(int* fb, size_t fb_size, size_t n)
{
    if (fb_size < 1 && fb_size > 2*104)
        fprintf(stderr, "Incorrect flowerbed length\n");
    if (n > fb_size)
        fprintf(stderr, "Incorrect number of flowers to plant\n");

    for (size_t i = 0; i < fb_size; i++)
    {
        if (fb[i] != EMPTY && fb[i] != PLANTED)
        {
            fprintf(stderr,
                    "Incorrect Initial State: Invalid plot at index: %zu\n",
                    i);
        }
    }

    int wrong_index = -1;
    for (size_t i = 0; i < fb_size; i++)
    {
        if (fb[i] == EMPTY)
            continue;

        if (i == 0 && fb[i + 1] == PLANTED)
            wrong_index = i;
        else
            continue;

        if (i == fb_size - 1 && fb[i - 1] == PLANTED)
            wrong_index = i;
        else
            break;

        if (fb[i - 1] == PLANTED || fb[i + 1] == PLANTED)
            wrong_index = i;
    }


    if (wrong_index != -1)
    {
        fprintf(stderr,
                "Incorrect Initial State: Wrongly planted plot at index: %d\n",
                wrong_index);
    }
}


/**
 * @param:
 *  -  fb:  flowerbed
 *  -  n:   count of flowers to plant
 */
bool can_place_flowers(int *fb, size_t fb_size, size_t n)
{
    for (size_t i = 0; i < fb_size; i++)
    {
        if (fb[i] == EMPTY &&
                (i == 0 || fb[i - 1] == EMPTY) &&
                (i == fb_size - 1 || fb[i + 1] == EMPTY))
        {
            fb[i] = PLANTED;
            n--;
        }
    }

    // Return true if all flowers are planted
    return n <= 0;
}
