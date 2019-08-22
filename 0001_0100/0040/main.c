#include <stdio.h>

#define N 51

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, i;
    int s[N] = {0};

    fscanf(f, "%d", &n);
    s[0] = 2;
    while (--n)
    {
        for (i = 0; i < N; ++i)
            s[i] *= 2;
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
