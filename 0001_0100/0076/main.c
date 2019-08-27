#include <stdio.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, m = 0, s[1440] = {0};

    fscanf(f, "%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int a, b, c, d;
        fscanf(f, "%d:%d %d:%d", &a, &b, &c, &d);
        for (int j = a * 60 + b; j <= c * 60 + d; ++j)
            ++s[j];
    }
    for (int i = 0; i < 1440; ++i)
        if (s[i] > m)
            m = s[i];
    fprintf(q, "%d", m);
    return 0;
}
