#include <stdio.h>

int gcd(int m, int n)
{
    while (n && m)
        if (n > m)
            n %= m;
        else m %= n;
    return n + m;
}

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, m, k;

    fscanf(f, "%d/%d", &n, &m);
    while ((k = gcd(n, m)) > 1)
        n /= k, m /= k;
    fprintf(q, "%d", n / m);
    if (n %= m)
    {
        putc('.', q);
        int a = 0, b = 0, c = m;
        while (c % 2 == 0)
            ++a, c /= 2;
        while (c % 5 == 0)
            ++b, c /= 5;
        if (a < b)
            a = b;
        while (a--)
            fprintf(q, "%d", (n = (n % m) * 10) / m);
        if (c != 1)
        {
            fprintf(q, "(");
            int t = n;
            fprintf(q, "%d", n * 10 / m);
            while((n = (n * 10) % m) != t)
                fprintf(q, "%d", n * 10 / m);
            fprintf(q, ")");
        }
    }
    return 0;
}
