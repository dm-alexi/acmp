#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pal(char *s)
{
    for (int i = 0, n = strlen(s); i < n / 2; ++i)
        if (s[i] != s[n - 1 - i])
            return 0;
    return 1;
}

char *conv(int n, int t, char s[])
{
    int i;
    for (i = 0; n > 0; ++i, n /= t)
    {
        int k = n % t;
        s[i] = k + (k < 10 ? '0' : 'A' - 10);
    }
    s[i] = '\0';
    return s;
}

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, a[34], c = 0;
    char s[33];

    fscanf(f, "%d", &n);
    for (int i = 2; i < 37; ++i)
        if (pal(conv(n, i, s)))
            a[c++] = i;
    fprintf(q, !c ? "none" : c == 1 ? "unique\n" : "multiple\n");
    for (int i = 0; i < c; ++i)
        fprintf(q, "%d ", a[i]);
    return 0;
}
