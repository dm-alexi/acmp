#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, m, i;
    unsigned int *p, a, b, c, d, x, y;

    fscanf(f, "%d", &n);
    p = (unsigned int*)malloc(sizeof(int) * n);
    for(i = 0; i < n; ++i)
    {
        fscanf(f, "%u.%u.%u.%u", &a, &b, &c, &d);
        p[i] = (((((a << 8) | b) << 8) | c) << 8) | d;
    }
    fscanf(f, "%d", &m);
    for(i = 0; i < m; ++i)
    {
        int j, k = 0;
        fscanf(f, "%u.%u.%u.%u", &a, &b, &c, &d);
        x = (((((a << 8) | b) << 8) | c) << 8) | d;
        fscanf(f, "%u.%u.%u.%u", &a, &b, &c, &d);
        y = (((((a << 8) | b) << 8) | c) << 8) | d;
        for (j = 0; j < n; ++j)
            if ((x & p[j]) == (y & p[j]))
                ++k;
        fprintf(q, "%d\n", k);
    }
    return 0;
}
