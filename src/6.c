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
    char* copy = malloc(sizeof(*copy) * strlen(s) + 1);
    copy = strcpy(copy, s);

    // Getting the count of tokens
    size_t token_count = 0;
    char* token = strtok(copy, DELIMITER);
    while (token != NULL) {
        token_count++;
        token = strtok(NULL, DELIMITER);
    }

    free(copy);

    char** tokens = malloc(sizeof(*tokens) * token_count);
    token = strtok(s, DELIMITER);
    for (size_t i = 0; token != NULL; i++) {
        size_t token_len = strlen(token);
        assert(token_len != 0 && "Token of size zero!");

        char* tmp = malloc(sizeof(*tmp) * token_len + 1);
        assert(tmp && "You are so poor!");
        strncpy(tmp, token, token_len + 1);
        tokens[i]
            = tmp; // ? Use of memory allocated with size zero [unix.Malloc]


        token = strtok(NULL, DELIMITER);
    }

    // Assmble tokens in reverse order into a string
    // i : looping over tokens
    // j : the position in which tokens or a space should be placed
    for (int i = (int)token_count - 1, j = 0; i > -1; i--) {
        size_t token_len
            = strlen(tokens[i]); // ? 1st function call argument is an
                                 // uninitialized value [core.CallAndMessage]
        strncpy(s + j, tokens[i], token_len);

        // Free token
        free(tokens[i]);

        // Add one space in between tokens
        // If last token has been inserted then add a null terminator at the end
        if (i == 0) {
            s[j + token_len] = '\0';
        } else {
            s[j + token_len] = ' ';
        }

        // Thus far we added a token and a space
        j += (int)token_len + 1;
    }

    // Free list of tokens
    free(tokens);

    // Remember to free reversed in the caller
    return s;
}

int main(void)
{
    char s[] = "This is not the best of ideas.";

    char* reversed = reverse_words(s);
    printf("%s\n", reversed);

    // free(reversed);

    return 0;
}
