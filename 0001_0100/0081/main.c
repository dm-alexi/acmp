#include <stdio.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, min, max, t;

    fscanf(f, "%d%d", &n, &min);
    max = min;
    while (--n)
    {
        fscanf(f, "%d", &t);
        if (t > max)
            max = t;
        if (t < min)
            min = t;
    }
    fprintf(q, "%d %d", min, max);
    return 0;
}
