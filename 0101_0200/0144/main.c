#include <stdio.h>
#include <string.h>

#define N 21

void longread(char *s, int *a)
{
    int n = strlen(s), j = N - 1 - (n - 1) / 5;
    for (int i = 0; i < n; ++i)
    {
        a[j] = a[j] * 10 + s[i] - '0';
        if (!((n - 1 - i) % 5))
            ++j;
    }
}

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int a[N] = {0}, b, i;
    char s[101];

    fscanf(f, "%s%d", s, &b);
    longread(s, a);
    for (i = 0; i < N; ++i)
        a[i] *= b;
    for (i = N - 1; i >=0; --i)
        if (a[i] > 100000)
            a[i - 1] += a[i] / 100000, a[i] %= 100000;
    for (i = 0; i < N - 1 && !a[i]; ++i);
    fprintf(q, "%d", a[i]);
    while (++i < N)
        fprintf(q, "%05d", a[i]);
    return 0;
}
