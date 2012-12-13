#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAX_TESTCASES 100
#define MAX_SHEEPS 100000
#define MAX_COORD 10000

int random_int(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int main(int argc, char **argv)
{
    // random generator initialization
    int seed = -1;
    if (argc > 1)
    {
        seed = atoi(argv[1]);
    }
    struct timeval t;
    gettimeofday(&t, NULL);
    if (seed < 0)
        srand(t.tv_sec + t.tv_usec);
    else
        srand(seed);
    // test case generation
    int test_count = random_int(MAX_TESTCASES, MAX_TESTCASES);
    int i,j;
    printf("%d\n\n", test_count);
    for (i=0; i<test_count; i++)
    {
        int sheep_count = random_int(MAX_SHEEPS, MAX_SHEEPS);
        printf("%d\n", sheep_count);
        for (j=0; j<sheep_count; j++)
        {
            int x = random_int(-MAX_COORD, MAX_COORD);
            int y = random_int(-MAX_COORD, MAX_COORD);
            printf("%d %d\n", x, y);
        }
        printf("\n");
    }
    return 0;
}
