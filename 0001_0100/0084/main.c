#include <stdio.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, m, xmax = -1, xmin, ymax = -1, ymin;

    fscanf(f, "%d %d\n", &n, &m);
    xmin = m, ymin = n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            if (getc(f) == '*')
            {
                ymax = i;
                if (j < xmin)
                    xmin = j;
                if (j > xmax)
                    xmax = j;
            }
        if (i < ymin && ymax == i)
            ymin = i;
        getc(f);
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            putc(i < ymin || i > ymax || j < xmin || j > xmax ? '.' : '*', q);
        putc('\n', q);
    }
    return 0;
}
