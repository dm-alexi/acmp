#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int m, n, i, *p, l;

    fscanf(f, "%d%d", &n, &m);
    p = (int*)calloc(n, sizeof(int));
    m *= 2;
    while (m--)
        fscanf(f, "%d", &l), ++p[l - 1];
    for (i = 0; i < n;++i)
        fprintf(q, "%d ", p[i]);
    return 0;
}
