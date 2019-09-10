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
    int i, d, k, a[N] = {0};
    char s[102];

    fscanf(f, "%s%d", s, &k);
    longread(s, a);
    for (i = 0; i < N - 1 && !a[i]; ++i);
    d = a[i];
    if (d < k && i < N - 1)
        d = d * 100000 + a[++i];
    fprintf(q, "%d", d / k);
    while (++i < N)
    {
        d = d % k * 100000 + a[i];
        fprintf(q, "%05d", d / k);
    }
    return 0;
}
