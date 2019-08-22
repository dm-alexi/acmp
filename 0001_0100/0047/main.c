#include <stdio.h>

int sum(int a)
{
    int k = 0;
    while (a)
        k += a % 10, a /= 10;
    return k;
}

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, d, s;

    fscanf(f, "%d", &n);
    d = n;
    s = sum(d);
    for (int i = 2; i <= n/2; ++i)
        if (!(n % i))
        {
            int t = sum(i);
            if (t > s || (t == s && i < d))
                d = i, s = t;
        }
    fprintf(q, "%d", d);
    return 0;
}
