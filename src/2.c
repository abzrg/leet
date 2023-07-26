/* 1071. Greatest Common Divisor of Strings
 *
 * (EASY)
 *
 * For two strings s and t, we say "t divides s" if
 * and only if s = t + ... + t (i.e., t is
 * concatenated with itself one or more times).
 *
 * Given two strings str1 and str2, return the
 * largest string x such that x divides both str1 and
 * str2.
 *
 * Constraints:
 *
 * 1 <= str1.length, str2.length <= 1000
 * str1 and str2 consist of English uppercase letters.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

// ----------------------------------------------------------------------------

static void print_facs(char** facs);
static void dealloc_facs(char** facs);
static void *init_set(size_t size, int val, size_t len);
static char** extract_factors(const char* str);
static char* strgcd(const char* str1, const char* str2);

// ----------------------------------------------------------------------------

int main(void)
{
    const char* str1 = "ABCABCABCABC";
    const char* str2 = "ABC";
    char* gcd1 = strgcd(str1, str2);
    printf("%s\n%s\n=> %s\n\n", str1, str2, gcd1);

    const char* str3 = "ABABAB";
    const char* str4 = "ABAB";
    char* gcd2 = strgcd(str3, str4);
    printf("%s\n%s\n=> %s\n\n", str3, str4, gcd2);

    const char* str5 = "LEET";
    const char* str6 = "CODE";
    char* gcd3 = strgcd(str5, str6);
    printf("%s\n%s\n=> %s\n\n", str5, str6, gcd3);


#if 0
    print_facs(facs1);
    print_facs(facs2);
#endif

    free(gcd1);
    free(gcd2);
    free(gcd3);

    return 0;
}

// ----------------------------------------------------------------------------

static void *init_set(size_t size, int val, size_t len)
{
    char* tmp = malloc(size);
    assert(tmp != NULL);
    memset(tmp, val, len);
    return tmp;
}

static char** extract_factors(const char* str)
{
    size_t len = strlen(str);

    // list of factors
    char **factors = init_set(sizeof(*factors) * (len+1), 0, len+1);
    // multiples
    char *mult = init_set(sizeof(*mult) * (len+1), 0, len+1);
    // combination of multiples
    char *combined = init_set(sizeof(*combined) * (len+1), 0, len+1);

    size_t i = 1;
    size_t j = 0;
    size_t k = 0;
    while (i < len)
    {
        memset(combined, 0, len+1);

        strncpy(mult, str, i);
        mult[i] = '\0';

        j = 0;
        while (j < len)
        {
            if (i + j > len + 1)
                break;

            strncpy(combined + j, mult, i);
            j += i;
        }

        if (!strcmp(combined, str))
        {
            factors[k] = malloc(sizeof(**factors) * (len+1));
            memset(factors[k], 0, len+1);
            strcpy(factors[k++], mult);
        }

        i++;
    }

    factors[k] = malloc(sizeof(**factors) * (len+1));
    strcpy(factors[k], str);

    factors[++k] = NULL;

    free(combined);
    free(mult);

    return factors;
}

static inline void print_facs(char** facs)
{
    size_t i = 0;
    while (facs[i] != NULL)
    {
        printf("factor str0.(%zu) = %s\n", i+1, facs[i]);
        i++;
    }
}

static inline void dealloc_facs(char** facs)
{
    size_t i = 0;
    while(facs[i] != NULL)
    {
        free(facs[i++]);
    }
    free(facs);
}

static char* strgcd(const char* str1, const char* str2)
{
    const size_t len1 = strlen(str1);
    const size_t len2 = strlen(str2);
    const size_t max_len = len1 > len2 ? len1 : len2;

    char** facs1 = extract_factors(str1);
    assert(facs1 != NULL);
    char** facs2 = extract_factors(str2);
    assert(facs2 != NULL);

    char **com_divisors =
        init_set(sizeof(**com_divisors)* (max_len+1), 0, (max_len+1));
    assert(com_divisors != NULL);

    size_t i = 0;
    size_t k = 0;
    while (facs1[i])
    {
        size_t j = 0;
        while (facs2[j] != NULL)
        {
            if (!strcmp(facs1[i], facs2[j]))
            {
                com_divisors[k] = malloc(sizeof(**com_divisors));
                assert(com_divisors[k] != NULL);
                strcpy(com_divisors[k], facs1[i]);
                k++;
            }
            j++;
        }
        i++;
    }
    com_divisors[k] = NULL;

    i = 0;
    char* gcd = malloc(sizeof(*gcd)*(max_len+1));
    assert(gcd != NULL);
    size_t max_size = 0;
    while (com_divisors[i] != NULL)
    {
        size_t cd_len = strlen(com_divisors[i]);
        if (cd_len > max_size)
            strcpy(gcd, com_divisors[i]);
        i++;
    }

    dealloc_facs(facs1);
    dealloc_facs(facs2);
    dealloc_facs(com_divisors);

    return gcd;
}
