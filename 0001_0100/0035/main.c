#include <stdio.h>

int main()
{
    int m, n, k;
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");

    fscanf(f, "%d", &k);
    while(k--)
    {
        fscanf(f, "%d%d", &n, &m);
        fprintf(q, "%d\n", 19 * m + (n + 239) * (n + 366) / 2);
    }
    return 0;
}
