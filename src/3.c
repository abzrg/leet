/* 1431. Kids With the Greatest Number of Candies

(EASY)

There are n kids with candies. You are given an
integer array candies, where each candies[i]
represents the number of candies the ith kid has,
and an integer extraCandies, denoting the number
of extra candies that you have.

Return a boolean array result of length n, where
result[i] is true if, after giving the ith kid all
the extraCandies, they will have the greatest
number of candies among all the kids, or false
otherwise.

Note that multiple kids can have the greatest
number of candies.


Constraints:

- n == candies.length
- 2 <= n <= 100
- 1 <= candies[i] <= 100
- 1 <= extraCandies <= 50

*/

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define ARR_SIZE(ARR) (sizeof(ARR) / sizeof(ARR[0]))

static inline uint64_t arrmax(uint64_t* arr, size_t len);
static bool* kids_with_candies(
        uint64_t* candies,
        size_t candies_size,
        uint64_t extra_candies);


int main(void)
{
#if 0
    uint64_t  candies[]     =  { 2, 3, 5, 1, 3 };
    uint64_t  extra_candies =  3;
    // Output: [1 1 1 0 1]
#endif

#if 0
    uint64_t  candies[]      =  { 4, 2, 1, 1, 2 };
    uint64_t  extra_candies  =  1;
    // Output: [1 0 0 0 0]
#endif

#if 1
    uint64_t  candies[]      =  { 12, 1, 12 };
    uint64_t  extra_candies  =  10;
    // Output: [1 0 1]
#endif

    bool* result;

    result = kids_with_candies(candies, ARR_SIZE(candies), extra_candies);

    for (size_t i = 0; i < ARR_SIZE(candies); i++)
    {
        printf("%d ", result[i]);
    }
    fputs("\n", stdout);

    free(result);

    return 0;
}



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
static bool* kids_with_candies(
        uint64_t*  candies,
        size_t   candies_size,
        uint64_t   extra_candies)
{
    // constraints
    assert(candies_size >= 2 && candies_size <= 100);
    for (size_t i = 0; i < candies_size; i++){
        uint64_t tmp = candies[i];
        assert(tmp >= 1 && tmp <= 100);
    }
    assert(extra_candies >= 1 && extra_candies <= 50);

    uint64_t m = arrmax(candies, candies_size);
    bool* lions = malloc(sizeof(*lions) * candies_size);
    memset(lions, false, candies_size);

    size_t i = 0;
    while (i < candies_size)
    {
        bool is_lion = true;
        uint64_t increased = candies[i] + extra_candies;

        size_t j = 0;
        while (j < candies_size)
        {
            if (increased < m)
            {
                is_lion = false;
                break;
            }
            j++;
        }

        lions[i] = is_lion;
        i++;
    }
    return lions;
}

static inline uint64_t arrmax(uint64_t* arr, size_t len)
{
    uint64_t max = 0;

    size_t i = 0;
    while (i < len)
    {
        if (arr[i] > max)
            max = arr[i];
        i++;
    }

    return max;
}

