#include <stdio.h>
#include <string.h>

#define N 12

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

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int a[N] = {0}, b[N] = {0}, i;
    char s[102];

    fscanf(f, "%s", s);
    longread(s, a);
    fscanf(f, "%s", s);
    longread(s, b);
    for (i = N - 1; i >= 0; --i)
    {
        a[i] += b[i];
        if (a[i] > 999999999)
            a[i] %= 1000000000, ++a[i - 1];
    }
    for (i = 0; i < N - 1 && !a[i]; ++i);
    fprintf(q, "%d", a[i]);
    while (++i < N)
        fprintf(q, "%09d", a[i]);
    return 0;
}
