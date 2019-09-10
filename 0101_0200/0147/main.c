#include <stdio.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, a, b = 0;

    fscanf(f, "%d", &n);
    if (n)
        for(--n, a = 0, b = 1; n; --n)
            b += a, a = b - a;
    fprintf(q, "%d", b);
    return 0;
}
