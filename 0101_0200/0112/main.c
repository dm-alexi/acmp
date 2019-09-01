#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countinv(int *p, int n)
{
    int r = 0, *a, *b;

    if (n <= 1)
        return 0;
    a = (int*)malloc(sizeof(int) * (n / 2));
    b = (int*)malloc(sizeof(int) * (n - n / 2));
    memcpy(a, p, sizeof(int) * (n / 2));
    memcpy(b, p + n / 2, sizeof(int) * (n - n / 2));
    r += countinv(a, n / 2) + countinv(b, n - n / 2);
    for (int i = 0, j = 0; i < n / 2 || j < n - n / 2;)
        if (j == n - n / 2 || (i < n / 2 && a[i] < b[j]))
            p[i + j] = a[i], ++i;
        else p[i + j] = b[j], ++j, r += n / 2 - i;
    free(a);
    free(b);
    return r;
}

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int k, n, m = 0, *p;

    fscanf(f, "%d%d", &n, &k);
    p = (int*)malloc(sizeof(int) * n);
    while (k--)
    {
        for (int i = 0; i < n; ++i)
            fscanf(f, "%d", p + i);
        m += countinv(p, n);
    }
    fprintf(q, "%d", m);
    return 0;
}
