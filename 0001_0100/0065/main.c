#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int diff(char *s, char *t, int n)
{
    int k = 0;

    while (--n >= 0)
        if (s[n] ^ t[n])
            ++k;
    return k;
}

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, k, *p, m, ind = 0;
    char s[30718], *t;

    fscanf(f, "%s%d", s, &n);
    m = k = strlen(s);
    t = (char*)malloc(k + 1);
    p = (int*)malloc(sizeof(int) * n);
    for (int i = 1; i <= n; ++i)
    {
        fscanf(f, "%s", t);
        int d = diff(s, t, k);
        if (d <= m)
        {
            if (d < m)
                m = d, ind = 0;
            p[ind++] = i;
        }
    }
    fprintf(q, "%d\n", ind);
    for (int i = 0; i < ind; ++i)
        fprintf(q, "%d ", p[i]);
    return 0;
}
