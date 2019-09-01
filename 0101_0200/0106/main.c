#include <stdio.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, a = 0, b;

    fscanf(f, "%d", &n);
    for (int i = 0; i < n; ++i)
    {
        fscanf(f, "%d", &b);
        a += b;
    }
    fprintf(q, "%d", a < n - a ? a : n - a);
    return 0;
}
