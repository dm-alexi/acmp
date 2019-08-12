#include <stdio.h>

int main()
{
    int n, i, odd = 0, b[100];

    FILE *f = fopen("input.txt", "r");
    fscanf(f, "%d\n", &n);
    for(i = 0; i < n; ++i)
        fscanf(f, "%d ", b + i);
    fclose(f);

    f = fopen("output.txt", "w");
    for(i = 0; i < n; ++i)
        if(b[i]%2)
            fprintf(f, "%d ", b[i]), ++odd;
    putc('\n', f);
    for(i = 0; i < n; ++i)
        if(!(b[i]%2))
            fprintf(f, "%d ", b[i]);
    putc('\n', f);
    fprintf(f, 2 * odd > n ? "NO" : "YES");

    return 0;
}
