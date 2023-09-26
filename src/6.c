// 06: 151. reverse word in a string
// url: https://leetcode.com/problems/reverse-words-in-a-string/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMITER " "

char* reverse_words(char* restrict s)
{
    // strtok() modifies the string it operates on, replacing delimiter
    // characters with `NULL`s.
    char* copy = malloc(sizeof(*copy) * strlen(s));
    copy = strcpy(copy, s);

    // Getting the count of tokens
    size_t token_count = 0;
    char* token = strtok(s, DELIMITER);
    while (token != NULL) {
        token_count++;
        token = strtok(NULL, DELIMITER);
    }

    char** tokens = malloc(sizeof(*tokens) * token_count);
    token = strtok(copy, DELIMITER);
    for (size_t i = 0; token != NULL; i++) {
        size_t token_len = strlen(token);
        assert(token_len != 0 && "Token of size zero!");

        char* tmp = malloc(sizeof(*tmp) * token_len + 1);
        assert(tmp && "You are so poor!");
        strncpy(tmp, token, token_len);
        tokens[i]
            = tmp; // ? Use of memory allocated with size zero [unix.Malloc]


        token = strtok(NULL, DELIMITER);
    }

    // Assmble tokens in reverse order into a string
    char* reversed = malloc(sizeof(*reversed) * strlen(s) + 1);
    // i : looping over tokens
    // j : the position in which tokens or a space should be placed
    for (int i = (int)token_count - 1, j = 0; i > -1; i--) {
        size_t token_len
            = strlen(tokens[i]); // ? 1st function call argument is an
                                 // uninitialized value [core.CallAndMessage]
        strncpy(reversed + j, tokens[i], token_len);

        // Free token
        free(tokens[i]);

        // Add one space in between tokens;
        reversed[j + token_len] = ' ';

        // Thus far we added a token and a space
        j += (int)token_len + 1;
    }

    // Free list of tokens
    free(tokens);

    // Remember to free reversed in the caller
    return reversed;
}

int main(void)
{
    char s[] = "This is not the best of ideas.";

    char* reversed = reverse_words(s);
    printf("%s\n", reversed);

    free(reversed);

    return 0;
}
