#include <stdio.h>

int main()
{
    int n, k;
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");

    fscanf(f, "%d%d", &n, &k);
    fprintf(q,"%d %d", k - 1, n - 1);
    return 0;
}
