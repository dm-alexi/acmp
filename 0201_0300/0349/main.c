#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n;
    char *s = "Absent", *p;
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");

    fscanf(f, "%d%d", &m, &n);
    p = (char*)malloc(n + 1);
    for (int i = 0; i <= n; ++i)
        p[i] = 1;
    for (int i = 3; i * i <= n; i += 2)
        if (p[i])
            for (int j = i * i; j <= n; j += 2 * i)
                p[j] = 0;
    if (m == 2)
        fprintf(q, "2\n"), s = "";
    for (int i = m % 2 ? m : m + 1; i <= n ; i += 2)
        if (p[i])
            fprintf(q, "%d\n", i), s = "";
    fprintf(q, s);
    return 0;
}

