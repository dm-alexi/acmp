#include <stdio.h>

int main()
{
    int a, b, c, d;

    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    fscanf(f, "%d%d%d%d", &a, &b, &c, &d);
    for (long long i = -100; i <= 100; ++i)
        if (a * i * i * i + b * i * i + c * i + d == 0)
            fprintf(q,"%I64d ", i);
    return 0;
}
