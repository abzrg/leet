// 06: 151. reverse word in a string
// url: https://leetcode.com/problems/reverse-words-in-a-string/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMITER " "

char* reverse_words(char* str)
{
    // Count the number of tokens
    char* copy = strdup(str);
    assert(copy != NULL && "ERROR: NOMEM");
    size_t token_count = 0;
    char* token = NULL;
    while ((token = strtok_r(copy, DELIMITER, &copy))) {
        token_count++;
    }

    free(copy);
    copy = str; // We need this as str will be overwritten by strtok_r

    // Storing tokens into an array of chars
    char** tokens = malloc(sizeof(*tokens) * token_count);
    size_t i = 0;
    while ((token = strtok_r(str, DELIMITER, &str))) {
        size_t token_len = strlen(token);
        assert(token_len != 0 && "Token of size zero!");

        tokens[i] = strdup(token);

        i++;
    }

    str = copy;

    // Assmble tokens in reverse order into a string
    // i : looping over tokens
    // j : the position in which tokens or a space should be placed
    for (int i = (int)token_count - 1, j = 0; i > -1; i--) {
        size_t token_len = strlen(tokens[i]);
        strncpy(&str[j], tokens[i], token_len);

        // Free token
        free(tokens[i]);

        // Add one space in between tokens
        // If last token has been inserted then add a null terminator at the end
        if (i == 0) {
            str[j + token_len] = '\0';
        } else {
            str[j + token_len] = ' ';
        }

        // Thus far we added a token and a space
        j += (int)token_len + 1;
    }

    // Free list of tokens
    free(tokens);

    return str;
}

int main(void)
{
    char* str = strdup("This is not the best of ideas.");
    char* reversed = reverse_words(str);
    printf("%s\n", reversed);

    return 0;
}
