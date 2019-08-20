#include <stdio.h>

int derange(int n)
{
    return !n ? 1 : n == 1 ? 0 : n * derange(n - 1) + (n % 2 ? -1 : 1);
}

int c(int n, int k)
{
    int a = 1, b = 1;
    while (n > k)
        a *= n, b *= n - k, --n;
    return a / b;
}

int main()
{
    int n, k;
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    fscanf(f, "%d%d", &n, &k);
    fprintf(q, "%d", c(n, k) * derange(n - k));
    return 0;
}
