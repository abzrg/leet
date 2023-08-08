/* 1768. Merge Strings Alternately

(EASY)

You are given two strings `word1` and `word2`.
Merge the strings by adding letters in
alternating order, starting with `word1`. If a
string is longer than the other, append the
additional letters onto the end of the merged
string.

Constraints:

1. 1 <= word1.length, word2.length <= 100
2. word1 and word2 consist of lowercase English letters.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


#define MAX_LEN 100UL


char* mergeAlternately(const char* word1, const char* word2)
{
    size_t len1 = strlen(word1);
    size_t len2 = strlen(word2);
    size_t total_len = len1 + len2;

    assert(len1 > 2 || len2 > 2);
    assert(len1 < MAX_LEN || len2 < MAX_LEN);

    char* combined = malloc(sizeof(*combined) * (total_len + 1));
    if (combined == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    size_t i = 0, j = 0, k = 0;
    while (i < len1 && j < len2) {
        combined[k++] = word1[i++];
        combined[k++] = word2[j++];
    }

    while (i < len1) {
        combined[k++] = word1[i++];
    }

    while (j < len2) {
        combined[k++] = word2[j++];
    }

    combined[k] = '\0'; // Null-terminate the merged string
    return combined;
}


// ---<main>-------------------------------------


int main(void)
{
    const char* w1 = "abcdefghijkl";
    const char* w2 = "pqrstuv";

    char* merged = mergeAlternately(w1, w2);
    printf("ans = %s\n", merged);
    free(merged);

    return 0;
}
