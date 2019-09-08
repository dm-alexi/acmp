#include <stdio.h>
#include <string.h>

#define N 112

void longread(char *s, int *a)
{
    int n = strlen(s), j = N - 1 - (n - 1) / 9;
    for (int i = 0; i < n; ++i)
    {
        a[j] = a[j] * 10 + s[i] - '0';
        if (!((n - 1 - i) % 9))
            ++j;
    }
}

int longcmp(int *a, int *b)
{
    for (int i = 0; i < N; ++i)
        if (a[i] > b[i])
            return 1;
        else if (a[i] < b[i])
            return -1;
    return 0;
}

int *longsub(int *a, int *b)
{
    for (int i = N - 1; i >= 0; --i)
    {
        a[i] -= b[i];
        if (a[i] < 0)
            a[i] += 1000000000, --a[i - 1];
    }
    return a;
}

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int a[N] = {0}, b[N] = {0}, i, sign, *res;
    char s[1002];

    fscanf(f, "%s", s);
    longread(s, a);
    fscanf(f, "%s", s);
    longread(s, b);
    sign = longcmp(a, b);
    if (!sign)
    {
        fprintf(q, "0");
        return 0;
    }
    else res = sign == 1 ? longsub(a, b) : longsub(b, a);
    for (i = 0; i < N - 1 && !res[i]; ++i);
    fprintf(q, sign == 1 ? "%d" : "-%d", res[i]);
    while (++i < N)
        fprintf(q, "%09d", res[i]);
    return 0;
}
