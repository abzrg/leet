/* 345. Reverse Vowels of a String

(EASY)

Given a string s, reverse only all the vowels in
the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and
they can appear in both lower and upper cases,
more than once.


Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SWAP_CHAR_BITWISE


#ifdef SWAP_CHAR_BITWISE
#define SWAP_CHARS(str, i, j) \
    do { \
        (str)[i] ^= (str)[j]; \
        (str)[j] ^= (str)[i]; \
        (str)[i] ^= (str)[j]; \
    } while(0)
#else
#define SWAP_CHARS(str, i, j) \
    do { \
        char tmp = (str)[i]; \
        (str)[i] = (str)[j]; \
        (str)[j] = tmp; \
    } while(0)
#endif


static inline bool is_vowel(char c);
static char * reverse_vowels(char * str);


// ---<main>--------------------------------------


int main(void)
{
#if 1
    char str[] = "hello"; // -> "holle"
#else
    char str[] = "leetcode"; // -> "leotcede"
#endif

    const char* result = reverse_vowels(str);

    printf("%s\n", result);

    return 0;
}


// ---<end main>----------------------------------


static inline bool is_vowel(char c)
{
    switch (c) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        return true;
    }

    return false;
}


static char* reverse_vowels(char* str)
{
#if 1
    size_t left = 0;
    size_t right = 0;

    // Go to the last character
    while (str[right] != '\0') {
        right++;
    }
    right--;

    while (left < right) {
        // Get to the left most vowel from where you are
        while (left < right && !is_vowel(str[left])) {
            left++;
        }

        // Get to the right most vowel from where you are
        while (left < right && !is_vowel(str[right])) {
            right--;
        }

        // If left vowel is in a position behind the right vowel, swap them
        if (left < right) {
            SWAP_CHARS(str, left, right);
            left++;
            right--;
        }
    }

#else
    for (size_t i = 0, len = strlen(str), j = len; i < len; i++) {
        if (!is_vowel(str[i]))
            continue;

        while (j > i) {
            if (is_vowel(str[j])) {
                SWAP_CHARS(str, i, j);

                j--;
                break;
            }

            j--;
        }
    }
#endif

    return str;
}
