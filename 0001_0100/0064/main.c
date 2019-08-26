#include <stdio.h>

void sadd(char *s, int n, int *k)
{
    char t[9];
    int i = -1;

    while (n)
        t[++i] = n % 10 + '0', n /= 10;
    while (i >= 0)
        s[(*k)++] = t[i--];
}

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, i, k = 1;
    char p[20222], s[10004] = "2";

    for (i = 3; i < 20222; i += 2)
        p[i] = 1;
    for (i = 3; i * i < 20222; i += 2)
        if (p[i])
        {
            sadd(s, i, &k);
            for (int j = i * i; j < 20222; j += 2 * i)
                p[j] = 0;
        }
    for (; i < 20222; i += 2)
        if (p[i])
            sadd(s, i, &k);
    fscanf(f, "%d", &n);
    while (n--)
    {
        fscanf(f, "%d", &k);
        putc(s[k - 1], q);
    }
    return 0;
}
