#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int w, h, n, i, j, x1, y1, x2, y2;
    char *d;

    fscanf(f, "%d%d%d", &w, &h, &n);
    d = (char*)calloc(w * h, 1);
    while (n--)
    {
        fscanf(f, "%d%d%d%d", &x1, &y1, &x2, &y2);
        for(i = x1; i < x2; ++i)
            for(j = y1; j < y2; ++j)
                d[w * i + j] = 1;
    }
    for (i = 0, n = 0; i < h; ++i)
        for (j = 0; j < w; ++j)
            n += d[w * i + j];
    fprintf(q, "%d", w * h - n);
    return 0;
}
