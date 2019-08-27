#include <stdio.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int m, n, k, a[100001] = {0};

    fscanf(f, "%d%d", &n, &m);
    while (n--)
    {
        fscanf(f, "%d", &k);
        a[k] = 1;
    }
    while (m--)
    {
        fscanf(f, "%d", &k);
        if (a[k])
            a[k] = 2;
    }
    for (k = 0; k < 100001; ++k)
        if (a[k] == 2)
            fprintf(q, "%d ", k);
    return 0;
}
