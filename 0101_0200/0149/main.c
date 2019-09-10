#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int *p, n;

    fscanf(f, "%d", &n);
    p = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)
        fscanf(f, "%d", p + i);
    while (--n >= 0)
        fprintf(q, "%d ", p[n]);
    return 0;
}
