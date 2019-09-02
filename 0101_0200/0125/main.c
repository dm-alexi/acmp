#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, i, j, k = 0, *p, *m;
    fscanf(f, "%d", &n);
    m = (int*)malloc(sizeof(int) * n * n);
    p = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n * n; ++i)
        fscanf(f, "%d", m + i);
    for (i = 0; i < n; ++i)
        fscanf(f, "%d", p + i);
    for (i = 0; i < n - 1; ++i)
        for (j = i + 1; j < n; ++j)
            if(m[i * n + j] && p[i] != p[j])
                ++k;
    fprintf(q, "%d", k);
    return 0;
}
