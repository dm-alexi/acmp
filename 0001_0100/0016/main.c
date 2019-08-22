#include <stdio.h>

int layer(int n, int k)
{
    if (n > k * (k + 1) / 2)
        return 0;
    if (n < 3 || n == k * (k + 1) / 2)
        return 1;
    if (k > n)
        k = n;
    int d = 0;
    for (; k >= n - k * (k + 1) / 2; --k)
        d += layer(n - k, k - 1);
    return d;
}

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n;

    fscanf(f, "%d", &n);
    fprintf(q, "%d", layer(n, n));
    return 0;
}
