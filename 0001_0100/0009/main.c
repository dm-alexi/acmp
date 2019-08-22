#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, *p, i, mini = 0, maxi = 0, sum = 0, mult = 1;

    fscanf(f, "%d", &n);
    p = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; ++i)
    {
        fscanf(f, "%d", p + i);
        if(p[i] < p[mini])
            mini = i;
        if(p[i] > p[maxi])
            maxi = i;
        if(p[i] > 0)
            sum += p[i];
    }
    if (mini > maxi)
        n = mini, mini = maxi, maxi = n;
    for (i = mini + 1; i < maxi; ++i)
        mult *= p[i];
    fprintf(q,"%d %d", sum, mult);
    return 0;
}
