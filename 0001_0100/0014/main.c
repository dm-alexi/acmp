#include <stdio.h>

int main()
{
    int a, b, n, m;
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");

    fscanf(f, "%d%d", &a, &b);
    n = a, m = b;
    while (n && m)
        if (n > m)
            n %= m;
        else m %= n;
    fprintf(q, "%d", a / (n + m) * b);
    return 0;
}
