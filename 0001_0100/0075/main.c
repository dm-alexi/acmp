#include <stdio.h>

#define N 276

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int s[N] = {0}, n, i;

    fscanf(f, "%d", &n);
    s[0] = 45;
    while (--n)
    {
        for (i = 0; i < N; ++i)
            s[i] *= 45;
        for (i = 0; i < N; ++i)
            if (s[i] > 999999)
                s[i + 1] += s[i] / 1000000, s[i] %= 1000000;
    }
    for (i = N - 1; s[i] == 0; --i);
    fprintf(q, "%d", s[i]);
    while (--i >= 0)
        fprintf(q, "%06d", s[i]);
    return 0;
}
