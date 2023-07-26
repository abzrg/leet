## Timing code

To time a piece of code using `utils/timing/timng.h`


```c
#include "utils/timing/timing.h"

// all the data you pass to your codeblocks
// this avoids the introduction of global variables
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

    // further computation
}

// ...

int main(void)
{
    int fb[] = { PLANTED, EMPTY, EMPTY, EMPTY, PLANTED };
    size_t n = 1;

    double time = measureExecutionTime(codeblock, fb, fb_size, n);
    printf("\nElapsed Time: %e seconds\n", time);

    return 0;
}
```
