#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, m, *p, maxmin = -1000, minmax = 1000;

    fscanf(f, "%d%d", &n, &m);
    p = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; ++i)
        p[i] = -1000;
    for (int i = 0; i < n; ++i)
    {
        int min = 1000, k;
        for (int j = 0; j < m; ++j)
        {
            fscanf(f, "%d", &k);
            if (k < min)
                min = k;
            if (k > p[j])
                p [j] = k;
        }
        if (min > maxmin)
            maxmin = min;
    }
    for (int i = 0; i < m; ++i)
        if (p[i] < minmax)
            minmax = p[i];
    fprintf(q, "%d %d", maxmin, minmax);
    return 0;
}
