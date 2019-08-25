#include <stdio.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, k, i, m = 1, s = 0;

    fscanf(f, "%d%d", &n, &k);
    while (n)
    {
        i = n % k;
        s += i;
        m *= i;
        n /= k;
    }
    fprintf(q, "%d", m - s);
    return 0;
}
