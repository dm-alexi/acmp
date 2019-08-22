#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int m = 0, n;
    char *p;

    fscanf(f, "%d", &n);
    p = (char*)malloc(2 * n);
    for (int i = 0; i < 2 * n; ++i)
        p[i] = 1;
    for (int i = 3; i * i < 2 * n; i += 2)
        if (p[i])
            for (int j = i * i; j < 2 * n; j += 2 * i)
                p[j] = 0;
    for (int i = n % 2 ? n + 2 : n + 1; i < 2 * n ; i += 2)
        m += p[i];
    fprintf(q, "%d", m);
    return 0;
}

